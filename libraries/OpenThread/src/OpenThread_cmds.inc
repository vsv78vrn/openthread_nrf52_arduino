#if 0
  struct {
    struct {
      void operator()() const { return OTCMD::bbr_enable(); }
    } enable;
    struct {
      void operator()() const { return OTCMD::bbr_disable(); }
    } disable;
    struct {
      otError operator()(uint8_t a0, uint16_t a1, uint32_t a2) { return OTCMD::bbr_config(a0, a1, a2); }
    } config;
    struct {
      uint8_t operator()() const { return OTCMD::bbr_jitter(); }
      void operator()(uint8_t a0) { return OTCMD::bbr_jitter(a0); }
    } jitter;
    struct {
      otError operator()() const { return OTCMD::bbr_register(); }
    } _register;
    struct {
      otBackboneRouterState operator()() const { return OTCMD::bbr_state(); }
    } state;
    otError operator()(otBackboneRouterConfig& a0) { return OTCMD::bbr(a0); }
  } bbr;
#endif
  struct {
    void operator()(otBufferInfo* a0) { return OTCMD::bufferinfo(a0); }
  } bufferinfo;
  struct {
    uint8_t operator()() const { return OTCMD::channel(); }
    otError operator()(uint8_t a0) { return OTCMD::channel(a0); }
    struct {
      uint32_t operator()() const { return OTCMD::channel_supported(); }
    } supported;
    struct {
      uint32_t operator()() const { return OTCMD::channel_preferred(); }
    } preferred;
#if 0
    struct {
      otError operator()() const { return OTCMD::channel_monitor(); }
    } monitor;
    struct {
      otError operator()() const { return OTCMD::channel_manager(); }
      struct {
        otError operator()(uint32_t a0) { return OTCMD::channel_manager_favored(a0); }
      } favored;
    } manager;
#endif
  } channel;
  struct {
    otError operator()(int a0, otChildInfo* a1) { return OTCMD::child(a0, a1); }
  } child;
  struct {
    struct {
      uint8_t operator()() const { return OTCMD::childip_max(); }
#if 0
      void operator()(uint8_t a0) { return OTCMD::childip_max(a0); }
#endif
    } max;
  } childip;
  struct {
    uint8_t operator()() const { return OTCMD::childmax(); }
    otError operator()(uint8_t a0) { return OTCMD::childmax(a0); }
  } childmax;
  struct {
    uint32_t operator()() const { return OTCMD::childtimeout(); }
    void operator()(uint32_t a0) { return OTCMD::childtimeout(a0); }
  } childtimeout;
#if 0
  struct {
    bool operator()() const { return OTCMD::coex(); }
    void operator()(bool a0) { return OTCMD::coex(a0); }
    struct {
      otError operator()(otRadioCoexMetrics& a0) { return OTCMD::coex_metrics(a0); }
    } metrics;
  } coex;
#endif
  struct {
    otCommissionerState operator()() const { return OTCMD::commissioner(); }
    struct {
      otError operator()(uint32_t a0, uint8_t a1, uint16_t a2, IPAddress& a3) { return OTCMD::commissioner_announce(a0, a1, a2, a3); }
    } announce;
    struct {
      otError operator()(uint32_t a0, uint8_t a1, uint16_t a2, uint16_t a3, IPAddress& a4, otCommissionerEnergyReportCallback a5, void* a6) { return OTCMD::commissioner_energy(a0, a1, a2, a3, a4, a5, a6); }
    } energy;
    struct {
      otError operator()(otMeshcopTlvType* a0, uint8_t a1) { return OTCMD::commissioner_mgmtget(a0, a1); }
    } mgmtget;
    struct {
      otError operator()(uint32_t a0, uint32_t a1, uint32_t a2, uint8_t* a3, uint8_t a4, otMeshcopTlvType* a5, uint8_t a6) { return OTCMD::commissioner_mgmtset(a0, a1, a2, a3, a4, a5, a6); }
    } mgmtset;
    struct {
      otError operator()(uint16_t a0, uint32_t a1, IPAddress& a2, otCommissionerPanIdConflictCallback a3, void* a4) { return OTCMD::commissioner_panid(a0, a1, a2, a3, a4); }
    } panid;
    struct {
      otError operator()(const char* a0) { return OTCMD::commissioner_provisioningurl(a0); }
    } provisioningurl;
    struct {
      uint16_t operator()() const { return OTCMD::commissioner_sessionid(); }
    } sessionid;
    struct {
      otError operator()(otCommissionerStateCallback a0, otCommissionerJoinerCallback a1, void* a2) { return OTCMD::commissioner_start(a0, a1, a2); }
    } start;
    struct {
      otError operator()() const { return OTCMD::commissioner_stop(); }
    } stop;
  } commissioner;
  struct {
    void operator()(uint32_t a0) { return OTCMD::contextreusedelay(a0); }
    uint32_t operator()() const { return OTCMD::contextreusedelay(); }
  } contextreusedelay;
  struct {
    struct {
      const otMacCounters* operator()() const { return OTCMD::counters_mac(); }
      struct {
        void operator()() const { return OTCMD:: counters_mac_reset(); }
      } reset;
    } mac;
    struct {
      const otMleCounters* operator()() const { return OTCMD::counters_mle(); }
      struct {
        void operator()() const { return OTCMD:: counters_mle_reset(); }
      } reset;
    } mle;
  }  counters;
  struct {
    uint32_t operator()() const { return OTCMD::delaytimermin(); }
    otError operator()(uint32_t a0) { return OTCMD::delaytimermin(a0); }
  } delaytimermin;
  struct {
    otError operator()(uint8_t a0, char** a1, char* a2, size_t a3) { return OTCMD::diag(a0, a1, a2, a3); }
  } diag;
  struct {
    otError operator()(uint32_t a0, otHandleActiveScanResult a1, void* a2) { return OTCMD::discover(a0, a1, a2); }
  } discover;
  struct {
    struct {
      otError operator()(const char* a0, const otIp6Address* a1, uint16_t a2, otDnsResponseHandler a3, void* a4) { return OTCMD::dns_resolve(a0, a1, a2, a3, a4); }
      otError operator()(const char* a0, otDnsResponseHandler a1, void* a2) { return OTCMD::dns_resolve(a0, a1, a2); }
    } resolve;
  } dns;
  struct {
    const OTExtAddress operator()() const { return OTCMD::eui64(); }
  } eui64;
