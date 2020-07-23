
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

otError OTUdp::open(otUdpReceive handler, void* context)
{
  OT_API_CALL_RET(otError,
    otUdpOpen(otrGetInstance(), &mSocket, handler, context);
  );
}
otError OTUdp::close()
{
  OT_API_CALL_RET(otError,
    otUdpClose(&mSocket);
  );
}
otError OTUdp::bind(const otIp6Address* addr, uint16_t port)
{
  otSockAddr sockaddr;
  sockaddr.mAddress = *addr;
  sockaddr.mPort = port;

  OT_API_CALL_RET(otError,
    otUdpBind(&mSocket, &sockaddr);
  );
}

otError OTUdp::connect(const otIp6Address* addr, uint16_t port)
{
  otSockAddr sockaddr;
  sockaddr.mAddress = *addr;
  sockaddr.mPort = port;

  OT_API_CALL_RET(otError,
    otUdpConnect(&mSocket, &sockaddr);
  );
}

otError OTUdp::_send(const otIp6Address* addr, uint16_t port, const void* data, uint16_t size)
{
  otError error;
  otMessageInfo msginfo = { 0 };
  if(addr) {
    msginfo.mPeerAddr = *addr;
    msginfo.mPeerPort = port;
  }

  otMessage* msg = otUdpNewMessage(otrGetInstance(), NULL);
  if(msg == NULL) return OT_ERROR_NO_BUFS;

  if(data) {
    error = otMessageAppend(msg, data, size);
    if(error) goto exit;
  } else {
    uint8_t character = 0x30; // 0
    for (uint16_t index = 0; index < size; index++)
    {
      error = otMessageAppend(msg, &character, 1);
      if(error) goto exit;
      character++;

      switch (character)
      {
      case 0x3A:          // 9
        character = 0x41; // A
        break;
      case 0x5B:          // Z
        character = 0x61; // a
        break;
      case 0x7B:          // z
        character = 0x30; // 0
        break;
      }
    }
  }
  error = otUdpSend(&mSocket, msg, &msginfo);

exit:
  if (error != OT_ERROR_NONE && msg != NULL)
  {
    otMessageFree(msg);
  }
  return error;
}

otError OTUdp::send_text(const otIp6Address* addr, uint16_t port, const char* text)
{
  OT_API_CALL_RET(otError,
    _send(addr, port, text, static_cast<uint16_t>(strlen(text)));
  );
}

otError OTUdp::send_data(const otIp6Address* addr, uint16_t port, uint8_t* data, uint16_t size)
{
  OT_API_CALL_RET(otError,
    _send(addr, port, data, size);
  );
}

otError OTUdp::send_size(const otIp6Address* addr, uint16_t port, uint16_t autosize)
{
  OT_API_CALL_RET(otError,
    _send(addr, port, NULL, autosize);
  );
}

otError OTUdp::send_text(const char* text)
{
  OT_API_CALL_RET(otError,
    _send(NULL, 0, text, static_cast<uint16_t>(strlen(text)));
  );
}

otError OTUdp::send_data(uint8_t* data, uint16_t size)
{
  OT_API_CALL_RET(otError,
    _send(NULL, 0, data, size);
  );
}

otError OTUdp::send_size(uint16_t autosize)
{
  OT_API_CALL_RET(otError,
    _send(NULL, 0, NULL, autosize);
  );
}

