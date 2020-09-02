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

#include "OpenThread.h"

#include <Print.h>

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

#include "Arduino.h"

#define COMMISSION_BIT (1 << 1)

template<>
otExtAddress OTm8Buffer<otExtAddress>::default_value = { .m8 = { 0,0,0,0,0,0,0,0 } };
template<>
otExtendedPanId OTm8Buffer<otExtendedPanId>::default_value = { .m8 = { 0,0,0,0,0,0,0,0 } };
template<>
otMasterKey OTm8Buffer<otMasterKey>::default_value = { .m8 = { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } };
template<>
otNetworkName OTm8Buffer<otNetworkName>::default_value = { .m8 = { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0 } };
template<>
otPskc OTm8Buffer<otPskc>::default_value = { .m8 = { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } };

static void* otCAlloc(size_t n, size_t size)
{
  return memset(pvPortMalloc(n * size), 0, n * size);
}

static void otFree(void *p_ptr)
{
  vPortFree(p_ptr);
}

void OpenThreadClass::init()
{
#if OPENTHREAD_CONFIG_HEAP_EXTERNAL_ENABLE
  otHeapSetCAllocFree(otCAlloc, otFree);
#endif /* OPENTHREAD_CONFIG_HEAP_EXTERNAL_ENABLE */

  otrInit(0, NULL);
  //otCliUartInit(otrGetInstance());
  otrUserInit();
}

int OpenThreadClass::begin()
  otrStart();
  return 1;
}

#define HDR(x) #x "="
#define OTFUN(x) OpenThread.x()
#define DUMP(x) n += p.print(HDR(x)); n += p.println(OTFUN(x))
#define DUMPF(x, f) n += p.print(HDR(x)); n += p.println(OTFUN(x), f)
int OpenThreadClass::dump(Print& p)
{
  int n = 0;
  //DUMP(networkname);
  OTExtendedPanId epan = extpanid();
  n += p.print("extpanid="); n += p.println(epan);
  DUMPF(panid, HEX);
  OTExtAddress eadr = extaddr();
  n += p.print("extaddr="); n += p.println(eadr);

  OTExtAddress e64 = eui64();
  n += p.print("eui64="); n += p.println(e64);

#if OPENTHREAD_FTD
  OTPskc pk = pskc();
  n += p.print("pskc="); n += p.println(pk);
#endif
  OTMasterKey mkey = masterkey();
  n += p.print("masterkey="); n += p.println(mkey);
  DUMP(channel);
  DUMPF(rloc16, HEX);
  //DUMP(ipaddr);
  DUMP(version);

#if OPENTHREAD_CONFIG_COMMISSIONER_ENABLE
  DUMP(commissioner);
#endif
  DUMP(ifconfig);
  OTLinkModeConfig lmode = mode();
  n += p.print("mode="); n += p.println(lmode);
  DUMP(promiscuous);
#if OPENTHREAD_FTD
  DUMP(routereligible);
#endif
  DUMP(state);
  DUMP(singleton);
  DUMP(txpower);

  return n;
}

size_t OTMacCounters::printTo(Print& p) const {
  size_t n = 0; 
  n += p.print("TxTotal: "); n += p.println(value->mTxTotal);
  n += p.print("TxUnicast: "); n += p.println(value->mTxUnicast);
  n += p.print("TxBroadcast: "); n += p.println(value->mTxBroadcast);
  n += p.print("TxAckRequested: "); n += p.println(value->mTxAckRequested);
  n += p.print("TxAcked: "); n += p.println(value->mTxAcked);
  n += p.print("TxNoAckRequested: "); n += p.println(value->mTxNoAckRequested);
  n += p.print("TxData: "); n += p.println(value->mTxData);
  n += p.print("TxDataPoll: "); n += p.println(value->mTxDataPoll);
  n += p.print("TxBeacon: "); n += p.println(value->mTxBeacon);
  n += p.print("TxBeaconRequest: "); n += p.println(value->mTxBeaconRequest);
  n += p.print("TxOther: "); n += p.println(value->mTxOther);
  n += p.print("TxRetry: "); n += p.println(value->mTxRetry);
  n += p.print("TxErrCca: "); n += p.println(value->mTxErrCca);
  n += p.print("TxErrAbort: "); n += p.println(value->mTxErrAbort);
  n += p.print("TxErrBusyChannel: "); n += p.println(value->mTxErrBusyChannel);
  n += p.print("RxTotal: "); n += p.println(value->mRxTotal);
  n += p.print("RxUnicast: "); n += p.println(value->mRxUnicast);
  n += p.print("RxBroadcast: "); n += p.println(value->mRxBroadcast);
  n += p.print("RxData: "); n += p.println(value->mRxData);
  n += p.print("RxDataPoll: "); n += p.println(value->mRxDataPoll);
  n += p.print("RxBeacon: "); n += p.println(value->mRxBeacon);
  n += p.print("RxBeaconRequest: "); n += p.println(value->mRxBeaconRequest);
  n += p.print("RxOther: "); n += p.println(value->mRxOther);
  n += p.print("RxAddressFiltered: "); n += p.println(value->mRxAddressFiltered);
  n += p.print("RxDestAddrFiltered: "); n += p.println(value->mRxDestAddrFiltered);
  n += p.print("RxDuplicated: "); n += p.println(value->mRxDuplicated);
  n += p.print("RxErrNoFrame: "); n += p.println(value->mRxErrNoFrame);
  n += p.print("RxErrUnknownNeighbor: "); n += p.println(value->mRxErrUnknownNeighbor);
  n += p.print("RxErrInvalidSrcAddr: "); n += p.println(value->mRxErrInvalidSrcAddr);
  n += p.print("RxErrSec: "); n += p.println(value->mRxErrSec);
  n += p.print("RxErrFcs: "); n += p.println(value->mRxErrFcs);
  n += p.print("RxErrOther: "); n += p.println(value->mRxErrOther);
  return n;
}

