cmdtable = {
'Interpreter::ProcessBackboneRouter' =>"bbr",
'Interpreter::ProcessBufferInfo' =>"bufferinfo",
'Interpreter::ProcessChannel' =>"channel",
'Interpreter::ProcessChild' =>"child",
'Interpreter::ProcessChildIp' =>"childip",
'Interpreter::ProcessChildMax' =>"childmax",
'Interpreter::ProcessChildTimeout' =>"childtimeout",
'Interpreter::ProcessCoap' =>"coap",
'Interpreter::ProcessCoapSecure' =>"coaps",
'Interpreter::ProcessCoexMetrics' =>"coex",
'Interpreter::ProcessCommissioner' =>"commissioner",
'Interpreter::ProcessContextIdReuseDelay' =>"contextreusedelay",
'Interpreter::ProcessCounters' =>"counters",
'Interpreter::ProcessDataset' =>"dataset",
'Interpreter::ProcessDelayTimerMin' =>"delaytimermin",
'Interpreter::ProcessDiag' =>"diag",
'Interpreter::ProcessDiscover' =>"discover",
'Interpreter::ProcessDns' =>"dns",
'Interpreter::ProcessEidCache' =>"eidcache",
'Interpreter::ProcessEui64' =>"eui64",
'Interpreter::ProcessExit' =>"exit",
'Interpreter::ProcessLogFilename' =>"logfilename",
'Interpreter::ProcessExtAddress' =>"extaddr",
'Interpreter::ProcessExtPanId' =>"extpanid",
'Interpreter::ProcessFactoryReset' =>"factoryreset",
'Interpreter::ProcessHelp' =>"help",
'Interpreter::ProcessIfconfig' =>"ifconfig",
'Interpreter::ProcessIpAddr' =>"ipaddr",
'Interpreter::ProcessIpMulticastAddr' =>"ipmaddr",
'Interpreter::ProcessJoiner' =>"joiner",
'Interpreter::ProcessJoinerPort' =>"joinerport",
'Interpreter::ProcessKeySequence' =>"keysequence",
'Interpreter::ProcessLeaderData' =>"leaderdata",
'Interpreter::ProcessLeaderPartitionId' =>"leaderpartitionid",
'Interpreter::ProcessLeaderWeight' =>"leaderweight",
'Interpreter::ProcessMac' =>"mac",
'Interpreter::ProcessMacFilter' =>"macfilter",
'Interpreter::ProcessMasterKey' =>"masterkey",
'Interpreter::ProcessMode' =>"mode",
'Interpreter::ProcessNeighbor' =>"neighbor",
'Interpreter::ProcessNetworkDataRegister' =>"netdataregister",
'Interpreter::ProcessNetworkDataShow' =>"netdatashow",
'Interpreter::ProcessNetworkDiagnostic' =>"networkdiagnostic",
'Interpreter::ProcessNetworkIdTimeout' =>"networkidtimeout",
'Interpreter::ProcessNetworkName' =>"networkname",
'Interpreter::ProcessNetworkTime' =>"networktime",
'Interpreter::ProcessPanId' =>"panid",
'Interpreter::ProcessParent' =>"parent",
'Interpreter::ProcessParentPriority' =>"parentpriority",
'Interpreter::ProcessPing' =>"ping",
'Interpreter::ProcessPollPeriod' =>"pollperiod",
'Interpreter::ProcessPromiscuous' =>"promiscuous",
'Interpreter::ProcessPrefix' =>"prefix",
'Interpreter::ProcessPreferRouterId' =>"preferrouterid",
'Interpreter::ProcessPskc' =>"pskc",
'Interpreter::ProcessReleaseRouterId' =>"releaserouterid",
'Interpreter::ProcessReset' =>"reset",
'Interpreter::ProcessRloc16' =>"rloc16",
'Interpreter::ProcessRoute' =>"route",
'Interpreter::ProcessRouter' =>"router",
'Interpreter::ProcessRouterDowngradeThreshold' =>"routerdowngradethreshold",
'Interpreter::ProcessRouterEligible' =>"routereligible",
'Interpreter::ProcessRouterSelectionJitter' =>"routerselectionjitter",
'Interpreter::ProcessRouterUpgradeThreshold' =>"routerupgradethreshold",
'Interpreter::ProcessScan' =>"scan",
'Interpreter::ProcessService' =>"service",
'Interpreter::ProcessSingleton' =>"singleton",
'Interpreter::ProcessSntp' =>"sntp",
'Interpreter::ProcessState' =>"state",
'Interpreter::ProcessThread' =>"thread",
'Interpreter::ProcessTxPower' =>"txpower",
'Interpreter::ProcessUdp' =>"udp",
'Interpreter::ProcessVersion' =>"version",
};


readlines.each do |line|

  if line =~ /[^&]Interpreter::Process/ or line =~ /strcmp/
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