#if 0
  struct {
    otError operator()(uint8_t a0, char** a1) { return OTCMD::exit(a0, a1); }
  } exit;
  struct {
    void operator()(const char* a0) { return OTCMD::logfilename(a0); }
  } logfilename;
#endif
  struct {
    OTExtAddress operator()() const { return OTCMD::extaddr(); }
    otError operator()(OTExtAddress a0) { return OTCMD::extaddr(a0); }
  } extaddr;
  struct {
    OTExtendedPanId operator()() const { return OTCMD::extpanid(); }
    otError operator()(OTExtendedPanId a0) { return OTCMD::extpanid(a0); }
  } extpanid;
  struct {
    void operator()() const { return OTCMD::factoryreset(); }
  } factoryreset;
  struct {
    bool operator()() const { return OTCMD::ifconfig(); }
    struct {
      otError operator()() const { return OTCMD::ifconfig_up(); }
    } up;
    struct {
      otError operator()() const { return OTCMD::ifconfig_down(); }
    } down;
  } ifconfig;
  struct {
    struct {
      otError operator()(const otIp6Address* a0, uint8_t a1, bool a2, bool a3, bool a4, uint32_t a5, bool a6) { return OTCMD::ipaddr_add(a0, a1, a2, a3, a4, a5, a6); }
    } add;
    struct {
      otError operator()(const otIp6Address* a0) { return OTCMD::ipaddr_del(a0); }
    } del;
    struct {
      const otIp6Address* operator()() const { return OTCMD::ipaddr_linklocal(); }
    } linklocal;
    struct {
      const otIp6Address* operator()() const { return OTCMD::ipaddr_mleid(); }
    } mleid;
    struct {
      const otIp6Address* operator()() const { return OTCMD::ipaddr_rloc(); }
    } rloc;
  } ipaddr;
  struct {
    struct {
      otError operator()(const otIp6Address* a0) { return OTCMD::ipmaddr_add(a0); }
    } add;
    struct {
      otError operator()(const otIp6Address* a0) { return OTCMD::ipmaddr_del(a0); }
    } del;
    struct {
      bool operator()() const { return OTCMD::ipmaddr_promiscuous(); }
      void operator()(bool a0) { return OTCMD::ipmaddr_promiscuous(a0); }
    } promiscuous;
  } ipmaddr;
  struct {
    struct {
      const OTExtAddress operator()() const { return OTCMD::joiner_id(); }
    } id;
    struct {
      otError operator()(const char* a0, const char* a1, otJoinerCallback a2, void* a3) { return OTCMD::joiner_start(a0, a1, a2, a3); }
      otError operator()(const char* a0, const char* a1=NULL) { return OTCMD::joiner_start(a0, a1); }
    } start;
    struct {
      void operator()() const { return OTCMD::joiner_stop(); }
    } stop;
  } joiner;
  struct {
    uint16_t operator()() const { return OTCMD::joinerport(); }
  } joinerport;
  struct {
    struct {
      uint32_t operator()() const { return OTCMD::keysequence_counter(); }
      void operator()(uint32_t a0) { return OTCMD::keysequence_counter(a0); }
    } counter;
    struct {
      uint32_t operator()() const { return OTCMD::keysequence_guardtime(); }
      void operator()(uint32_t a0) { return OTCMD:: keysequence_guardtime(a0); }
    } guardtime;
  }  keysequence;
  struct {
    otError operator()(otLeaderData* a0) { return OTCMD::leaderdata(a0); }
  } leaderdata;
  struct {
    uint32_t operator()() const { return OTCMD::leaderpartitionid(); }
    void operator()(uint32_t a0) { return OTCMD::leaderpartitionid(a0); }
  } leaderpartitionid;
  struct {
    uint8_t operator()() const { return OTCMD::leaderweight(); }
    void operator()(uint8_t a0) { return OTCMD::leaderweight(a0); }
  } leaderweight;
  struct {
    struct {
      struct {
        void operator()(uint8_t a0) { return OTCMD::mac_retries_indirect(a0); }
      } indirect;
    } retries;
  } mac;
  struct {
    struct {
      struct {
        void operator()() const { return OTCMD::macfilter_addr_whitelist(); }
      } whitelist;
    } addr;
    struct {
      struct {
        otError operator()(const otExtAddress* a0=nullptr) { return OTCMD::macfilter_rss_remove(a0); }
      } remove;
    } rss;
  } macfilter;
  struct {
    OTMasterKey operator()() const { return OTCMD::masterkey(); }
    otError operator()(OTMasterKey a0) { return OTCMD::masterkey(a0); }
  } masterkey;
  struct {
    otLinkModeConfig operator()() const { return OTCMD::mode(); }
    otError operator()(otLinkModeConfig a0) { return OTCMD::mode(a0); }
  } mode;
  struct {
    otError operator()() const { return OTCMD::netdataregister(); }
  } netdataregister;
  struct {
    otError operator()(uint8_t* a0, uint8_t& a1) { return OTCMD::netdatashow(a0, a1); }
  } netdatashow;
  struct {
    struct {
      otError operator()(const otIp6Address* a0, uint8_t* a1, uint8_t a2) { return OTCMD::networkdiagnostic_get(a0, a1, a2); }
    } get;
    struct {
      otError operator()(const otIp6Address* a0, uint8_t* a1, uint8_t a2) { return OTCMD::networkdiagnostic_reset(a0, a1, a2); }
    } reset;
  } networkdiagnostic;
  struct {
    void operator()(uint8_t a0) { return OTCMD::networkidtimeout(a0); }
    uint8_t operator()() const { return OTCMD::networkidtimeout(); }
  } networkidtimeout;
  struct {
    const char* operator()() const { return OTCMD::networkname(); }
    otError operator()(const char* a0) { return OTCMD::networkname(a0); }
  } networkname;