const otRouterInfo* OTRouterIterator::next() {
  uint16_t max_routerid;
  index++;

  OT_API_CALL(
    max_routerid = otThreadGetMaxRouterId(otrGetInstance());
  );

  if(index >= max_routerid) {
    error = OT_ERROR_FAILED;
    return nullptr;
  }

  OT_API_CALL(
    error = otThreadGetRouterInfo(otrGetInstance(), index, &entry);
  );
  return get();
}


const otChildInfo* OTChildIterator::next() {
  uint16_t max_children;
  index++;

  OT_API_CALL(
    max_children = otThreadGetMaxAllowedChildren(otrGetInstance());
  );

  if(index >= max_children) {
    error = OT_ERROR_FAILED;
    return nullptr;
  }

  OT_API_CALL(
    error = otThreadGetChildInfoByIndex(otrGetInstance(), index, &entry);
  );
  return get();
}



const otIp6Address* OTChildIpIterator::next() {
  OT_API_CALL(
    error = otThreadGetChildNextIp6Address(otrGetInstance(), index, &iter, &entry);
  );
  return get();
}

const otCacheEntryInfo* OTEidCacheIterator::next() {
  OT_API_CALL(
    error = otThreadGetNextCacheEntry(otrGetInstance(), &entry, &iter);
  );
  return get();
}

const otNeighborInfo* OTNeighborIterator::next() {
  OT_API_CALL(
    error = otThreadGetNextNeighborInfo(otrGetInstance(), &iter, &entry);
  );
  return get();
}

const otBorderRouterConfig* OTPrefixIterator::next() {
  OT_API_CALL(
    error = otBorderRouterGetNextOnMeshPrefix(otrGetInstance(), &iter, &entry);
  );
  return get();
}

const otMacFilterEntry* OTMacfilterAddrIterator::next() {
  OT_API_CALL(
    error = otLinkFilterGetNextAddress(otrGetInstance(), &iter, &entry);
  );
  return get();
}

const otMacFilterEntry* OTMacfilterRssIterator::next() {
  OT_API_CALL(
    error = otLinkFilterGetNextRssIn(otrGetInstance(), &iter, &entry);
  );
  return get();
}

void OTMacfilterIterator::_next() {
  if(!addr_end) {
    error = otLinkFilterGetNextAddress(otrGetInstance(), &iter, &entry);
    if(error) {
      addr_end = true;
      error = OT_ERROR_NONE;
    }
  }
  else {
    error = otLinkFilterGetNextRssIn(otrGetInstance(), &iter, &entry);
  }
}

const otMacFilterEntry* OTMacfilterIterator::next() {
  OT_API_CALL(
    _next();
  );

  return get();
}

OTIpaddrIterator::OTIpaddrIterator() {
  OT_API_CALL(
    addr = otIp6GetUnicastAddresses(otrGetInstance());
  );
}

OTIpmaddrIterator::OTIpmaddrIterator() {
  OT_API_CALL(
    addr = otIp6GetMulticastAddresses(otrGetInstance());
  );
}



OpenThreadClass OpenThread;

