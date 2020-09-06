cmdtable = {
'Commissioner::ProcessBackboneRouter' =>"bbr",
'Commissioner::ProcessBufferInfo' =>"bufferinfo",
'Commissioner::ProcessChannel' =>"channel",
'Commissioner::ProcessChild' =>"child",
'Commissioner::ProcessChildIp' =>"childip",
'Commissioner::ProcessChildMax' =>"childmax",
'Commissioner::ProcessChildTimeout' =>"childtimeout",
'Commissioner::ProcessCoap' =>"coap",
'Commissioner::ProcessCoapSecure' =>"coaps",
'Commissioner::ProcessCoexMetrics' =>"coex",
'Commissioner::ProcessCommissioner' =>"commissioner",
'Commissioner::ProcessContextIdReuseDelay' =>"contextreusedelay",
'Commissioner::ProcessCounters' =>"counters",
'Commissioner::ProcessDataset' =>"dataset",
'Commissioner::ProcessDelayTimerMin' =>"delaytimermin",
'Commissioner::ProcessDiag' =>"diag",
'Commissioner::ProcessDiscover' =>"discover",
'Commissioner::ProcessDns' =>"dns",
'Commissioner::ProcessEidCache' =>"eidcache",
'Commissioner::ProcessEui64' =>"eui64",
'Commissioner::ProcessExit' =>"exit",
'Commissioner::ProcessLogFilename' =>"logfilename",
'Commissioner::ProcessExtAddress' =>"extaddr",
'Commissioner::ProcessExtPanId' =>"extpanid",
'Commissioner::ProcessFactoryReset' =>"factoryreset",
'Commissioner::ProcessHelp' =>"help",
'Commissioner::ProcessIfconfig' =>"ifconfig",
'Commissioner::ProcessIpAddr' =>"ipaddr",
'Commissioner::ProcessIpMulticastAddr' =>"ipmaddr",
'Commissioner::ProcessJoiner' =>"joiner",
'Commissioner::ProcessJoinerPort' =>"joinerport",
'Commissioner::ProcessKeySequence' =>"keysequence",
'Commissioner::ProcessLeaderData' =>"leaderdata",
'Commissioner::ProcessLeaderPartitionId' =>"leaderpartitionid",
'Commissioner::ProcessLeaderWeight' =>"leaderweight",
'Commissioner::ProcessMac' =>"mac",
'Commissioner::ProcessMacFilter' =>"macfilter",
'Commissioner::ProcessMasterKey' =>"masterkey",
'Commissioner::ProcessMode' =>"mode",
'Commissioner::ProcessNeighbor' =>"neighbor",
'Commissioner::ProcessNetworkDataRegister' =>"netdataregister",
'Commissioner::ProcessNetworkDataShow' =>"netdatashow",
'Commissioner::ProcessNetworkDiagnostic' =>"networkdiagnostic",
'Commissioner::ProcessNetworkIdTimeout' =>"networkidtimeout",
'Commissioner::ProcessNetworkName' =>"networkname",
'Commissioner::ProcessNetworkTime' =>"networktime",
'Commissioner::ProcessPanId' =>"panid",
'Commissioner::ProcessParent' =>"parent",
'Commissioner::ProcessParentPriority' =>"parentpriority",
'Commissioner::ProcessPing' =>"ping",
'Commissioner::ProcessPollPeriod' =>"pollperiod",
'Commissioner::ProcessPromiscuous' =>"promiscuous",
'Commissioner::ProcessPrefix' =>"prefix",
'Commissioner::ProcessPreferRouterId' =>"preferrouterid",
'Commissioner::ProcessPskc' =>"pskc",
'Commissioner::ProcessReleaseRouterId' =>"releaserouterid",
'Commissioner::ProcessReset' =>"reset",
'Commissioner::ProcessRloc16' =>"rloc16",
'Commissioner::ProcessRoute' =>"route",
'Commissioner::ProcessRouter' =>"router",
'Commissioner::ProcessRouterDowngradeThreshold' =>"routerdowngradethreshold",
'Commissioner::ProcessRouterEligible' =>"routereligible",
'Commissioner::ProcessRouterSelectionJitter' =>"routerselectionjitter",
'Commissioner::ProcessRouterUpgradeThreshold' =>"routerupgradethreshold",
'Commissioner::ProcessScan' =>"scan",
'Commissioner::ProcessService' =>"service",
'Commissioner::ProcessSingleton' =>"singleton",
'Commissioner::ProcessSntp' =>"sntp",
'Commissioner::ProcessState' =>"state",
'Commissioner::ProcessThread' =>"thread",
'Commissioner::ProcessTxPower' =>"txpower",
'Commissioner::ProcessUdp' =>"udp",
'Commissioner::ProcessVersion' =>"version",
};


readlines.each do |line|

  if line =~ /[^&]Commissioner::Process/ or line =~ /strcmp/
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
