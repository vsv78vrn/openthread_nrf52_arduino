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

#define COMMISSION_BIT 1

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

namespace OTCMD {
  struct discover_data {
    //struct k_sem sem;
    otError error;
    otActiveScanResult* table;
    size_t size;
    size_t count;
  };
  struct discover_data sync_discover_context;

  void joiner_start_sync_callback(otError aResult, void *aContext);
  void discover_sync_callback(otActiveScanResult *aResult, void *aContext);
}

#define OT_GETTER_IMPL(ty, na, cat, n2)  \
ty OTCMD::  na  () \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC0(cat, Get ## n2) ); \
}

#define OT_V_FUNC_0_IMPL(na, cat, n2)  \
void OTCMD::  na  () \
{ \
  OT_API_CALL( OT_CALL_FUNC0(cat, n2) ); \
}

#define OT_FUNC_0_IMPL(ty, na, cat, n2)  \
ty OTCMD::  na  () \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC0(cat, n2) ); \
}

#define OT_V_FUNC_1_IMPL(na, cat, n2, t1)  \
void OTCMD::  na  (t1 a1) \
{ \
  OT_API_CALL( OT_CALL_FUNC1(cat, n2) ); \
}

#define OT_FUNC_1_IMPL(ty, na, cat, n2, t1)  \
ty OTCMD::  na  (t1 a1) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC1(cat, n2) ); \
}

#define OT_FUNC_2_IMPL(ty, na, cat, n2, t1, t2)  \
ty OTCMD::  na  (t1 a1, t2 a2) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC2(cat, n2) ); \
}

#define OT_FUNC_3_IMPL(ty, na, cat, n2, t1, t2, t3)  \
ty OTCMD::  na  (t1 a1, t2 a2, t3 a3) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC3(cat, n2) ); \
}

#define OT_FUNC_4_IMPL(ty, na, cat, n2, t1, t2, t3, t4)  \
ty OTCMD::  na  (t1 a1, t2 a2, t3 a3, t4 a4) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC4(cat, n2) ); \
}

#define OT_FUNC_5_IMPL(ty, na, cat, n2, t1, t2, t3, t4, t5)  \
ty OTCMD::  na  (t1 a1, t2 a2, t3 a3, t4 a4, t5 a5) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC5(cat, n2) ); \
}

#define OT_FUNC_6_IMPL(ty, na, cat, n2, t1, t2, t3, t4, t5, t6)  \
ty OTCMD::  na  (t1 a1, t2 a2, t3 a3, t4 a4, t5 a5, t6 a6) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC6(cat, n2) ); \
}

#define OT_FUNC_7_IMPL(ty, na, cat, n2, t1, t2, t3, t4, t5, t6, t7)  \
ty OTCMD::  na  (t1 a1, t2 a2, t3 a3, t4 a4, t5 a5, t6 a6, t7 a7) \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC7(cat, n2) ); \
}

