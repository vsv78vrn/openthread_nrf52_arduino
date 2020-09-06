lines = []

hier = {}

readlines.each do |l|
  next if l =~ /^#/
  next if not l =~ /;\s+$/
  lines.append l.strip
  l.gsub!(/const /, "const_")
  l.gsub!(/,\s+/, "\t")
  l = l.sub(/ /,"\t").gsub(/[\(\);]/,"\t").strip
  data = l.split("\t")
  mtd = data[1] + ":" + (data.count - 2).to_s
  #data[1] = data[1] + ":" + (data.count - 2).to_s
  next if mtd =~ /^_/
  
  mtds =  mtd.split(/_/)

  if mtds.count == 1
    hier[mtds[0]] = {} if not hier.has_key?(mtds[0])
    hier[mtds[0]][""] = data
  elsif mtds.count == 2
    hier[mtds[0]] = {} if not hier[mtds[0]]
    hier[mtds[0]][mtds[1]] = {} if not hier[mtds[0]].has_key?([mtds[1]])
    hier[mtds[0]][mtds[1]][""] = data
  elsif mtds.count == 3
    hier[mtds[0]] = {} if not hier[mtds[0]]
    hier[mtds[0]][mtds[1]] = {} if not hier[mtds[0]].has_key?([mtds[1]])
    hier[mtds[0]][mtds[1]][mtds[2]] = {} if not hier[mtds[0]][mtds[1]].has_key?([mtds[2]])
    hier[mtds[0]][mtds[1]][mtds[2]][""] = data
  end

end

def sp(lv)
  return "  " * lv
end

def formatdecl(types)
  cnt =  -1
  types.collect {|t| cnt+=1 ;  "#{t} a#{cnt}"}.join(", ")
end
def formatcall(types)
  cnt =  -1
  types.collect {|t| cnt+=1 ;  "a#{cnt}"}.join(", ")
end


def traverse(tr, lv)
  tr.each do |k, v|
    next if v[0] == "noimpl"
    if k == ""
      if v.count > 2
        print "#{sp(lv)}#{v[0]} operator()(#{formatdecl(v[2..-1])}) { return OTCMD::#{v[1]}(#{formatcall(v[2..-1])}); }\n"
      else
        print "#{sp(lv)}#{v[0]} operator()() const { return OTCMD::#{v[1]}(); }\n"
      end
    else
      print "#{sp(lv)}struct {\n"
      traverse(tr[k], lv+1)
      print "#{sp(lv)}} #{k.sub(/:.*/,"")};\n"
    end
  end
end

traverse(hier, 1)
