
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


otError OTCoapSecure::_request(otCoapCode coapCode, const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
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
  error = otCoapSecureSendRequest(otrGetInstance(), message, handler, context);

exit:
  if ((error != OT_ERROR_NONE) && (message != NULL))
  {
    otMessageFree(message);
  }
  return error;
}



otError OTCoapSecure::request_get(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_GET, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoapSecure::request_post(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_POST, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoapSecure::request_put(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_PUT, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoapSecure::request_delete(const otIp6Address* dest, char const* url, otCoapType coapType, uint8_t* data, uint16_t datalen, otCoapResponseHandler handler, void* context)
{
  return _request(OT_COAP_CODE_DELETE, dest, url, coapType, data, datalen, handler, context);
}

otError OTCoapSecure::start()
{
  return otCoapSecureStart(otrGetInstance(), OT_DEFAULT_COAP_PORT);
}

void OTCoapSecure::stop()
{
  otCoapSecureStop(otrGetInstance());
}

otError OTCoapSecure::connect(const otIp6Address* addr, uint16_t port, otHandleCoapSecureClientConnect handler, void* context)
{
  otSockAddr sockaddr;
  sockaddr.mAddress = *addr;
  sockaddr.mPort = port;
  return otCoapSecureConnect(otrGetInstance(), &sockaddr, handler, context);
}

void OTCoapSecure::disconnect()
{
  otCoapSecureDisconnect(otrGetInstance());
}

otError OTCoapSecure::resource(const char* url, otCoapRequestHandler handler, void* context)
{
  mResource.mUriPath = url;
  mResource.mContext = context;
  mResource.mHandler = handler;

  return otCoapSecureAddResource(otrGetInstance(), &mResource);
}

