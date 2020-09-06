cmdtable = {
'Joiner::ProcessBackboneRouter' =>"bbr",
'Joiner::ProcessBufferInfo' =>"bufferinfo",
'Joiner::ProcessChannel' =>"channel",
'Joiner::ProcessChild' =>"child",
'Joiner::ProcessChildIp' =>"childip",
'Joiner::ProcessChildMax' =>"childmax",
'Joiner::ProcessChildTimeout' =>"childtimeout",
'Joiner::ProcessCoap' =>"coap",
'Joiner::ProcessCoapSecure' =>"coaps",
'Joiner::ProcessCoexMetrics' =>"coex",
'Joiner::ProcessCommissioner' =>"commissioner",
'Joiner::ProcessContextIdReuseDelay' =>"contextreusedelay",
'Joiner::ProcessCounters' =>"counters",
'Joiner::ProcessDataset' =>"dataset",
'Joiner::ProcessDelayTimerMin' =>"delaytimermin",
'Joiner::ProcessDiag' =>"diag",
'Joiner::ProcessDiscover' =>"discover",
'Joiner::ProcessDns' =>"dns",
'Joiner::ProcessEidCache' =>"eidcache",
'Joiner::ProcessEui64' =>"eui64",
'Joiner::ProcessExit' =>"exit",
'Joiner::ProcessLogFilename' =>"logfilename",
'Joiner::ProcessExtAddress' =>"extaddr",
'Joiner::ProcessExtPanId' =>"extpanid",
'Joiner::ProcessFactoryReset' =>"factoryreset",
'Joiner::ProcessHelp' =>"help",
'Joiner::ProcessIfconfig' =>"ifconfig",
'Joiner::ProcessIpAddr' =>"ipaddr",
'Joiner::ProcessIpMulticastAddr' =>"ipmaddr",
'Joiner::ProcessJoiner' =>"joiner",
'Joiner::ProcessJoinerPort' =>"joinerport",
'Joiner::ProcessKeySequence' =>"keysequence",
'Joiner::ProcessLeaderData' =>"leaderdata",
'Joiner::ProcessLeaderPartitionId' =>"leaderpartitionid",
'Joiner::ProcessLeaderWeight' =>"leaderweight",
'Joiner::ProcessMac' =>"mac",
'Joiner::ProcessMacFilter' =>"macfilter",
'Joiner::ProcessMasterKey' =>"masterkey",
'Joiner::ProcessMode' =>"mode",
'Joiner::ProcessNeighbor' =>"neighbor",
'Joiner::ProcessNetworkDataRegister' =>"netdataregister",
'Joiner::ProcessNetworkDataShow' =>"netdatashow",
'Joiner::ProcessNetworkDiagnostic' =>"networkdiagnostic",
'Joiner::ProcessNetworkIdTimeout' =>"networkidtimeout",
'Joiner::ProcessNetworkName' =>"networkname",
'Joiner::ProcessNetworkTime' =>"networktime",
'Joiner::ProcessPanId' =>"panid",
'Joiner::ProcessParent' =>"parent",
'Joiner::ProcessParentPriority' =>"parentpriority",
'Joiner::ProcessPing' =>"ping",
'Joiner::ProcessPollPeriod' =>"pollperiod",
'Joiner::ProcessPromiscuous' =>"promiscuous",
'Joiner::ProcessPrefix' =>"prefix",
'Joiner::ProcessPreferRouterId' =>"preferrouterid",
'Joiner::ProcessPskc' =>"pskc",
'Joiner::ProcessReleaseRouterId' =>"releaserouterid",
'Joiner::ProcessReset' =>"reset",
'Joiner::ProcessRloc16' =>"rloc16",
'Joiner::ProcessRoute' =>"route",
'Joiner::ProcessRouter' =>"router",
'Joiner::ProcessRouterDowngradeThreshold' =>"routerdowngradethreshold",
'Joiner::ProcessRouterEligible' =>"routereligible",
'Joiner::ProcessRouterSelectionJitter' =>"routerselectionjitter",
'Joiner::ProcessRouterUpgradeThreshold' =>"routerupgradethreshold",
'Joiner::ProcessScan' =>"scan",
'Joiner::ProcessService' =>"service",
'Joiner::ProcessSingleton' =>"singleton",
'Joiner::ProcessSntp' =>"sntp",
'Joiner::ProcessState' =>"state",
'Joiner::ProcessThread' =>"thread",
'Joiner::ProcessTxPower' =>"txpower",
'Joiner::ProcessUdp' =>"udp",
'Joiner::ProcessVersion' =>"version",
};


readlines.each do |line|

  if line =~ /[^&]Joiner::Process/ or line =~ /strcmp/
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
