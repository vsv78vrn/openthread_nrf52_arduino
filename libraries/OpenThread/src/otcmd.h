#ifndef OTCMD_H__
#define OTCMD_H__

#include <Print.h>

#include <openthread/config.h>
#include <openthread/commissioner.h>
#include <openthread/icmp6.h>
#include <openthread/joiner.h>
#include <openthread/link.h>
#if OPENTHREAD_CONFIG_ENABLE_TIME_SYNC
#include <openthread/network_time.h>
#endif

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

#include <openthread/heap.h>
#include <openthread/sntp.h>

extern "C" {
#include <openthread/openthread-freertos.h>
}

class OTChildIterator;
class OTChildIpIterator;
class OTRouteIterator;
class OTRouterIterator;
class OTEidCacheIterator;
class OTNeighborIterator;
class OTPrefixIterator;
class OTMacfilterAddrIterator;
class OTMacfilterRssIterator ;
class OTMacfilterIterator ;
class OTIpaddrIterator;
class OTIpmaddrIterator;




namespace OTCMD {

void bufferinfo(otBufferInfo*);
uint8_t channel();
otError channel(uint8_t);
uint32_t channel_supported();
uint32_t channel_preferred();
#if OPENTHREAD_CONFIG_CHANNEL_MONITOR_ENABLE
otError channel_monitor();
otError channel_monitor_start();
otError channel_monitor_stop();
#endif
#if OPENTHREAD_CONFIG_CHANNEL_MANAGER_ENABLE && OPENTHREAD_FTD
otError channel_manager();
otError channel_manager_change(uint8_t);
#if OPENTHREAD_CONFIG_CHANNEL_MONITOR_ENABLE
otError channel_manager_select(bool);
#endif
otError channel_manager_auto(bool);
otError channel_manager_delay(uint8_t);
otError channel_manager_interval(uint32_t);
otError channel_manager_supported(uint32_t);
otError channel_manager_favored(uint32_t);
#endif
#if (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)
//otError bbr(otBackboneRouterConfig&);
#if OPENTHREAD_FTD && OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE
void _bbr(bool);
void bbr_disable();
void bbr_enable();
uint8_t bbr_jitter();
void bbr_jitter(uint8_t);
otError bbr_register();
otBackboneRouterState bbr_state();
otError bbr_config(uint8_t, uint16_t, uint32_t);
#endif // OPENTHREAD_FTD && OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE
#endif // (OPENTHREAD_CONFIG_THREAD_VERSION >= OT_THREAD_VERSION_1_2)

#if OPENTHREAD_FTD
OTChildIterator child();
otError child(int, otChildInfo*);
OTChildIpIterator childip(uint16_t);
uint8_t childip_max();
#if OPENTHREAD_CONFIG_REFERENCE_DEVICE_ENABLE
void childip_max(uint8_t);
#endif
uint8_t childmax();
otError childmax(uint8_t);
#endif // OPENTHREAD_FTD
uint32_t childtimeout();
void childtimeout(uint32_t);
#if OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_ENABLE
bool coex();
void coex_enable();
void coex_disable();
otError coex_metrics(otRadioCoexMetrics&);
#endif // OPENTHREAD_CONFIG_PLATFORM_RADIO_COEX_ENABLE
#if OPENTHREAD_CONFIG_COMMISSIONER_ENABLE && OPENTHREAD_FTD
otCommissionerState commissioner();
otError commissioner_announce(uint32_t, uint8_t, uint16_t, const otIp6Address*);
otError commissioner_energy(uint32_t, uint8_t, uint16_t, uint16_t, const otIp6Address*, otCommissionerEnergyReportCallback, void*);
otError commissioner_joiner_add(const otExtAddress*, const char*, uint32_t);
otError commissioner_joiner_add(const char*, uint32_t);
otError commissioner_joiner_remove(const otExtAddress*);
otError commissioner_joiner_remove();
otError commissioner_mgmtget(otMeshcopTlvType* tlvs, uint8_t count);
otError commissioner_mgmtset(uint32_t, uint32_t, uint32_t, uint8_t*, uint8_t, otMeshcopTlvType*, uint8_t);










otError commissioner_panid(uint16_t, uint32_t, const otIp6Address*, otCommissionerPanIdConflictCallback, void*);
otError commissioner_provisioningurl(const char*);
uint16_t commissioner_sessionid();
otError commissioner_start(otCommissionerStateCallback, otCommissionerJoinerCallback, void*);
otError commissioner_stop();
#endif // OPENTHREAD_CONFIG_COMMISSIONER_ENABLE && OPENTHREAD_FTD

#if OPENTHREAD_FTD
void contextreusedelay(uint32_t);
uint32_t contextreusedelay();
#endif // OPENTHREAD_FTD

const otMacCounters* counters_mac();
void  counters_mac_reset();
const otMleCounters* counters_mle();
void  counters_mle_reset();

#if OPENTHREAD_FTD
uint32_t delaytimermin();
otError delaytimermin(uint32_t);
#endif
#if OPENTHREAD_CONFIG_DIAG_ENABLE
otError diag(uint8_t, char**, char*, size_t);
#endif
otError discover(otActiveScanResult*, size_t, uint32_t chbits=0xFFFFFFFF);
otError discover(uint32_t, otHandleActiveScanResult, void*);
#if OPENTHREAD_CONFIG_DNS_CLIENT_ENABLE
otError dns_resolve(const char*, const otIp6Address*, uint16_t, otDnsResponseHandler, void*);
otError dns_resolve(const char*, otDnsResponseHandler, void*);
#endif

#if OPENTHREAD_FTD
OTEidCacheIterator eidcache();
#endif // OPENTHREAD_FTD
void eui64(otExtAddress*);
const otExtAddress* eui64();
#if OPENTHREAD_POSIX
otError exit(uint8_t, char**);
#endif
#if (OPENTHREAD_CONFIG_LOG_OUTPUT == OPENTHREAD_CONFIG_LOG_OUTPUT_DEBUG_UART) && OPENTHREAD_POSIX
void logfilename(const char*);
#endif
const otExtAddress* extaddr();
otError extaddr(const otExtAddress*);
const otExtendedPanId* extpanid();
otError extpanid(const otExtendedPanId*);
void factoryreset();
otError _ifconfig(bool);
bool ifconfig();
otError ifconfig_up();
otError ifconfig_down();
OTIpaddrIterator ipaddr();
otError _ipaddr_add(const struct otNetifAddress*);
otError ipaddr_add(const otIp6Address*, uint8_t, bool, bool, bool, uint32_t, bool);
otError ipaddr_del(const otIp6Address*);
const otIp6Address* ipaddr_linklocal();
const otIp6Address* ipaddr_mleid();
const otIp6Address* ipaddr_rloc();
OTIpmaddrIterator ipmaddr();
otError ipmaddr_add(const otIp6Address*);
otError ipmaddr_del(const otIp6Address*);
bool ipmaddr_promiscuous();
void ipmaddr_promiscuous(bool);

#if OPENTHREAD_CONFIG_JOINER_ENABLE
void joiner_id(otExtAddress*);
const otExtAddress* joiner_id();
otError joiner_start(const char*, const char*, otJoinerCallback, void*);
otError joiner_start(const char*, const char* provision=NULL);
void joiner_stop();
#endif // OPENTHREAD_CONFIG_JOINER_ENABLE
#if OPENTHREAD_FTD
uint16_t joinerport();
#endif
uint32_t keysequence_counter();
void keysequence_counter(uint32_t);
uint32_t keysequence_guardtime();
void  keysequence_guardtime(uint32_t);
otError leaderdata(otLeaderData*);
#if OPENTHREAD_FTD
uint32_t leaderpartitionid();
void leaderpartitionid(uint32_t);
uint8_t leaderweight();
void leaderweight(uint8_t);
#endif // OPENTHREAD_FTD
const otMasterKey* masterkey();
otError masterkey(const otMasterKey*);
otLinkModeConfig mode();
otError mode(otLinkModeConfig);
#if OPENTHREAD_FTD
OTNeighborIterator neighbor();


#endif
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE || OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError netdataregister();
#endif // OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE || OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError netdatashow(uint8_t*, uint8_t&);

#if OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE
otError service_add(uint32_t, uint8_t*, uint8_t, uint8_t*, uint8_t);
otError service_add(uint32_t, const char*, const char*);
otError service_remove(uint32_t, uint8_t*, uint8_t);
otError service_remove(uint32_t, const char*);
#endif

#if OPENTHREAD_FTD || OPENTHREAD_CONFIG_TMF_NETWORK_DIAG_MTD_ENABLE
otError networkdiagnostic_get(const otIp6Address*, uint8_t*, uint8_t);
otError networkdiagnostic_reset(const otIp6Address*, uint8_t*, uint8_t);
#endif // OPENTHREAD_FTD || OPENTHREAD_CONFIG_TMF_NETWORK_DIAG_MTD_ENABLE
#if OPENTHREAD_FTD
void networkidtimeout(uint8_t);
uint8_t networkidtimeout();
#endif // OPENTHREAD_FTD
const char* networkname();
otError networkname(const char*);
#if OPENTHREAD_CONFIG_TIME_SYNC_ENABLE
otNetworkTimeStatus networktime();
otError networktime(uint16_t, uint16_t);
#endif // OPENTHREAD_CONFIG_TIME_SYNC_ENABLE
uint16_t panid();
otError panid(uint16_t);
otError parent(otRouterInfo*);
#if OPENTHREAD_FTD
uint8_t parentpriority();
otError parentpriority(uint8_t);
#endif
otError ping(const otIp6Address*, const uint8_t*, uint16_t);
otError ping_stop();
uint32_t pollperiod();
otError pollperiod(uint32_t);
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
OTPrefixIterator prefix();
otError _prefix_add(const otBorderRouterConfig*);
otError prefix_add(const otIp6Prefix*, otRoutePreference, bool, bool, bool, bool, bool, bool, bool);
otError prefix_remove(const otIp6Prefix*);
#endif // OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
bool promiscuous();
otError promiscuous_enable(otLinkPcapCallback, void* ctx);
otError promiscuous_disable();
#if OPENTHREAD_FTD
otError preferrouterid(uint8_t);
const otPskc* pskc();
otError pskc(const otPskc*);
otError pskc_passphrase(const char*);
otError releaserouterid(uint8_t);
#endif // OPENTHREAD_FTD
void reset();
#if OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
OTRouteIterator route();
otError route_add(const otExternalRouteConfig*);
otError route_add(otRoutePreference, bool);
otError route_remove(const otIp6Prefix*);
#endif // OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE
#if OPENTHREAD_FTD
OTRouterIterator router();
otError router(int, otRouterInfo*);
uint8_t routerdowngradethreshold();
void routerdowngradethreshold(uint8_t);
bool routereligible();
otError routereligible_enable();
otError routereligible_disable();
uint8_t routerselectionjitter();
void routerselectionjitter(uint8_t);
uint8_t routerupgradethreshold();
void routerupgradethreshold(uint8_t);
#endif // OPENTHREAD_FTD
uint16_t rloc16();
otError scan(uint16_t, uint32_t, otHandleActiveScanResult, void*);
otError scan_energy(uint16_t, uint32_t, otHandleEnergyScanResult, void*);
bool singleton();
#if OPENTHREAD_CONFIG_SNTP_CLIENT_ENABLE
otError sntp_query(const otIp6Address*, uint16_t, otSntpResponseHandler, void*);
#endif
otDeviceRole state();
otError state(otDeviceRole);
otError state_child();
otError state_detached();
#if OPENTHREAD_FTD
otError state_router();
otError state_leader();
#endif // OPENTHREAD_FTD
bool thread();
otError _thread(bool);
otError thread_start();
otError thread_stop();
uint16_t thread_version();
int8_t txpower();
otError txpower(int8_t);
otError _txpower(int8_t*);
const char* version();

uint8_t mac_retries_direct();
void mac_retries_direct(uint8_t);
uint8_t mac_retries_indirect();
void mac_retries_indirect(uint8_t);
#if OPENTHREAD_CONFIG_MAC_FILTER_ENABLE
OTMacfilterIterator macfilter();
void _macfilter_addr_mode(otMacFilterAddressMode);
otMacFilterAddressMode _macfilter_addr_mode();
OTMacfilterAddrIterator macfilter_addr();
void macfilter_addr_disable();
void macfilter_addr_whitelist();
void macfilter_addr_blacklist();
otError macfilter_addr_add(const otExtAddress*, uint8_t);
otError macfilter_addr_add(uint8_t);
otError macfilter_addr_remove(const otExtAddress*);
void macfilter_addr_clear();
OTMacfilterRssIterator macfilter_rss();
otError macfilter_rss_add(const otExtAddress*, uint8_t);
otError macfilter_rss_add(uint8_t);
otError macfilter_rss_add_lqi(const otExtAddress*, uint8_t);
otError macfilter_rss_add_lqi(uint8_t);
otError macfilter_rss_remove(const otExtAddress* a=nullptr);
void macfilter_rss_clear();
#endif // OPENTHREAD_CONFIG_MAC_FILTER_ENABLE

/* 
// help
noimpl help();
noimpl coap_help();
noimpl coaps_help();
noimpl dataset_help();
noimpl joiner_help();
noimpl udp_help();
noimpl commissioner_help();

//updsend -?
noimpl udp_send_s();
noimpl udp_send_x();
noimpl udp_send_t();

noimpl pskc_p();
noimpl dataset_pskc_p();

// list/table
noimpl child_list();
noimpl neighbor_list();
noimpl router_list();
noimpl child_table();
noimpl neighbor_table();
noimpl router_table();

// array args
noimpl prefix_add_high();
noimpl prefix_add_low();
noimpl prefix_add_med();
noimpl route_add_high();
noimpl route_add_low();
noimpl route_add_med();
noimpl route_add_s();
noimpl dataset_mgmtgetcommand_activetimestamp();
noimpl dataset_mgmtgetcommand_address();
noimpl dataset_mgmtgetcommand_binary();
noimpl dataset_mgmtgetcommand_channel();
noimpl dataset_mgmtgetcommand_delaytimer();
noimpl dataset_mgmtgetcommand_extpanid();
noimpl dataset_mgmtgetcommand_localprefix();
noimpl dataset_mgmtgetcommand_masterkey();
noimpl dataset_mgmtgetcommand_networkname();
noimpl dataset_mgmtgetcommand_panid();
noimpl dataset_mgmtgetcommand_pendingtimestamp();
noimpl dataset_mgmtsetcommand_activetimestamp();
noimpl dataset_mgmtsetcommand_binary();
noimpl dataset_mgmtsetcommand_channel();
noimpl dataset_mgmtsetcommand_channelmask();
noimpl dataset_mgmtsetcommand_delaytimer();
noimpl dataset_mgmtsetcommand_extpanid();
noimpl dataset_mgmtsetcommand_localprefix();
noimpl dataset_mgmtsetcommand_masterkey();
noimpl dataset_mgmtsetcommand_networkname();
noimpl dataset_mgmtsetcommand_panid();
noimpl dataset_mgmtsetcommand_pendingtimestamp();
noimpl commissioner_mgmtget_binary();
noimpl commissioner_mgmtget_joinerudpport();
noimpl commissioner_mgmtget_locator();
noimpl commissioner_mgmtget_sessionid();
noimpl commissioner_mgmtget_steeringdata();
noimpl commissioner_mgmtset_binary();
noimpl commissioner_mgmtset_joinerudpport();
noimpl commissioner_mgmtset_locator();
noimpl commissioner_mgmtset_sessionid();
noimpl commissioner_mgmtset_steeringdata();

// need args
noimpl dns();
noimpl mac();
noimpl service();
noimpl sntp();
noimpl keysequence();
noimpl networkdiagnostic();
noimpl dataset_init();
noimpl dataset_commit();
noimpl dataset_mgmtgetcommand();
noimpl dataset_mgmtsetcommand();
noimpl commissioner_joiner();
noimpl coap_parameters();

// misparse
noimpl commissioner_joiner_*();
noimpl coap_parameters_response_default();

noimpl coaps_put_delete();
noimpl coaps_put_delete_con();
noimpl coaps_put_get();
noimpl coaps_put_post();
noimpl coaps_put_put();
noimpl coaps_start_true();
noimpl coaps_start_false();

noimpl coap_put_delete();
noimpl coap_put_delete_con();
noimpl coap_put_get();
noimpl coap_put_observe();
noimpl coap_put_post();
noimpl coap_put_put();

noimpl bbr_config_delay();
noimpl bbr_config_seqno();
noimpl bbr_config_timeout();

noimpl counters();

*/
}


#endif //OTCMD_H__
