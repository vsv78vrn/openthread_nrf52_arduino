srcdir = ARGV[0]


FILECLAZZ = {
  'coap' => ["#{srcdir}/cli_coap.cpp", 'Coap'],
  'coaps' => ["#{srcdir}/cli_coap_secure.cpp", 'CoapSecure'],
  'commissioner' => ["#{srcdir}/cli_commissioner.cpp", 'Commissioner'],
  'dataset' => ["#{srcdir}/cli_dataset.cpp", 'Dataset'],
  'joiner' => ["#{srcdir}/cli_joiner.cpp", 'Joiner'],
  'udp' => ["#{srcdir}/cli_udp.cpp", 'UdpExample']
}

def extract_command(file, clazz, prefix)
  cmdtable = {}

  IO.readlines(file).each do |line|
    if line =~ /^#(if[^d]|endif|else)/
      print line
      next
    end
    if line =~ /&#{clazz}::Process/
      line.split('{').each do |entry|
        entry.gsub!(/}.*/, '')
        entry.gsub!(/&/, '')
        entry.gsub!(/"/, '')
        entry.strip!
        vk = entry.split(',')

        if vk.count >= 2
          cmdtable[vk[1].strip] = vk[0].strip
        end
      end
    end

    if line =~ /[^&]#{clazz}::Process/ or line =~ /strcmp/
      morespace = (prefix == "") ? "" : "\t"
      line.gsub!(/\ \ \ \ /, "\t")
      line.gsub!(/^(\t*).*strcmp.*"([^"]*)".*/, '\1' + morespace + '\2')
      line.gsub!(/\(.*$/, '')
      line.gsub!(/^.* /, '')

      next if line =~ /Process$/


      if cmdtable[line.strip] != nil
        cmd = cmdtable[line.strip]
        if prefix == "" and FILECLAZZ[cmd] != nil
          args = FILECLAZZ[cmd]
          extract_command(args[0], args[1], cmd) 
          next
        else
          line = "#{prefix}#{morespace}#{cmdtable[line.strip]}\n"
        end
      end
      print line
    end
  end
end

extract_command(ARGV[0] + "/cli.cpp", 'Interpreter', "")

