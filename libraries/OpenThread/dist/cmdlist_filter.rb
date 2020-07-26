buffer = []
table = {}

key = nil

readlines.each do |line|
  if line =~ /^#(if[^d]|endif|else)/
    buffer.append line
    next
  end

  key = nil if not line =~ /^\t/

  next if line =~ /Interpreter\:\:ProcessBackboneRouterLocal/
  next if line =~ /Interpreter\:\:ProcessIpAddrAdd/
  next if line =~ /Interpreter\:\:ProcessIpAddrDel/
  next if line =~ /Interpreter\:\:ProcessIpMulticastAddrAdd/
  next if line =~ /Interpreter\:\:ProcessIpMulticastAddrDel/
  next if line =~ /Interpreter\:\:ProcessPrefixRemove/
  next if line =~ /Interpreter\:\:ProcessPrefixList/
  next if line =~ /Interpreter\:\:ProcessRouteRemove/
  next if line =~ /Interpreter\:\:ProcessRouteList/

  if line =~ /Interpreter\:\:ProcessMulticastPromiscuous/
    key = 'ipmaddr:promiscuous'
    table[key] = []
    next
  end
  if line =~ /Interpreter\:\:ProcessPrefixAdd/
    key = 'prefix:add'
    table[key] = []
    next
  end
  if line =~ /Interpreter\:\:ProcessRouteAdd/
    key = 'route:add'
    table[key] = []
    next
  end
  if line =~ /Interpreter\:\:ProcessMacFilterAddress/
    key = 'macfilter:addr'
    table[key] = []
    next
  end
  if line =~ /Interpreter\:\:ProcessMacFilterRss/
    key = 'macfilter:rss'
    table[key] = []
    next
  end
  if line =~ /Interpreter\:\:ProcessMacRetries/
    key = 'mac:retries'
    table[key] = []
    next
  end
  if line =~ /Interpreter\:\:ProcessLine/
    key = 'line'
    table[key] = []
    next
  end

  if key
    table[key].append(line.strip)
    next
  end

  buffer.append line
end

prev = nil

cmds = []

buffer.each do |line|
  if line =~ /^#(if[^d]|endif|else)/
    cmds.append [line]
    next
  end

  ent = line.split(/\s/)
  next if ent.count == 0

  if ent[0] == "" and prev.count >= 1
    ent[0] = prev[0]
  end
  if ent[1] == "" and prev.count >= 2
    ent[1] = prev[1]
  end
  if ent[2] == "" and prev.count >= 3
    ent[2] = prev[2]
  end
  if ent[3] == "" and prev.count >= 4
    ent[3] = prev[3]
  end

  if ent.count >= 2 and table.has_key?(ent[0] + ":" + ent[1])
    table[ent[0] + ":" + ent[1]].each do |v|
      expand = [ent[0], ent[1], v]
      cmds.append expand
    end
  else
    cmds.append ent
  end

  prev = ent
end

cmds.each do |cmd|
  if cmd[0] =~ /^#(if[^d]|endif|else)/
    print cmd[0]
    next
  end
  print("??? #{cmd.join('_').gsub(/_+/,'_').gsub(/-/,'')}\n")
end

