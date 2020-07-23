
#include "OpenThread.h"

#include <Arduino.h>

#include <openthread/config.h>
#include <openthread/commissioner.h>
#include <openthread/icmp6.h>
#include <openthread/joiner.h>
#include <openthread/link.h>
#if OPENTHREAD_CONFIG_ENABLE_TIME_SYNC
#include <openthread/network_time.h>

#include <openthread/dns.h>

#if OPENTHREAD_FTD
#include <openthread/dataset_ftd.h>
#include <openthread/thread_ftd.h>
#endif

#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
#include <openthread/border_router.h>
#endif
#if OPENTHREAD_CONFIG_SERVICE_ENABLE
#include <openthread/server.h>
#endif
#endif

#include <openthread/heap.h>

extern "C" {
#include <openthread/openthread-freertos.h>
}

otError OTCoap::_request(otCoapCode coapCode, const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  otError       error   = OT_ERROR_NONE;
  otMessage *   message = NULL;
  otMessageInfo messageInfo;

  message = otCoapNewMessage(otrGetInstance(), NULL);
  VerifyOrExit(message != NULL, error = OT_ERROR_NO_BUFS);

  otCoapMessageInit(message, coapType, coapCode);
  otCoapMessageGenerateToken(message, 2);

  if(url) {
    error = otCoapMessageAppendUriPathOptions(message, url);
  }

  if(data && datalen > 0) {
    error = otCoapMessageSetPayloadMarker(message);
    error = otMessageAppend(message, data, datalen);
  }

  memset(&messageInfo, 0, sizeof(messageInfo));
  messageInfo.mPeerAddr = *dest;
  messageInfo.mPeerPort = OT_DEFAULT_COAP_PORT;
  error = otCoapSendRequestWithParameters(otrGetInstance(), message, &messageInfo, handler, context,
                                                GetRequestTxParameters());

exit:
  if ((error != OT_ERROR_NONE) && (message != NULL))
  {
    otMessageFree(message);
  }
  return error;
}

otError OTCoap::request_get(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_GET, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoap::request_post(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_POST, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoap::request_put(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_PUT, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoap::request_delete(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_DELETE, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoap::start()
{
  return otCoapStart(otrGetInstance(), OT_DEFAULT_COAP_PORT);
}

otError OTCoap::stop()
{
  return otCoapStop(otrGetInstance());
}

otError OTCoap::resource(const char* url)
{
  mResource.mUriPath = url;
  mResource.mContext = this;
  mResource.mHandler = OTCoap::HandleRequest;

  return otCoapAddResource(otrGetInstance(), &mResource);
}

void OTCoap::parameters_request_default()
{
  mUseDefaultRequestTxParameters = true;
}

void OTCoap::parameters_request(uint32_t acktimeout, uint8_t numerator, uint8_t denominator, uint8_t retransmit)
{
  mRequestTxParameters.mAckTimeout = acktimeout;
  mRequestTxParameters.mAckRandomFactorNumerator = numerator;
  mRequestTxParameters.mAckRandomFactorDenominator = denominator;
  mRequestTxParameters.mMaxRetransmit = retransmit ;
  mUseDefaultRequestTxParameters = false;
}

void OTCoap::parameters_response_default()
{
  mUseDefaultResponseTxParameters = true;
}

void OTCoap::parameters_response(uint32_t acktimeout, uint8_t numerator, uint8_t denominator, uint8_t retransmit)
{
  mResponseTxParameters.mAckTimeout = acktimeout;
  mResponseTxParameters.mAckRandomFactorNumerator = numerator;
  mResponseTxParameters.mAckRandomFactorDenominator = denominator;
  mResponseTxParameters.mMaxRetransmit = retransmit ;
  mUseDefaultResponseTxParameters = false;
}

void OTCoap::set(uint8_t* data, size_t datalen)
{
  memcpy(&mResourceContent, data, datalen);
}


void OTCoap::HandleRequest(void *aContext, otMessage *aMessage, const otMessageInfo *aMessageInfo)
{
  static_cast<OTCoap*>(aContext)->HandleRequest(aMessage, aMessageInfo);
}

void OTCoap::HandleRequest(otMessage *aMessage, const otMessageInfo *aMessageInfo)
{
  otError  error       = OT_ERROR_NONE;
  otMessage *responseMessage = NULL;
  otCoapCode responseCode  = OT_COAP_CODE_EMPTY;

  if (otCoapMessageGetType(aMessage) == OT_COAP_TYPE_CONFIRMABLE ||
      otCoapMessageGetCode(aMessage) == OT_COAP_CODE_GET) {
    if (otCoapMessageGetCode(aMessage) == OT_COAP_CODE_GET) {
      responseCode = OT_COAP_CODE_CONTENT;
    }
    else {
      responseCode = OT_COAP_CODE_VALID;
    }

    responseMessage = otCoapNewMessage(otrGetInstance(), NULL);
    VerifyOrExit(responseMessage != NULL, error = OT_ERROR_NO_BUFS);

    SuccessOrExit(
      error = otCoapMessageInitResponse(responseMessage, aMessage, OT_COAP_TYPE_ACKNOWLEDGMENT, responseCode));

    if (responseCode == OT_COAP_CODE_CONTENT) {
      SuccessOrExit(error = otCoapMessageSetPayloadMarker(responseMessage));
      SuccessOrExit(error = otMessageAppend(responseMessage, mResourceContent, mResourceContentLength));
    }
    SuccessOrExit(error = otCoapSendResponseWithParameters(otrGetInstance(), responseMessage, aMessageInfo,
                          GetResponseTxParameters()));
  }

exit:

  if (error != OT_ERROR_NONE)
  {
    if (responseMessage != NULL)
    {
      otMessageFree(responseMessage);
    }
  }
}






