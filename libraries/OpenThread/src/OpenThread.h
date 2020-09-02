/*
  Copyright (c) 2019 Tokita, Hiroshi  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SOCKETS_OPENTHREAD_H
#define SOCKETS_OPENTHREAD_H

#include "IPAddress.h"
#include "Print.h"

#include <initializer_list>

#include <nrf52840.h>

extern "C" {
#include <openthread-core-config.h>

#include <openthread/config.h>
#include <openthread/backbone_router.h>
#include <openthread/backbone_router_ftd.h>
#include <openthread/border_agent.h>
#include <openthread/border_router.h>
#include <openthread/instance.h>
#include <openthread/ip6.h>
#include <openthread/link.h>
#include <openthread/message.h>
#include <openthread/thread.h>
#include <openthread/dataset.h>
#include <openthread/coap.h>
#include <openthread/coap_secure.h>
#include <openthread/thread_ftd.h>
#include <openthread/dataset_ftd.h>
#include <openthread/diag.h>
#include <openthread/commissioner.h>
#include <openthread/joiner.h>
#include <openthread/netdata.h>
#include <openthread/server.h>
#include <openthread/platform/radio.h>

#include <openthread/icmp6.h>
#include <openthread/dns.h>
#include <openthread/dns.h>
#include <openthread/jam_detection.h>
#include <openthread/link_raw.h>
#include <openthread/netdiag.h>
#include <openthread/network_time.h>
#include <openthread/sntp.h>
#include <openthread/udp.h>
#include <openthread/tasklet.h>
#include <openthread/channel_manager.h>
#include <openthread/channel_monitor.h>
#include <openthread/child_supervision.h>
#include <openthread/entropy.h>
#include <openthread/random_crypto.h>
#include <openthread/cli.h>
#include <openthread/ncp.h>
#include <openthread/diag.h>
#include <openthread/platform/diag.h>
#include <openthread/openthread-freertos.h>

#include <openthread/platform/entropy.h>
#include <openthread/platform/udp.h>
#include <openthread/crypto.h>
#include <openthread/random_crypto.h>
#include <openthread/random_noncrypto.h>
#include <openthread/entropy.h>
#include <openthread/logging.h>

#include <mbedtls/entropy.h>
#include <openthread/openthread-freertos.h>
}

#include "otcmd.h"

#define SuccessOrExit(aStatus) \
    do                         \
    {                          \
        if ((aStatus) != 0)    \
        {                      \
            goto exit;         \
        }                      \
    } while (false)

#define VerifyOrExit(aCondition, ...) \
    do                                \
    {                                 \
        if (!(aCondition))            \
        {                             \
            __VA_ARGS__;              \
            goto exit;                \
        }                             \
    } while (false)

#define OT_API_CALL_RET(ty, ...) \
    { ty ret; \
    do                       \
    {                        \
        otrLock();           \
        ret = __VA_ARGS__;   \
        otrUnlock();         \
        otrTaskNotifyGive(); \
    } while (0);             \
    return ret; }


#define OT_CALL_FUNC0(cls, fn) ot##cls##fn (otrGetInstance())
#define OT_CALL_FUNC1(cls, fn) ot##cls##fn (otrGetInstance(), a1)
#define OT_CALL_FUNC2(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2)
#define OT_CALL_FUNC3(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2, a3)
#define OT_CALL_FUNC4(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2, a3, a4)
#define OT_CALL_FUNC5(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2, a3, a4, a5)
#define OT_CALL_FUNC6(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2, a3, a4, a5, a6)
#define OT_CALL_FUNC7(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2, a3, a4, a5, a6, a7)
#define OT_CALL_FUNC8(cls, fn) ot##cls##fn (otrGetInstance(), a1, a2, a3, a4, a5, a6, a7, a8)

#define OT_DECL_ARGS0()
#define OT_DECL_ARGS1(T1) T1 a1
#define OT_DECL_ARGS2(T1, T2) T1 a1, T2 a2
#define OT_DECL_ARGS3(T1, T2, T3) T1 a1, T2 a2, T3 a3
#define OT_DECL_ARGS4(T1, T2, T3, T4) T1 a1, T2 a2, T3 a3, T4 a4
#define OT_DECL_ARGS5(T1, T2, T3, T4, T5) T1 a1, T2 a2, T3 a3, T4 a4, T5 a5
#define OT_DECL_ARGS6(T1, T2, T3, T4, T5, T6) T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6
#define OT_DECL_ARGS7(T1, T2, T3, T4, T5, T6, T7) T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7
#define OT_DECL_ARGS8(T1, T2, T3, T4, T5, T6, T7, T8) T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8

#define OT_IS_DECL(ty, na, cat, n2)  ty na ();
#define OT_GETTER_DECL(ty, na, cat, n2)  ty na ();
#define OT_SETTER_DECL(ty, na, cat, n2)  otError na (ty arg);
#define OT_V_SETTER_DECL(ty, na, cat, n2)  void na (ty arg);

#define OT_SETGET_DECL(ty, na, cat, n2)  \
  OT_SETTER_DECL(ty, na, cat, n2); \
  OT_GETTER_DECL(ty, na, cat, n2) \

#define OT_SET_IS_DECL(ty, na, cat, n2)  \
  OT_SETTER_DECL(ty, na, cat, n2); \
  OT_IS_DECL(ty, na, cat, n2) \

#define OT_V_SETGET_DECL(ty, na, cat, n2)  \
  OT_V_SETTER_DECL(ty, na, cat, n2); \
  OT_GETTER_DECL(ty, na, cat, n2) \

#define OT_V_SET_IS_DECL(ty, na, cat, n2)  \
  OT_V_SETTER_DECL(ty, na, cat, n2); \
  OT_IS_DECL(ty, na, cat, n2) \

#define OT_V_FUNC_0_DECL(na, cat, n2) \
  void na()

#define OT_FUNC_0_DECL(ty, na, cat, n2) \
  ty na()

#define OT_V_FUNC_1_DECL(na, cat, n2, t1) \
  void na(t1)

#define OT_FUNC_1_DECL(ty, na, cat, n2, t1) \
  ty na(t1)

#define OT_FUNC_2_DECL(ty, na, cat, n2, t1, t2) \
  ty na(t1, t2)

#define OT_FUNC_3_DECL(ty, na, cat, n2, t1, t2, t3) \
  ty na(t1, t2, t3)

#define OT_FUNC_4_DECL(ty, na, cat, n2, t1, t2, t3, t4) \
  ty na(t1, t2, t3, t4)

#define OTCLS(cls) OpenThread ## cls ## Class
#define OT_DECL__FUNC(n, cls, rettype, fn, ...) \
rettype OpenThreadClass::  OTCLS(cls)  ::  fn (OT_DECL_ARGS ## n(__VA_ARGS__)) \
{ \
  rettype ret = OT_CALL_FUNC ## n(cls, fn); \
  return ret; \
}

#define OT_DECL_VFUNC(n, cls, rettype, fn, ...) \
rettype OpenThreadClass::  OTCLS(cls)  ::  fn (OT_DECL_ARGS ## n(__VA_ARGS__)) \
{ \
  OT_CALL_FUNC ## n(cls, fn); \
}

template<typename T> class OTm8Buffer : public Printable {
public:
  OTm8Buffer() : value(&default_value) { }
  OTm8Buffer(const T* v) : value(v) { }
  OTm8Buffer(const uint8_t* v) : value( reinterpret_cast<const T*>(v) ) { }
  size_t printTo(Print& p) const {
    size_t n=0;
    for(unsigned int i=0; i<sizeof(T); i++) {
      uint8_t byte = value->m8[i];
      if(byte <= 0xF) n += p.print('0');
      n += p.print(byte, HEX);
    }
    return n;
  }
  operator const uint8_t*() { return value->m8; }
  operator const T*() const { return value; }
  operator T*() { return const_cast<T*>(value); }
private:
  static T default_value;
  const T* value;
};

template<typename T> class OTm8String : public Printable {
public:
  OTm8String(const T* v) : value(v) { }
  OTm8String(const char* v) : value( reinterpret_cast<const T*>(v) ) { }
  size_t printTo(Print& p) const {
    return p.print(reinterpret_cast<const char*>(value->m8));
  }
  operator const T*() const { return value; }
  operator T*() { return const_cast<T*>(value); }
  operator const char*() { return reinterpret_cast<const char*>(value->m8); }
private:
  const T* value;
};

typedef class OTm8Buffer<otExtAddress> OTExtAddress;
typedef class OTm8Buffer<otExtendedPanId> OTExtendedPanId;
typedef class OTm8Buffer<otMasterKey> OTMasterKey;
typedef class OTm8String<otNetworkName> OTNetworkName;
typedef class OTm8Buffer<otPskc> OTPskc;

class OTLinkModeConfig : public Printable{
public:
  OTLinkModeConfig(const otLinkModeConfig v) : conf(v) { }
  size_t printTo(Print& p) const {
    size_t n = 0;
    if (conf.mRxOnWhenIdle)       n += p.print("r");
    if (conf.mSecureDataRequests) n += p.print("s");
    if (conf.mDeviceType)         n += p.print("d");
    if (conf.mNetworkData)        n += p.print("n");
    return n;
  }

  operator const otLinkModeConfig() { return conf; }
private:
  otLinkModeConfig conf;
};

class OTMacCounters : public Printable {
public:
  OTMacCounters(const otMacCounters* v) : value(v) { }

  uint32_t TxTotal() const { return value->mTxTotal; }
  uint32_t TxUnicast() const { return value->mTxUnicast; }
  uint32_t TxBroadcast() const { return value->mTxBroadcast; }
  uint32_t TxAckRequested() const { return value->mTxAckRequested; }
  uint32_t TxAcked() const { return value->mTxAcked; }
  uint32_t TxNoAckRequested() const { return value->mTxNoAckRequested; }
  uint32_t TxData() const { return value->mTxData; }
  uint32_t TxDataPoll() const { return value->mTxDataPoll; }
  uint32_t TxBeacon() const { return value->mTxBeacon; }
  uint32_t TxBeaconRequest() const { return value->mTxBeaconRequest; }
  uint32_t TxOther() const { return value->mTxOther; }
  uint32_t TxRetry() const { return value->mTxRetry; }
  uint32_t TxErrCca() const { return value->mTxErrCca; }
  uint32_t TxErrAbort() const { return value->mTxErrAbort; }
  uint32_t TxErrBusyChannel() const { return value->mTxErrBusyChannel; }
  uint32_t RxTotal() const { return value->mRxTotal; }
  uint32_t RxUnicast() const { return value->mRxUnicast; }
  uint32_t RxBroadcast() const { return value->mRxBroadcast; }
  uint32_t RxData() const { return value->mRxData; }
  uint32_t RxDataPoll() const { return value->mRxDataPoll; }
  uint32_t RxBeacon() const { return value->mRxBeacon; }
  uint32_t RxBeaconRequest() const { return value->mRxBeaconRequest; }
  uint32_t RxOther() const { return value->mRxOther; }
  uint32_t RxAddressFiltered() const { return value->mRxAddressFiltered; }
  uint32_t RxDestAddrFiltered() const { return value->mRxDestAddrFiltered; }
  uint32_t RxDuplicated() const { return value->mRxDuplicated; }
  uint32_t RxErrNoFrame() const { return value->mRxErrNoFrame; }
  uint32_t RxErrUnknownNeighbor() const { return value->mRxErrUnknownNeighbor; }
  uint32_t RxErrInvalidSrcAddr() const { return value->mRxErrInvalidSrcAddr; }
  uint32_t RxErrSec() const { return value->mRxErrSec; }
  uint32_t RxErrFcs() const { return value->mRxErrFcs; }
  uint32_t RxErrOther() const { return value->mRxErrOther; }
  operator const otMacCounters*() const { return value; }
  size_t printTo(Print& p) const;
private:
  const otMacCounters* value;
};

class OTErr: public Printable {
public:
  OTErr(const otError e=OT_ERROR_NONE) : err(e) { }
  size_t printTo(Print& p) const {
    const char* msg = otThreadErrorToString(err);
    if(msg) return p.print(msg);
    else return 0;
  }

  operator otError() { return err; }
private:
  otError err;
};

class OTChildIterator {
  otError error;
  uint16_t index;
  otChildInfo entry;

public:
  OTChildIterator() : index(0) {}
  bool end() { return error; }
  const otChildInfo* get() { return (error ? nullptr : &entry); }
  const otChildInfo* next();
};

class OTChildIpIterator {
  otError error;
  otChildIp6AddressIterator iter;
  otIp6Address entry;
  uint16_t index;

public:
  OTChildIpIterator(uint16_t i) : iter(OT_CHILD_IP6_ADDRESS_ITERATOR_INIT), index(i) {}
  bool end() { return error; }
  const otIp6Address* get() { return (error ? nullptr : &entry); }
  const otIp6Address* next();
};

class OTRouteIterator {
  otError error;
  otNetworkDataIterator iter;
  otExternalRouteConfig entry;

public:
  OTRouteIterator() : iter(OT_NETWORK_DATA_ITERATOR_INIT) {}
  bool end() { return error; }
  const otExternalRouteConfig* get() { return (error ? nullptr : &entry); }

  const otExternalRouteConfig* next();
};

class OTRouterIterator {
  otError error;
  uint16_t index;
  otRouterInfo entry;


public:
  OTRouterIterator() : index(0) {}
  bool end() { return error; }
  const otRouterInfo* get() { return (error ? nullptr : &entry); }

  const otRouterInfo* next();
};

class OTEidCacheIterator {
  otError error;
  otCacheEntryIterator iter;
  otCacheEntryInfo entry;

public:
  bool end() { return error; }
  const otCacheEntryInfo* get() { return (error ? nullptr : &entry); }
  const otCacheEntryInfo* next();
};

class OTNeighborIterator {
  otError error;
  otNeighborInfoIterator iter;
  otNeighborInfo entry;

public:
  OTNeighborIterator() : iter(OT_NEIGHBOR_INFO_ITERATOR_INIT) {}
  bool end() { return error; }
  const otNeighborInfo* get() { return (error ? nullptr : &entry); }

  const otNeighborInfo* next();
};

class OTPrefixIterator {
  otError error;
  otNetworkDataIterator iter;
  otBorderRouterConfig entry;

public:
  OTPrefixIterator() : iter(OT_NETWORK_DATA_ITERATOR_INIT) {}
  bool end() { return error; }
  const otBorderRouterConfig* get() { return (error ? nullptr : &entry); }
  const otBorderRouterConfig* next();
};

class OTMacfilterAddrIterator {
  otError error;
  otMacFilterIterator iter;
  otMacFilterEntry entry;

public:
  OTMacfilterAddrIterator() : iter(OT_MAC_FILTER_ITERATOR_INIT) {}
  bool end() { return error; }
  const otMacFilterEntry* get() { return (error ? nullptr : &entry); }
  const otMacFilterEntry* next();
};

class OTMacfilterRssIterator {
  otError error;
  otMacFilterIterator iter;
  otMacFilterEntry entry;

public:
  OTMacfilterRssIterator() : iter(OT_MAC_FILTER_ITERATOR_INIT) {}
  bool end() { return error; }
  const otMacFilterEntry* get() { return (error ? nullptr : &entry); }
  const otMacFilterEntry* next();
};

class OTMacfilterIterator {
  otError error;
  otMacFilterIterator iter;
  otMacFilterEntry entry;
  bool addr_end;

  void _next();
public:
  OTMacfilterIterator() : iter(OT_MAC_FILTER_ITERATOR_INIT) {}
  bool end() { return error; }
  const otMacFilterEntry* get() { return (error ? nullptr : &entry); }
  const otMacFilterEntry* next();
};

class OTIpaddrIterator {
  const otNetifAddress* addr;

public:
  OTIpaddrIterator();
  bool end() { return !addr; }
  const otNetifAddress* get() { return addr; }
  const otNetifAddress* next() { addr = addr->mNext; return addr; }
};

class OTIpmaddrIterator{
  const otNetifMulticastAddress* addr;

public:
  OTIpmaddrIterator();
  bool end() { return !addr; }
  const otNetifMulticastAddress* get() { return addr; }

  const otNetifMulticastAddress* next() { addr = addr->mNext; return addr; }
};

#if OPENTHREAD_CONFIG_COAP_API_ENABLE
class OTCoap {
  otCoapResource mResource;
  uint8_t mResourceContent[16];
  uint16_t mResourceContentLength;
  bool mUseDefaultRequestTxParameters;
  bool mUseDefaultResponseTxParameters;
  otCoapTxParameters mRequestTxParameters;
  otCoapTxParameters mResponseTxParameters;

  otError _request(otCoapCode, const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);

  const otCoapTxParameters *GetRequestTxParameters(void) const
  {
    return mUseDefaultRequestTxParameters ? NULL : &mRequestTxParameters;
  }

  const otCoapTxParameters *GetResponseTxParameters(void) const
  {
    return mUseDefaultResponseTxParameters ? NULL : &mResponseTxParameters;
  }

  static void HandleRequest(void*, otMessage*, const otMessageInfo*);
  void HandleRequest(otMessage*, const otMessageInfo*);

public:
#if OPENTHREAD_CONFIG_COAP_OBSERVE_API_ENABLE
  otError cancel();
  otError observe(const otIp6Addresss*, const char*, otCoapType);
#endif
  otError resource(char const*);
  void set(uint8_t*, size_t);
  otError start();
  otError stop();
  void parameters_request_default();
  void parameters_request(uint32_t acktimeout, uint8_t numerator, uint8_t denominator, uint8_t retransmit);
  void parameters_response_default();
  void parameters_response(uint32_t acktimeout, uint8_t numerator, uint8_t denominator, uint8_t retransmit);
  otError request_delete(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
  otError request_get(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
  otError request_post(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
  otError request_put(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
};
#endif // OPENTHREAD_CONFIG_COAP_API_ENABLE

#if OPENTHREAD_CONFIG_COAP_SECURE_API_ENABLE
class OTCoapSecure {
  otCoapResource mResource;
  otError _request(otCoapCode, const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
public:
  otError resource(char const*, otCoapRequestHandler, void*);
  otError start();
  void stop();
  otError connect(const otIp6Address*, uint16_t, otHandleCoapSecureClientConnect, void*);
  void disconnect();
  otError request_delete(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
  otError request_get(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
  otError request_post(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
  otError request_put(const otIp6Address*, char const*, otCoapType, uint8_t*, uint16_t, otCoapResponseHandler, void*);
#ifdef MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
  otError psk(const char*, const char*);
#endif // MBEDTLS_KEY_EXCHANGE_PSK_ENABLED
#ifdef MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
  void x509();
#endif
};
#endif // OPENTHREAD_CONFIG_COAP_SECURE_API_ENABLE

class OTDataset {
  otOperationalDataset mDataset;
public:
  otError commit_active();
  otError commit_pending();
  otError init_active();
#if OPENTHREAD_FTD
  otError init_new();
#endif
  otError init_pending();
  //TODO otError mgmtgetcommand_active(otOperationalDatasetComponents*);
  //TODO otError mgmtgetcommand_pending(otOperationalDatasetComponents*);
  //TODO otError mgmtsetcommand_active(const otOperationalDatasetComponents*);
  //TODO otError mgmtsetcommand_pending(const otOperationalDatasetComponents*);
  void clear();
  void channelmask(uint32_t);
  void channel(uint16_t);
  void delay(uint32_t);
  void extpanid(const otExtendedPanId*);
  void masterkey(const otMasterKey*);
  void meshlocalprefix(const otIp6Prefix*);
  void networkname(const char*);
  void panid(otPanId);
  void pendingtimestamp(uint64_t);
  void activetimestamp(uint64_t);
  void securitypolicy(uint16_t, uint32_t);
#if OPENTHREAD_FTD
  void pskc(const otPskc*);
  otError pskc_passphrase(char const*);
#endif
};

class OTUdp {
  otUdpSocket mSocket;
public:
  otError open(otUdpReceive, void*);
  otError close();
  otError bind(const otIp6Address*, uint16_t);
  otError connect(const otIp6Address*, uint16_t);
  otError _send(const otIp6Address*, uint16_t, const void*, uint16_t);
  otError send_text(const otIp6Address*, uint16_t, char const*);
  otError send_data(const otIp6Address*, uint16_t, uint8_t*, uint16_t);
  otError send_size(const otIp6Address*, uint16_t, uint16_t);
  otError send_text(const char*);
  otError send_data(uint8_t*, uint16_t);
  otError send_size(uint16_t);
};

class OpenThreadClass {
public:
  void init();
  int begin();
  int dump(Print& p);

  inline const char* VersionString() { return otGetVersionString(); }
  inline const char* RadioVersionString() { return otGetRadioVersionString(otrGetInstance()); }
  inline const char* otErrorToString(otError err) { return otThreadErrorToString(err); }
  inline otError SetStateChangedCallback(otStateChangedCallback cb, void* user) {
    return otSetStateChangedCallback(otrGetInstance(), cb, user);
  }
  inline void RemoveStateChangeCallback(otStateChangedCallback cb, void* user) {
    otRemoveStateChangeCallback(otrGetInstance(), cb, user);
  }

#include "OpenThread_APIs.inc"
#include "OpenThread_cmds.inc"

  OpenThreadBackboneRouterClass BackboneRouter;
  OpenThreadBorderAgentClass BorderAgent;
  OpenThreadBorderRouterClass BorderRouter;
  OpenThreadChannelManagerClass ChannelManager;
  OpenThreadChannelMonitorClass ChannelMonitor;
  OpenThreadChildSupervisionClass ChildSupervision;
  OpenThreadCliClass Cli;
  OpenThreadCoapClass Coap;
  OpenThreadCoapSecureClass CoapSecure;
  OpenThreadCommissionerClass Commissioner;
  OpenThreadCryptoClass Crypto;
  OpenThreadDatasetClass Dataset;
  OpenThreadDiagClass Diag;
  OpenThreadDnsClientClass DnsClient;
  OpenThreadEntropyClass Entropy;
  OpenThreadHeapClass Heap;
  OpenThreadIcmp6Class Icmp6;
  OpenThreadInstanceClass Instance;
  OpenThreadIp6Class Ip6;
  OpenThreadJamDetectionClass JamDetection;
  OpenThreadJoinerClass Joiner;
  OpenThreadLinkClass Link;
  OpenThreadLoggingClass Logging;
  OpenThreadMessageClass Message;
  OpenThreadNcpClass Ncp;
  OpenThreadNetDataClass NetData;
  OpenThreadNetworkTimeClass NetworkTime;
  OpenThreadPlatClass Plat;
  OpenThreadRandomCryptoClass RandomCrypto;
  OpenThreadRandomNonCryptoClass RandomNonCrypto;
  OpenThreadServerClass Server;
  OpenThreadSntpClientClass SntpClient;
  OpenThreadTaskletsClass Tasklets;
  OpenThreadThreadClass Thread;
  OpenThreadUdpClass Udp;
private:
};

extern OpenThreadClass OpenThread;

#endif