#define OT_IS_IMPL(ty, na, cat, n2)  \
ty OTCMD::  na  () \
{ \
  OT_API_CALL_RET(ty, OT_CALL_FUNC0(cat, Is ## n2) ); \
}

#define OT_SETTER_IMPL(ty, na, cat, n2)  \
otError OTCMD:: na (ty a1) \
{ \
  OT_API_CALL_RET(otError, OT_CALL_FUNC1(cat, Set ## n2) ); \
}

#define OT_V_SETTER_IMPL(ty, na, cat, n2)  \
void OTCMD:: na (ty a1) \
{ \
  OT_API_CALL( OT_CALL_FUNC1(cat, Set ## n2) ); \
}

#define OT_SETGET_IMPL(ty, na, cat, n2)  \
  OT_GETTER_IMPL(ty, na, cat, n2) \
  OT_SETTER_IMPL(ty, na, cat, n2)

#define OT_SET_IS_IMPL(ty, na, cat, n2)  \
  OT_IS_IMPL(ty, na, cat, n2) \
  OT_SETTER_IMPL(ty, na, cat, n2)

#define OT_V_SETGET_IMPL(ty, na, cat, n2)  \
  OT_GETTER_IMPL(ty, na, cat, n2) \
  OT_V_SETTER_IMPL(ty, na, cat, n2)

#define OT_V_SET_IS_IMPL(ty, na, cat, n2)  \
  OT_IS_IMPL(ty, na, cat, n2) \
  OT_V_SETTER_IMPL(ty, na, cat, n2)

#define OT_COPY_IP6(ip6, addr) {\
    ip6.mFields.m16[0] = addr.v6[0]; \
    ip6.mFields.m16[1] = addr.v6[1]; \
    ip6.mFields.m16[2] = addr.v6[2]; \
    ip6.mFields.m16[3] = addr.v6[3]; \
    ip6.mFields.m16[4] = addr.v6[4]; \
    ip6.mFields.m16[5] = addr.v6[5]; \
    ip6.mFields.m16[6] = addr.v6[6]; \
    ip6.mFields.m16[7] = addr.v6[7]; \
}

// x help
OT_V_FUNC_1_IMPL(bufferinfo, Message, GetBufferInfo, otBufferInfo*);
OT_SETGET_IMPL(uint8_t, channel, Link, Channel);
OT_GETTER_IMPL(uint32_t, channel_supported, PlatRadio, SupportedChannelMask);
OT_GETTER_IMPL(uint32_t, channel_preferred, PlatRadio, PreferredChannelMask);
#if OPENTHREAD_CONFIG_CHANNEL_MONITOR_ENABLE
//otError channel_monitor();
//otError channel_monitor_start();
//otError channel_monitor_stop();
#endif
#if OPENTHREAD_CONFIG_CHANNEL_MANAGER_ENABLE && OPENTHREAD_FTD
//otError channel_manager();
//otError channel_manager_change(uint8_t);
#if OPENTHREAD_CONFIG_CHANNEL_MONITOR_ENABLE
//otError channel_manager_select(bool);
#endif
//otError channel_manager_auto(bool);
//otError channel_manager_delay(uint8_t);
//otError channel_manager_interval(uint32_t);
//otError channel_manager_supported(uint32_t);
//otError channel_manager_favored(uint32_t);
#endif

#if (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)
//otError bbr(otBackboneRouterConfig&);
#if OPENTHREAD_FTD && OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE
OT_V_SETTER_IMPL(bool, _bbr, BackboneRouter, Enabled);
void bbr_disable() { _bbr(false); }
void bbr_enable() { _bbr(true); }
OT_V_SETGET_IMPL(uint8_t, bbr_jitter, BackboneRouter, RegistrationJitter);
//otError bbr_register();
//otBackboneRouterState bbr_state();
//otError bbr_config(uint8_t, uint16_t, uint32_t);
#endif // OPENTHREAD_FTD && OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE
#endif // (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)


#if OPENTHREAD_FTD
OTChildIterator OTCMD::child();

OTChildIpIterator OTCMD::childip(uint16_t index);
OT_GETTER_IMPL(uint8_t, childip_max, Thread, MaxChildIpAddresses);
#if OPENTHREAD_CONFIG_REFERENCE_DEVICE_ENABLE
OT_SETTER_IMPL(uint8_t, childip_max, Thread, MaxChildIpAddresses);
#endif
OT_SETGET_IMPL(uint8_t, childmax, Thread, MaxAllowedChildren);
#endif
OT_V_SETGET_IMPL(uint32_t, childtimeout, Thread, ChildTimeout);
// x coap
// x coaps


#if OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_ENABLE
//???	coex
//???	coex_enable
//???	coex_disable
//???	coex_metrics
#endif // OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_ENABLE

#if OPENTHREAD_CONFIG_COMMISSIONER_ENABLE
OT_GETTER_IMPL(otCommissionerState, commissioner, Commissioner, State);
OT_FUNC_3_IMPL(otError, commissioner_start, Commissioner, Start, otCommissionerStateCallback, otCommissionerJoinerCallback, void*);
OT_FUNC_0_IMPL(otError, commissioner_stop, Commissioner, Stop);
OT_SETTER_IMPL(const char*, commissioner_provisioningurl, Commissioner, ProvisioningUrl);
OT_FUNC_4_IMPL(otError, commissioner_announce, Commissioner, AnnounceBegin, uint32_t, uint8_t, uint16_t, const otIp6Address*);
OT_FUNC_7_IMPL(otError, commissioner_energy, Commissioner, EnergyScan, uint32_t, uint8_t, uint16_t, uint16_t, const otIp6Address*, otCommissionerEnergyReportCallback, void*);
OT_FUNC_5_IMPL(otError, commissioner_panid, Commissioner, PanIdQuery, uint16_t, uint32_t, const otIp6Address*, otCommissionerPanIdConflictCallback, void*);
OT_GETTER_IMPL(uint16_t, commissioner_sessionid, Commissioner, SessionId);
OT_FUNC_3_IMPL(otError, commissioner_joiner_add, Commissioner, AddJoiner, const otExtAddress*, const char*, uint32_t);
OT_FUNC_1_IMPL(otError, commissioner_joiner_remove, Commissioner, RemoveJoiner, const otExtAddress*);
#endif

#if OPENTHREAD_FTD
OT_V_SETGET_IMPL(uint32_t, contextreusedelay, Thread, ContextIdReuseDelay);
#endif

OT_GETTER_IMPL(const otMacCounters*, counters_mac, Link, Counters);
OT_V_FUNC_0_IMPL(counters_mac_reset, Link, ResetCounters);
OT_GETTER_IMPL(const otMleCounters*, counters_mle, Thread, MleCounters);
OT_V_FUNC_0_IMPL(counters_mle_reset, Thread, ResetMleCounters);

// x dataset

#if OPENTHREAD_FTD
OT_SETGET_IMPL(uint32_t, delaytimermin, Dataset, DelayTimerMinimal);
#endif
OT_FUNC_4_IMPL(otError, diag, Diag, ProcessCmd, uint8_t, char**, char*, size_t);
otError OTCMD::discover(uint32_t, otHandleActiveScanResult, void*);
otError OTCMD::discover(otActiveScanResult*, size_t, uint32_t);
#if OPENTHREAD_CONFIG_DNS_CLIENT_ENABLE
otError OTCMD::dns_resolve(const char*, const otIp6Address*, uint16_t, otDnsResponseHandler, void*);
otError OTCMD::dns_resolve(const char*, otDnsResponseHandler, void*);
#endif
#if OPENTHREAD_FTD
OTEidCacheIterator OTCMD::eidcache();
#endif
OT_V_FUNC_1_IMPL(eui64, Link, GetFactoryAssignedIeeeEui64, otExtAddress*);
const otExtAddress* OTCMD::eui64() { static otExtAddress eaddr; eui64(&eaddr); return &eaddr; }
#if OPENTHREAD_POSIX
// x exit
#endif
#if (OPENTHREAD_CONFIG_LOG_OUTPUT == OPENTHREAD_CONFIG_LOG_OUTPUT_DEBUG_UART) && OPENTHREAD_POSIX
// &&&	logfilename	\<filename\>
#endif
OT_SETGET_IMPL(const otExtAddress*, extaddr, Link, ExtendedAddress);
OT_SETGET_IMPL(const otExtendedPanId*, extpanid, Thread, ExtendedPanId);
OT_V_FUNC_0_IMPL(factoryreset, Instance, FactoryReset);
OT_FUNC_0_IMPL(bool, ifconfig, Ip6, IsEnabled);
OT_FUNC_1_IMPL(otError, _ifconfig, Ip6, SetEnabled, bool);
otError OTCMD::ifconfig_up() { return _ifconfig(true); }
otError OTCMD::ifconfig_down() { return _ifconfig(false); }
OTIpaddrIterator OTCMD::ipaddr();
OT_FUNC_1_IMPL(otError, _ipaddr_add, Ip6, AddUnicastAddress, const struct otNetifAddress*);
OT_FUNC_1_IMPL(otError, ipaddr_del, Ip6, RemoveUnicastAddress, const otIp6Address*);
OT_GETTER_IMPL(const otIp6Address*, ipaddr_linklocal, Thread, LinkLocalIp6Address);
OT_GETTER_IMPL(const otIp6Address*, ipaddr_mleid, Thread, MeshLocalEid);
OT_GETTER_IMPL(const otIp6Address*, ipaddr_rloc, Thread, Rloc);
OTIpmaddrIterator OTCMD::ipmaddr();
OT_FUNC_1_IMPL(otError, ipmaddr_add, Ip6, SubscribeMulticastAddress, const otIp6Address*);
OT_FUNC_1_IMPL(otError, ipmaddr_del, Ip6, UnsubscribeMulticastAddress, const otIp6Address*);
OT_FUNC_0_IMPL(bool, ipmaddr_promiscuous, Ip6, IsMulticastPromiscuousEnabled);
OT_V_SETTER_IMPL(bool, ipmaddr_promiscuous, Ip6, MulticastPromiscuousEnabled);
#if OPENTHREAD_CONFIG_JOINER_ENABLE
OT_V_FUNC_1_IMPL(joiner_id, Joiner, GetId, otExtAddress*);
const otExtAddress* OTCMD::joiner_id() { static otExtAddress eaddr; joiner_id(&eaddr); return &eaddr; }
otError OTCMD::joiner_start(const char* pskc, const char* provision, otJoinerCallback cb, void* ctx);
otError OTCMD::joiner_start(const char* pskc, const char* provision);
OT_V_FUNC_0_IMPL(joiner_stop, Joiner, Stop);
#endif
#if OPENTHREAD_FTD
OT_GETTER_IMPL(uint16_t, joinerport, Thread, JoinerUdpPort);
#endif
OT_V_SETGET_IMPL(uint32_t, keysequence_counter, Thread, KeySequenceCounter);
OT_V_SETGET_IMPL(uint32_t, keysequence_guardtime, Thread, KeySwitchGuardTime);
OT_FUNC_1_IMPL(otError, leaderdata, Thread, GetLeaderData, otLeaderData*);
#if OPENTHREAD_FTD
OT_V_SETGET_IMPL(uint32_t, leaderpartitionid, Thread, LocalLeaderPartitionId);
OT_V_SETGET_IMPL(uint8_t, leaderweight, Thread, LocalLeaderWeight);
#endif
OT_SETGET_IMPL(const otMasterKey*, masterkey, Thread, MasterKey);
OT_SETGET_IMPL(otLinkModeConfig, mode, Thread, LinkMode);
#if OPENTHREAD_FTD
OTNeighborIterator OTCMD::neighbor();
#endif
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE || OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError OTCMD::netdataregister();
otError OTCMD::netdatashow(uint8_t*, uint8_t&);
#endif
#if OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError OTCMD::service_add(uint32_t, uint8_t*, uint8_t, uint8_t*, uint8_t);
otError OTCMD::service_add(uint32_t, const char*, const char*);
otError OTCMD::service_remove(uint32_t, const char*);
OT_FUNC_3_IMPL(otError, service_remove, Server, RemoveService, uint32_t, uint8_t*, uint8_t);
#endif
#if OPENTHREAD_FTD || OPENTHREAD_CONFIG_TMF_NETWORK_DIAG_MTD_ENABLE
OT_FUNC_3_IMPL(otError, networkdiagnostic_get, Thread, SendDiagnosticGet, const otIp6Address*, uint8_t*, uint8_t);
OT_FUNC_3_IMPL(otError, networkdiagnostic_reset, Thread, SendDiagnosticReset, const otIp6Address*, uint8_t*, uint8_t);
#endif
#if OPENTHREAD_FTD
OT_V_SETGET_IMPL(uint8_t, networkidtimeout, Thread, NetworkIdTimeout);
#endif
OT_FUNC_0_IMPL(const char*, networkname, Thread, GetNetworkName);
OT_FUNC_1_IMPL(otError, networkname, Thread, SetNetworkName, const char*);
#if OPENTHREAD_CONFIG_TIME_SYNC_ENABLE
// x networktime
#endif
OT_SETGET_IMPL(uint16_t, panid, Link, PanId);
OT_FUNC_1_IMPL(otError, parent, Thread, GetParentInfo, otRouterInfo*);
#if OPENTHREAD_FTD
OT_SETGET_IMPL(uint8_t, parentpriority, Thread, ParentPriority);
#endif
//otError ping(IPAddress& addr, const uint8_t*, uint16_t);
OT_SETGET_IMPL(uint32_t, pollperiod, Link, PollPeriod);
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
OTPrefixIterator OTCMD::prefix();
otError OTCMD::prefix_add(const otIp6Prefix*, otRoutePreference, bool, bool, bool, bool, bool, bool, bool);
OT_FUNC_1_IMPL(otError, _prefix_add, BorderRouter, AddOnMeshPrefix, const otBorderRouterConfig*);
OT_FUNC_1_IMPL(otError, prefix_remove, BorderRouter, RemoveOnMeshPrefix, const otIp6Prefix*);
#endif
OT_FUNC_0_IMPL(bool, promiscuous, Link, IsPromiscuous);
#if OPENTHREAD_FTD
OT_SETTER_IMPL(uint8_t, preferrouterid, Thread, PreferredRouterId);
OT_SETGET_IMPL(const otPskc*, pskc, Thread, Pskc);
OT_FUNC_1_IMPL(otError, releaserouterid, Thread, ReleaseRouterId, uint8_t);
#endif
OT_V_FUNC_0_IMPL(reset, Instance, Reset);
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
OTRouteIterator OTCMD::route();
otError OTCMD::route_add(otRoutePreference preference, bool stable);
OT_FUNC_1_IMPL(otError, route_add, BorderRouter, AddRoute, const otExternalRouteConfig*);
OT_FUNC_1_IMPL(otError, route_remove, BorderRouter, RemoveRoute, const otIp6Prefix*);
#endif
#if OPENTHREAD_FTD
OTRouterIterator OTCMD::router();
OT_FUNC_2_IMPL(otError, router, Thread, GetRouterInfo, int, otRouterInfo*);
OT_V_SETGET_IMPL(uint8_t, routerdowngradethreshold, Thread, RouterDowngradeThreshold);
OT_FUNC_0_IMPL(bool, routereligible, Thread, IsRouterEligible);
OT_V_SETGET_IMPL(uint8_t, routerselectionjitter, Thread, RouterSelectionJitter);
OT_V_SETGET_IMPL(uint8_t, routerupgradethreshold, Thread, RouterUpgradeThreshold);
#endif
OT_GETTER_IMPL(uint16_t, rloc16, Thread, Rloc16);
OT_FUNC_4_IMPL(otError, scan, Link, ActiveScan, uint16_t, uint32_t, otHandleActiveScanResult, void*);
OT_FUNC_4_IMPL(otError, scan_energy, Link, EnergyScan, uint16_t, uint32_t, otHandleEnergyScanResult, void*);
OT_IS_IMPL(bool, singleton, Thread, Singleton);
#if OPENTHREAD_CONFIG_SNTP_CLIENT_ENABLE
otError OTCMD::sntp_query(const otIp6Address* addr, uint16_t port, otSntpResponseHandler handler, void* context);
#endif
OT_GETTER_IMPL(otDeviceRole, state, Thread, DeviceRole);
OT_FUNC_0_IMPL(otError, state_child, Thread, BecomeChild);
OT_FUNC_0_IMPL(otError, state_detached, Thread, BecomeDetached);
OT_FUNC_0_IMPL(otError, state_router, Thread, BecomeRouter);
OT_FUNC_0_IMPL(otError, state_leader, Thread, BecomeLeader);
OT_SETTER_IMPL(bool, _thread, Thread, Enabled);
otError OTCMD::thread_start() { return _thread(true); }
otError OTCMD::thread_stop() { return _thread(false); }
uint16_t OTCMD::thread_version() { return otThreadGetVersion(); }
//dataset
OT_SETTER_IMPL(int8_t, txpower, PlatRadio, TransmitPower);
OT_FUNC_1_IMPL(otError, _txpower, PlatRadio, GetTransmitPower, int8_t*);
int8_t OTCMD::txpower() { int8_t r; otError e = _txpower(&r); return e ? 0 : r; }
const char* OTCMD::version() { return otGetVersionString(); }
#if OPENTHREAD_CONFIG_MAC_FILTER_ENABLE
OT_FUNC_2_IMPL(otError, macfilter_addr_add, LinkFilter, AddRssIn, const otExtAddress*, uint8_t);
otError OTCMD::macfilter_addr_add(uint8_t rss) { return macfilter_addr_add(nullptr, rss); }
OT_FUNC_1_IMPL(otError, macfilter_addr_remove, LinkFilter, RemoveAddress, const otExtAddress*);
OT_V_FUNC_0_IMPL(macfilter_addr_clear, LinkFilter, ClearAddresses);

OT_FUNC_2_IMPL(otError, macfilter_rss_add, LinkFilter, AddRssIn, const otExtAddress*, uint8_t);
otError OTCMD::macfilter_rss_add(uint8_t rss) { return macfilter_rss_add(NULL, rss); }
OT_FUNC_1_IMPL(otError, macfilter_rss_remove, LinkFilter, RemoveRssIn, const otExtAddress*);
OT_V_FUNC_0_IMPL(macfilter_rss_clear, LinkFilter, ClearRssIn);

OT_V_SETGET_IMPL(otMacFilterAddressMode, _macfilter_addr_mode, LinkFilter, AddressMode);
void OTCMD::macfilter_addr_disable() { _macfilter_addr_mode(OT_MAC_FILTER_ADDRESS_MODE_DISABLED); }
void OTCMD::macfilter_addr_blacklist() { _macfilter_addr_mode(OT_MAC_FILTER_ADDRESS_MODE_BLACKLIST); }
void OTCMD::macfilter_addr_whitelist() { _macfilter_addr_mode(OT_MAC_FILTER_ADDRESS_MODE_WHITELIST); }
#endif

OT_V_SETGET_IMPL(uint8_t, mac_retries_direct, Link, MaxFrameRetriesDirect);
OT_V_SETGET_IMPL(uint8_t, mac_retries_indirect, Link, MaxFrameRetriesIndirect);


otError OTCMD::discover(uint32_t chbits, otHandleActiveScanResult callback, void* context)
{
  OT_API_CALL_RET(otError,
    otThreadDiscover(otrGetInstance(), chbits, OT_PANID_BROADCAST, false, false, callback, context)
  );
}

void OTCMD::discover_sync_callback(otActiveScanResult *aResult, void *aContext)
{
/* TODO
  struct discover_data* data= reinterpret_cast<struct discover_data*>(aContext);
  if(aResult) {
    if(data->size == data->count) {
      data->error = OT_ERROR_NO_BUFS;
      k_sem_give(&data->sem);
    }
    else {
      memcpy(&data->table[data->count], aResult, sizeof(otActiveScanResult));
      data->count++;
    }
  }
  else {
    if(data->error != OT_ERROR_NO_BUFS) {
      k_sem_give(&data->sem);
    }
  }
*/
}

otError OTCMD::discover(otActiveScanResult* table, size_t tablesize, uint32_t chbits)
{
/* TODO
  memset(&sync_discover_context, 0, sizeof(struct discover_data));

  sync_discover_context.table = table;
  sync_discover_context.size = tablesize;
  k_sem_init(&sync_discover_context.sem, 0, 1);

  otError err = otThreadDiscover(otrGetInstance(), chbits, OT_PANID_BROADCAST, false, false, discover_sync_callback, &sync_discover_context);
  if(err) return err;

  k_sem_take(&sync_discover_context.sem, K_FOREVER);

  return sync_discover_context.error;
*/
  return OT_ERROR_NONE;
}

otError OTCMD::ipaddr_add(const otIp6Address* addr, uint8_t prefixlen, bool preferred, bool valid, bool scopeoverridevalid, uint32_t scopeoverride, bool rloc)
{
  struct otNetifAddress address;

  memcpy(&address.mAddress, addr, sizeof(otIp6Address));
  address.mPrefixLength = prefixlen;
  address.mPreferred = preferred;
  address.mValid = valid;
  address.mScopeOverrideValid = scopeoverridevalid;
  address.mScopeOverride = scopeoverride;
  address.mRloc = rloc;

  return  _ipaddr_add(&address);
}


#if OPENTHREAD_CONFIG_JOINER_ENABLE

otError OTCMD::joiner_start(const char* pskc, const char* provision, otJoinerCallback cb, void* ctx)
{
  OT_API_CALL_RET(otError,
    otJoinerStart(otrGetInstance(), pskc, provision, PACKAGE_NAME, OPENTHREAD_CONFIG_PLATFORM_INFO,
                      PACKAGE_VERSION, NULL, cb, ctx);
  );
}

void OTCMD::joiner_start_sync_callback(otError aResult, void *aContext)
{
  otError* ptrerr = reinterpret_cast<otError*>(aContext);
  *ptrerr = aResult;
  notifyLoop(COMMISSION_BIT);
}

otError OTCMD::joiner_start(const char* pskc, const char* provision)
{
  otError cbErr = OT_ERROR_NONE;
  otError err = joiner_start(pskc, provision, joiner_start_sync_callback, &cbErr);
  if(err) return err;

  waitLoop(COMMISSION_BIT);

  return cbErr;
}

#endif

otError OTCMD::ping(const otIp6Address* addr, const uint8_t* buffer, uint16_t buflen)
{
  return OT_ERROR_NONE; //TODO
}

otError OTCMD::promiscuous_enable(otLinkPcapCallback cb, void* ctx)
{
  OT_API_CALL(otLinkSetPcapCallback(otrGetInstance(), cb, ctx); );
  OT_API_CALL_RET(otError,
    otLinkSetPromiscuous(otrGetInstance(), true);
  );
}

otError OTCMD::promiscuous_disable()
{
  OT_API_CALL( otLinkSetPcapCallback(otrGetInstance(), NULL, NULL); );
  OT_API_CALL_RET(otError,
    otLinkSetPromiscuous(otrGetInstance(), false);
  );
}

typedef otError (*state_func)(otInstance*);

otError OTCMD::state(otDeviceRole role)
{
  state_func statefunc = nullptr;
  switch (role)
  {
    case OT_DEVICE_ROLE_DETACHED:
      statefunc = otThreadBecomeDetached;
      break;
    case OT_DEVICE_ROLE_CHILD:
      statefunc = otThreadBecomeChild;
      break;

#if OPENTHREAD_FTD
    case OT_DEVICE_ROLE_ROUTER:
      statefunc = otThreadBecomeRouter;
      break;
    case OT_DEVICE_ROLE_LEADER:
      statefunc = otThreadBecomeLeader;
      break;
#endif // OPENTHREAD_FTD
    default:
      return OT_ERROR_INVALID_ARGS;
  }
  OT_API_CALL_RET(otError,
    statefunc(otrGetInstance());
  );
}


otError OTCMD::commissioner_joiner_add(const char* pskd, uint32_t timeout)
{
  return commissioner_joiner_add(NULL, pskd, timeout);
}

otError OTCMD::commissioner_joiner_remove()
{
  return commissioner_joiner_remove(NULL);
}

otError OTCMD::commissioner_mgmtget(otMeshcopTlvType* tlvtypes, uint8_t count)
{
  uint8_t tlvs[32];

  for(uint8_t i=0; i<count; i++) {
    tlvs[i] = tlvtypes[i];
  }

  OT_API_CALL_RET(otError,
    otCommissionerSendMgmtGet(otrGetInstance(), tlvs, count);
  );
}

otError OTCMD::commissioner_mgmtset(uint32_t rloc, uint32_t sessionid, uint32_t port, uint8_t* steeringdata, uint8_t steeringlen, otMeshcopTlvType* tlvtypes, uint8_t count)
{
  uint8_t tlvs[32];
  otCommissioningDataset dataset;

  if(rloc <= 0xFFFFL) {
    dataset.mIsLocatorSet = true;
    dataset.mLocator = static_cast<uint16_t>(rloc);
  }

  if(sessionid <= 0xFFFFL) {
    dataset.mIsSessionIdSet = true;
    dataset.mSessionId = static_cast<uint16_t>(sessionid);
  }

  if(steeringdata != NULL) {
    dataset.mIsSteeringDataSet = true;
    memcpy(dataset.mSteeringData.m8, steeringdata, steeringlen);
    dataset.mSteeringData.mLength = steeringlen;
  }

  if(port <= 0xFFFFL) {
    dataset.mIsJoinerUdpPortSet = true;
    dataset.mJoinerUdpPort = static_cast<uint16_t>(port);
  }

  for(uint8_t i=0; i<count; i++) {
    tlvs[i] = tlvtypes[i];
  }

  OT_API_CALL_RET(otError,
    otCommissionerSendMgmtSet(otrGetInstance(), &dataset, tlvs, count);
  );
}





#if OPENTHREAD_CONFIG_DNS_CLIENT_ENABLE

otError OTCMD::dns_resolve(const char* hostname, const otIp6Address* addr, uint16_t port, otDnsResponseHandler handler, void* context)
{
  otDnsQuery query = { 0 };
  otMessageInfo msginfo = { 0 };

  msginfo.mPeerAddr = *addr;
  msginfo.mPeerPort = port;

  query.mHostname = hostname,
  query.mMessageInfo = &msginfo;
  query.mNoRecursion = false;

  OT_API_CALL_RET(otError,
    otDnsClientQuery(otrGetInstance(), &query, handler, context);
  );
}

otError OTCMD::dns_resolve(const char* hostname, otDnsResponseHandler handler, void* context)
{
  otIp6Address addr;
  otIp6AddressFromString(OT_DNS_DEFAULT_SERVER_IP, &addr);
  return dns_resolve(hostname, &addr, OT_DNS_DEFAULT_SERVER_PORT, handler, context);
}

#endif


#if OPENTHREAD_CONFIG_MAC_FILTER_ENABLE
otError OTCMD::macfilter_rss_add_lqi(const otExtAddress* addr, uint8_t linkquality)
{
  OT_API_CALL_RET(otError,
    otLinkFilterAddRssIn(otrGetInstance(), addr, otLinkConvertLinkQualityToRss(otrGetInstance(), linkquality) );
  );
}

otError OTCMD::macfilter_rss_add_lqi(uint8_t linkquality)
{
  return macfilter_rss_add_lqi(NULL, linkquality);
}
#endif

#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE || OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError OTCMD::netdataregister()
{
  OT_API_CALL_RET(otError,
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
    otBorderRouterRegister(otrGetInstance());
#else
    otServerRegister(otrGetInstance());
#endif
  );
}

otError OTCMD::netdatashow(uint8_t* data, uint8_t& len)
{
  OT_API_CALL_RET(otError,
    otNetDataGet(otrGetInstance(), false, data, &len);
  );
}
#endif

otError OTCMD::pskc_passphrase(const char* passphrase)
{
  otPskc pskc;
  otError error;
  OT_API_CALL_RET(otError,
    otDatasetGeneratePskc(passphrase,
                              reinterpret_cast<const otNetworkName *>(otThreadGetNetworkName(otrGetInstance())),
                              otThreadGetExtendedPanId(otrGetInstance()), &pskc);
  );

  OT_API_CALL_RET(otError,
    otThreadSetPskc(otrGetInstance(), &pskc);
  );
exit:
  return error;
}

#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
otError OTCMD::prefix_add(const otIp6Prefix* prefix, otRoutePreference preference, 
		bool preferred, bool slaac, bool dhcp, bool config, bool defaultroute, bool onmesh, bool stable)
{
  otBorderRouterConfig cfg = { 0 };
  cfg.mPreference = preference;
  cfg.mPrefix = *prefix;

  cfg.mPreferred = preferred;
  cfg.mSlaac = slaac;
  cfg.mDhcp = dhcp;
  cfg.mConfigure = config;
  cfg.mDefaultRoute = defaultroute;
  cfg.mOnMesh = onmesh;
  cfg.mStable = stable;

  return _prefix_add(&cfg);
}
#endif

#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
otError OTCMD::route_add(otRoutePreference preference, bool stable)
{
  otExternalRouteConfig cfg = { 0 };
  cfg.mPreference = preference;
  cfg.mStable = stable;
  return route_add(&cfg);
}
#endif

#if OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError OTCMD::service_add(uint32_t no, uint8_t* servicedata, uint8_t servicedatasize, uint8_t* serverdata, uint8_t serverdatasize)
{
  otServiceConfig cfg = { 0 };
  cfg.mEnterpriseNumber = no;
  if(servicedatasize > sizeof(cfg.mServiceData)) return OT_ERROR_NO_BUFS;
  if(serverdatasize  > sizeof(cfg.mServerConfig.mServerData)) return OT_ERROR_NO_BUFS;
  memcpy(cfg.mServiceData, servicedata, servicedatasize);
  memcpy(cfg.mServerConfig.mServerData, serverdata, serverdatasize);
  cfg.mServiceDataLength = servicedatasize;
  cfg.mServerConfig.mServerDataLength = serverdatasize;
  cfg.mServerConfig.mStable = true;

  OT_API_CALL_RET(otError,
    otServerAddService(otrGetInstance(), &cfg);
  );
}
otError OTCMD::service_add(uint32_t no, const char* servicedata, const char* serverdata)
{
  return service_add(no, 
    const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(servicedata)), static_cast<uint8_t>(strlen(servicedata)),
    const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(serverdata)),  static_cast<uint8_t>(strlen(serverdata)) );
}


otError OTCMD::service_remove(uint32_t no, const char* servicedata)
{
  return service_remove(no, 
    const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(servicedata)), static_cast<uint8_t>(strlen(servicedata)));
}
#endif

#if OPENTHREAD_CONFIG_SNTP_CLIENT_ENABLE
otError OTCMD::sntp_query(const otIp6Address* addr, uint16_t port, otSntpResponseHandler handler, void* context)
{
  otSntpQuery query = { 0 };
  otMessageInfo msginfo = { 0 };

  msginfo.mPeerAddr = *addr;
  msginfo.mPeerPort = port;

  query.mMessageInfo = &msginfo;

  OT_API_CALL_RET(otError,
    otSntpClientQuery(otrGetInstance(), &query, handler, context);
  );
}
#endif

