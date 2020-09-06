cmdtable = {
'CoapSecure::ProcessBackboneRouter' =>"bbr",
'CoapSecure::ProcessBufferInfo' =>"bufferinfo",
'CoapSecure::ProcessChannel' =>"channel",
'CoapSecure::ProcessChild' =>"child",
'CoapSecure::ProcessChildIp' =>"childip",
'CoapSecure::ProcessChildMax' =>"childmax",
'CoapSecure::ProcessChildTimeout' =>"childtimeout",
'CoapSecure::ProcessCoap' =>"coap",
'CoapSecure::ProcessCoapSecure' =>"coaps",
'CoapSecure::ProcessCoexMetrics' =>"coex",
'CoapSecure::ProcessCommissioner' =>"commissioner",
'CoapSecure::ProcessContextIdReuseDelay' =>"contextreusedelay",
'CoapSecure::ProcessCounters' =>"counters",
'CoapSecure::ProcessDataset' =>"dataset",
'CoapSecure::ProcessDelayTimerMin' =>"delaytimermin",
'CoapSecure::ProcessDiag' =>"diag",
'CoapSecure::ProcessDiscover' =>"discover",
'CoapSecure::ProcessDns' =>"dns",
'CoapSecure::ProcessEidCache' =>"eidcache",
'CoapSecure::ProcessEui64' =>"eui64",
'CoapSecure::ProcessExit' =>"exit",
'CoapSecure::ProcessLogFilename' =>"logfilename",
'CoapSecure::ProcessExtAddress' =>"extaddr",
'CoapSecure::ProcessExtPanId' =>"extpanid",
'CoapSecure::ProcessFactoryReset' =>"factoryreset",
'CoapSecure::ProcessHelp' =>"help",
'CoapSecure::ProcessIfconfig' =>"ifconfig",
'CoapSecure::ProcessIpAddr' =>"ipaddr",
'CoapSecure::ProcessIpMulticastAddr' =>"ipmaddr",
'CoapSecure::ProcessJoiner' =>"joiner",
'CoapSecure::ProcessJoinerPort' =>"joinerport",
'CoapSecure::ProcessKeySequence' =>"keysequence",
'CoapSecure::ProcessLeaderData' =>"leaderdata",
'CoapSecure::ProcessLeaderPartitionId' =>"leaderpartitionid",
'CoapSecure::ProcessLeaderWeight' =>"leaderweight",
'CoapSecure::ProcessMac' =>"mac",
'CoapSecure::ProcessMacFilter' =>"macfilter",
'CoapSecure::ProcessMasterKey' =>"masterkey",
'CoapSecure::ProcessMode' =>"mode",
'CoapSecure::ProcessNeighbor' =>"neighbor",
'CoapSecure::ProcessNetworkDataRegister' =>"netdataregister",
'CoapSecure::ProcessNetworkDataShow' =>"netdatashow",
'CoapSecure::ProcessNetworkDiagnostic' =>"networkdiagnostic",
'CoapSecure::ProcessNetworkIdTimeout' =>"networkidtimeout",
'CoapSecure::ProcessNetworkName' =>"networkname",
'CoapSecure::ProcessNetworkTime' =>"networktime",
'CoapSecure::ProcessPanId' =>"panid",
'CoapSecure::ProcessParent' =>"parent",
'CoapSecure::ProcessParentPriority' =>"parentpriority",
'CoapSecure::ProcessPing' =>"ping",
'CoapSecure::ProcessPollPeriod' =>"pollperiod",
'CoapSecure::ProcessPromiscuous' =>"promiscuous",
'CoapSecure::ProcessPrefix' =>"prefix",
'CoapSecure::ProcessPreferRouterId' =>"preferrouterid",
'CoapSecure::ProcessPskc' =>"pskc",
'CoapSecure::ProcessReleaseRouterId' =>"releaserouterid",
'CoapSecure::ProcessReset' =>"reset",
'CoapSecure::ProcessRloc16' =>"rloc16",
'CoapSecure::ProcessRoute' =>"route",
'CoapSecure::ProcessRouter' =>"router",
'CoapSecure::ProcessRouterDowngradeThreshold' =>"routerdowngradethreshold",
'CoapSecure::ProcessRouterEligible' =>"routereligible",
'CoapSecure::ProcessRouterSelectionJitter' =>"routerselectionjitter",
'CoapSecure::ProcessRouterUpgradeThreshold' =>"routerupgradethreshold",
'CoapSecure::ProcessScan' =>"scan",
'CoapSecure::ProcessService' =>"service",
'CoapSecure::ProcessSingleton' =>"singleton",
'CoapSecure::ProcessSntp' =>"sntp",
'CoapSecure::ProcessState' =>"state",
'CoapSecure::ProcessThread' =>"thread",
'CoapSecure::ProcessTxPower' =>"txpower",
'CoapSecure::ProcessUdp' =>"udp",
'CoapSecure::ProcessVersion' =>"version",
};


readlines.each do |line|

  if line =~ /[^&]CoapSecure::Process/ or line =~ /strcmp/
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
