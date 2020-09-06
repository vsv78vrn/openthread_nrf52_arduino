cmdtable = {
'Coap::ProcessBackboneRouter' =>"bbr",
'Coap::ProcessBufferInfo' =>"bufferinfo",
'Coap::ProcessChannel' =>"channel",
'Coap::ProcessChild' =>"child",
'Coap::ProcessChildIp' =>"childip",
'Coap::ProcessChildMax' =>"childmax",
'Coap::ProcessChildTimeout' =>"childtimeout",
'Coap::ProcessCoap' =>"coap",
'Coap::ProcessCoapSecure' =>"coaps",
'Coap::ProcessCoexMetrics' =>"coex",
'Coap::ProcessCommissioner' =>"commissioner",
'Coap::ProcessContextIdReuseDelay' =>"contextreusedelay",
'Coap::ProcessCounters' =>"counters",
'Coap::ProcessDataset' =>"dataset",
'Coap::ProcessDelayTimerMin' =>"delaytimermin",
'Coap::ProcessDiag' =>"diag",
'Coap::ProcessDiscover' =>"discover",
'Coap::ProcessDns' =>"dns",
'Coap::ProcessEidCache' =>"eidcache",
'Coap::ProcessEui64' =>"eui64",
'Coap::ProcessExit' =>"exit",
'Coap::ProcessLogFilename' =>"logfilename",
'Coap::ProcessExtAddress' =>"extaddr",
'Coap::ProcessExtPanId' =>"extpanid",
'Coap::ProcessFactoryReset' =>"factoryreset",
'Coap::ProcessHelp' =>"help",
'Coap::ProcessIfconfig' =>"ifconfig",
'Coap::ProcessIpAddr' =>"ipaddr",
'Coap::ProcessIpMulticastAddr' =>"ipmaddr",
'Coap::ProcessJoiner' =>"joiner",
'Coap::ProcessJoinerPort' =>"joinerport",
'Coap::ProcessKeySequence' =>"keysequence",
'Coap::ProcessLeaderData' =>"leaderdata",
'Coap::ProcessLeaderPartitionId' =>"leaderpartitionid",
'Coap::ProcessLeaderWeight' =>"leaderweight",
'Coap::ProcessMac' =>"mac",
'Coap::ProcessMacFilter' =>"macfilter",
'Coap::ProcessMasterKey' =>"masterkey",
'Coap::ProcessMode' =>"mode",
'Coap::ProcessNeighbor' =>"neighbor",
'Coap::ProcessNetworkDataRegister' =>"netdataregister",
'Coap::ProcessNetworkDataShow' =>"netdatashow",
'Coap::ProcessNetworkDiagnostic' =>"networkdiagnostic",
'Coap::ProcessNetworkIdTimeout' =>"networkidtimeout",
'Coap::ProcessNetworkName' =>"networkname",
'Coap::ProcessNetworkTime' =>"networktime",
'Coap::ProcessPanId' =>"panid",
'Coap::ProcessParent' =>"parent",
'Coap::ProcessParentPriority' =>"parentpriority",
'Coap::ProcessPing' =>"ping",
'Coap::ProcessPollPeriod' =>"pollperiod",
'Coap::ProcessPromiscuous' =>"promiscuous",
'Coap::ProcessPrefix' =>"prefix",
'Coap::ProcessPreferRouterId' =>"preferrouterid",
'Coap::ProcessPskc' =>"pskc",
'Coap::ProcessReleaseRouterId' =>"releaserouterid",
'Coap::ProcessReset' =>"reset",
'Coap::ProcessRloc16' =>"rloc16",
'Coap::ProcessRoute' =>"route",
'Coap::ProcessRouter' =>"router",
'Coap::ProcessRouterDowngradeThreshold' =>"routerdowngradethreshold",
'Coap::ProcessRouterEligible' =>"routereligible",
'Coap::ProcessRouterSelectionJitter' =>"routerselectionjitter",
'Coap::ProcessRouterUpgradeThreshold' =>"routerupgradethreshold",
'Coap::ProcessScan' =>"scan",
'Coap::ProcessService' =>"service",
'Coap::ProcessSingleton' =>"singleton",
'Coap::ProcessSntp' =>"sntp",
'Coap::ProcessState' =>"state",
'Coap::ProcessThread' =>"thread",
'Coap::ProcessTxPower' =>"txpower",
'Coap::ProcessUdp' =>"udp",
'Coap::ProcessVersion' =>"version",
};


readlines.each do |line|

  if line =~ /[^&]Coap::Process/ or line =~ /strcmp/
    line.gsub!(/^.*strcmp.*"([^"]*)".*/, "\t" + '\1')
    line.gsub!(/\(.*$/, '')
    line.gsub!(/^.* /, '')
    if cmdtable[line.strip] != nil
      line = cmdtable[line.strip]
      line += "\n"
    end
    print line
  end


end
