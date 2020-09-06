doclines = []

File.open("../README.md", 'r') do |f|
  f.each_line do |line|
    doclines.append line.strip
  end
end

File.open("../README_UDP.md", 'r') do |f|
  f.each_line do |line|
    doclines.append line.sub(/^###/, "### udp").strip
  end
end

File.open("../README_COAP.md", 'r') do |f|
  f.each_line do |line|
    doclines.append line.sub(/^###/, "### coap").strip
  end
end

File.open("../README_COAPS.md", 'r') do |f|
  f.each_line do |line|
    doclines.append line.sub(/^###/, "### coaps").strip
  end
end

File.open("../README_DATASET.md", 'r') do |f|
  f.each_line do |line|
    next if line =~ /^###/
    doclines.append line.sub(/^Usage: `/, "### ").sub(/`$/,"").strip
  end
end

File.open("../README_COMMISSIONER.md", 'r') do |f|
  f.each_line do |line|
    next if line =~ /^###/
    doclines.append line.sub(/^Usage: `/, "### ").sub(/`$/,"").strip
  end
end

File.open("../README_JOINER.md", 'r') do |f|
  f.each_line do |line|
    next if line =~ /^###/
    doclines.append line.sub(/^Usage: `/, "### ").sub(/`$/,"").strip
  end
end

doclines.each do |l|
  #print l
  #print "\n"
end
ents = {}

i = 0
lines = []
STDIN.readlines.each do |line|
  lines.append(line.strip)
  if line.start_with?('#')
    #print line
    i += 1
    next
  end
  data = line.strip.split("\t")
  ents[i.to_s] = data[1] if data.length > 1
  i += 1
end

oents =  ents.values.sort {|x, y| x.length <=> y.length }.reverse

replacetable = {}


oents.each do |e|
  pat = e.gsub(/_/, " ")
  replaces = doclines.grep(/### #{pat}/)

  if replaces.count > 0
    replacetable[e] = replaces

    replacetable[e].each do |line|
      doclines.delete(line)
    end
  end
end

ents.keys.sort{|x,y| x.to_i <=> y.to_i}.reverse.each do |pos|
  if replacetable.has_key?( ents[pos] )
    lines.delete_at(pos.to_i)
    replacetable[ ents[pos] ].reverse.each do |e|
      pat = ents[pos].gsub(/_/, " ")
      data = e.gsub(/###\s*#{pat}\s*/, "").strip.split(" ")
      data.insert(0, ents[pos])
      data.insert(0, "&&&")
      lines.insert(pos.to_i, data.join("\t"))
    end
  end
end

lines.each do |l|
  print l
  print "\n"
end
