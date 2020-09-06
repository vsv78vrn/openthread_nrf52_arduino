cmdtable = {
'Dataset::ProcessBackboneRouter' =>"bbr",
'Dataset::ProcessBufferInfo' =>"bufferinfo",
'Dataset::ProcessChannel' =>"channel",
'Dataset::ProcessChild' =>"child",
'Dataset::ProcessChildIp' =>"childip",
'Dataset::ProcessChildMax' =>"childmax",
'Dataset::ProcessChildTimeout' =>"childtimeout",
'Dataset::ProcessCoap' =>"coap",
'Dataset::ProcessCoapSecure' =>"coaps",
'Dataset::ProcessCoexMetrics' =>"coex",
'Dataset::ProcessCommissioner' =>"commissioner",
'Dataset::ProcessContextIdReuseDelay' =>"contextreusedelay",
'Dataset::ProcessCounters' =>"counters",
'Dataset::ProcessDataset' =>"dataset",
'Dataset::ProcessDelayTimerMin' =>"delaytimermin",
'Dataset::ProcessDiag' =>"diag",
'Dataset::ProcessDiscover' =>"discover",
'Dataset::ProcessDns' =>"dns",
'Dataset::ProcessEidCache' =>"eidcache",
'Dataset::ProcessEui64' =>"eui64",
'Dataset::ProcessExit' =>"exit",
'Dataset::ProcessLogFilename' =>"logfilename",
'Dataset::ProcessExtAddress' =>"extaddr",
'Dataset::ProcessExtPanId' =>"extpanid",
'Dataset::ProcessFactoryReset' =>"factoryreset",
'Dataset::ProcessHelp' =>"help",
'Dataset::ProcessIfconfig' =>"ifconfig",
'Dataset::ProcessIpAddr' =>"ipaddr",
'Dataset::ProcessIpMulticastAddr' =>"ipmaddr",
'Dataset::ProcessJoiner' =>"joiner",
'Dataset::ProcessJoinerPort' =>"joinerport",
'Dataset::ProcessKeySequence' =>"keysequence",
'Dataset::ProcessLeaderData' =>"leaderdata",
'Dataset::ProcessLeaderPartitionId' =>"leaderpartitionid",
'Dataset::ProcessLeaderWeight' =>"leaderweight",
'Dataset::ProcessMac' =>"mac",
'Dataset::ProcessMacFilter' =>"macfilter",
'Dataset::ProcessMasterKey' =>"masterkey",
'Dataset::ProcessMode' =>"mode",
'Dataset::ProcessNeighbor' =>"neighbor",
'Dataset::ProcessNetworkDataRegister' =>"netdataregister",
'Dataset::ProcessNetworkDataShow' =>"netdatashow",
'Dataset::ProcessNetworkDiagnostic' =>"networkdiagnostic",
'Dataset::ProcessNetworkIdTimeout' =>"networkidtimeout",
'Dataset::ProcessNetworkName' =>"networkname",
'Dataset::ProcessNetworkTime' =>"networktime",
'Dataset::ProcessPanId' =>"panid",
'Dataset::ProcessParent' =>"parent",
'Dataset::ProcessParentPriority' =>"parentpriority",
'Dataset::ProcessPing' =>"ping",
'Dataset::ProcessPollPeriod' =>"pollperiod",
'Dataset::ProcessPromiscuous' =>"promiscuous",
'Dataset::ProcessPrefix' =>"prefix",
'Dataset::ProcessPreferRouterId' =>"preferrouterid",
'Dataset::ProcessPskc' =>"pskc",
'Dataset::ProcessReleaseRouterId' =>"releaserouterid",
'Dataset::ProcessReset' =>"reset",
'Dataset::ProcessRloc16' =>"rloc16",
'Dataset::ProcessRoute' =>"route",
'Dataset::ProcessRouter' =>"router",
'Dataset::ProcessRouterDowngradeThreshold' =>"routerdowngradethreshold",
'Dataset::ProcessRouterEligible' =>"routereligible",
'Dataset::ProcessRouterSelectionJitter' =>"routerselectionjitter",
'Dataset::ProcessRouterUpgradeThreshold' =>"routerupgradethreshold",
'Dataset::ProcessScan' =>"scan",
'Dataset::ProcessService' =>"service",
'Dataset::ProcessSingleton' =>"singleton",
'Dataset::ProcessSntp' =>"sntp",
'Dataset::ProcessState' =>"state",
'Dataset::ProcessThread' =>"thread",
'Dataset::ProcessTxPower' =>"txpower",
'Dataset::ProcessUdp' =>"udp",
'Dataset::ProcessVersion' =>"version",
};


readlines.each do |line|

  if line =~ /[^&]Dataset::Process/ or line =~ /strcmp/
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