#if 0
  struct {
    otNetworkTimeStatus operator()() const { return OTCMD::networktime(); }
    otError operator()(uint16_t a0, uint16_t a1) { return OTCMD::networktime(a0, a1); }
  } networktime;
#endif
  struct {
    uint16_t operator()() const { return OTCMD::panid(); }
    otError operator()(uint16_t a0) { return OTCMD::panid(a0); }
  } panid;
  struct {
    otError operator()(otRouterInfo* a0) { return OTCMD::parent(a0); }
  } parent;
  struct {
    uint8_t operator()() const { return OTCMD::parentpriority(); }
    otError operator()(uint8_t a0) { return OTCMD::parentpriority(a0); }
  } parentpriority;
  struct {
    otError operator()(const otIp6Address* a0, const uint8_t* a1, uint16_t a2) { return OTCMD::ping(a0, a1, a2); }
    struct {
      otError operator()() const { return OTCMD::ping_stop(); }
    } stop;
  } ping;
  struct {
    uint32_t operator()() const { return OTCMD::pollperiod(); }
    otError operator()(uint32_t a0) { return OTCMD::pollperiod(a0); }
  } pollperiod;
  struct {
    bool operator()() const { return OTCMD::promiscuous(); }
    struct {
      otError operator()(otLinkPcapCallback a0, void* a1) { return OTCMD::promiscuous_enable(a0, a1); }
    } enable;
    struct {
      otError operator()() const { return OTCMD::promiscuous_disable(); }
    } disable;
  } promiscuous;
  struct {
    struct {
      otError operator()(const otIp6Prefix* a0, otRoutePreference a1, bool a2, bool a3, bool a4, bool a5, bool a6, bool a7, bool a8) { return OTCMD::prefix_add(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
    } add;
    struct {
      otError operator()(const otIp6Prefix* a0) { return OTCMD::prefix_remove(a0); }
    } remove;
  } prefix;
  struct {
    otError operator()(uint8_t a0) { return OTCMD::preferrouterid(a0); }
  } preferrouterid;
  struct {
    const otPskc* operator()() const { return OTCMD::pskc(); }
    otError operator()(const otPskc* a0) { return OTCMD::pskc(a0); }
    struct {
      otError operator()(const char* a0) { return OTCMD::pskc_passphrase(a0); }
    } passphrase;
  } pskc;
  struct {
    otError operator()(uint8_t a0) { return OTCMD::releaserouterid(a0); }
  } releaserouterid;
  struct {
    void operator()() const { return OTCMD::reset(); }
  } reset;
  struct {
    uint16_t operator()() const { return OTCMD::rloc16(); }
  } rloc16;
  struct {
    struct {
      otError operator()(const otExternalRouteConfig* a0) { return OTCMD::route_add(a0); }
      otError operator()(otRoutePreference a0, bool a1) { return OTCMD::route_add(a0, a1); }
    } add;
    struct {
      otError operator()(const otIp6Prefix* a0) { return OTCMD::route_remove(a0); }
    } remove;
  } route;
  struct {
    otError operator()(int a0, otRouterInfo* a1) { return OTCMD::router(a0, a1); }
  } router;
  struct {
    uint8_t operator()() const { return OTCMD::routerdowngradethreshold(); }
    void operator()(uint8_t a0) { return OTCMD::routerdowngradethreshold(a0); }
  } routerdowngradethreshold;
  struct {
    bool operator()() const { return OTCMD::routereligible(); }
    struct {
      otError operator()() const { return OTCMD::routereligible_enable(); }
    } enable;
    struct {
      otError operator()() const { return OTCMD::routereligible_disable(); }
    } disable;
  } routereligible;
  struct {
    uint8_t operator()() const { return OTCMD::routerselectionjitter(); }
    void operator()(uint8_t a0) { return OTCMD::routerselectionjitter(a0); }
  } routerselectionjitter;
  struct {
    uint8_t operator()() const { return OTCMD::routerupgradethreshold(); }
    void operator()(uint8_t a0) { return OTCMD::routerupgradethreshold(a0); }
  } routerupgradethreshold;
  struct {
    otError operator()(uint16_t a0, uint32_t a1, otHandleActiveScanResult a2, void* a3) { return OTCMD::scan(a0, a1, a2, a3); }
    struct {
      otError operator()(uint16_t a0, uint32_t a1, otHandleEnergyScanResult a2, void* a3) { return OTCMD::scan_energy(a0, a1, a2, a3); }
    } energy;
  } scan;
  struct {
    struct {
      otError operator()(uint32_t a0, uint8_t* a1, uint8_t a2, uint8_t* a3, uint8_t a4) { return OTCMD::service_add(a0, a1, a2, a3, a4); }
      otError operator()(uint32_t a0, const char* a1, const char* a2) { return OTCMD::service_add(a0, a1, a2); }
    } add;
    struct {
      otError operator()(uint32_t a0, uint8_t* a1, uint8_t a2) { return OTCMD::service_remove(a0, a1, a2); }
      otError operator()(uint32_t a0, const char* a1) { return OTCMD::service_remove(a0, a1); }
    } remove;
  } service;
  struct {
    bool operator()() const { return OTCMD::singleton(); }
  } singleton;
  struct {
    struct {
      otError operator()(const otIp6Address* a0, uint16_t a1, otSntpResponseHandler a2, void* a3) { return OTCMD::sntp_query(a0, a1, a2, a3); }
    } query;
  } sntp;
  struct {
    otError operator()(otDeviceRole a0) { return OTCMD::state(a0); }
    otDeviceRole operator()() const { return OTCMD::state(); }
    struct {
      otError operator()() const { return OTCMD::state_child(); }
    } child;
    struct {
      otError operator()() const { return OTCMD::state_detached(); }
    } detached;
    struct {
      otError operator()() const { return OTCMD::state_router(); }
    } router;
    struct {
      otError operator()() const { return OTCMD::state_leader(); }
    } leader;
  } state;
  struct {
    bool operator()() const { return OTCMD::thread(); }
    struct {
      otError operator()() const { return OTCMD::thread_start(); }
    } start;
    struct {
      otError operator()() const { return OTCMD::thread_stop(); }
    } stop;
    struct {
      uint16_t operator()() const { return OTCMD::thread_version(); }
    } version;
  } thread;
  struct {
    int8_t operator()() const { return OTCMD::txpower(); }
    otError operator()(int8_t a0) { return OTCMD::txpower(a0); }
  } txpower;
  struct {
    const char* operator()() const { return OTCMD::version(); }
  } version;


