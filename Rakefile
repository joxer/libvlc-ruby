require 'fileutils'

$host = ""
$arch = ""
task :default do
  
  $host = RbConfig::CONFIG["host_os"]
  $arch = RbConfig::CONFIG["arch"]

  headers = "";
  
  if($host =~ /linux/)
    
    if(RbConfig::CONFIG["ruby_version"].slice(0,3) == "1.8")

      headers +=  RbConfig::CONFIG['archdir']
      
    elsif(RbCOnfig::CONFIG["version"].slice(0,3) == "1.9")

      headers +=  RbConfig::CONFIG['rubyhdrdir'] +  " -I " + RbConfig::CONFIG["rubyhdrdir"]+"/"+  RbConfig::CONFIG["arch"]
    end

sh %{ 
swig -ruby -c++ libvlc.i
g++ -c libvlc_wrap.cxx -fPIC -I #{headers} -lvlc
g++ -c vlcdummyoutput.cpp -fPIC -I #{headers} -lvlc `sdl-config --cflags --libs`
g++ -c libvlc.cpp -fPIC -I #{headers} -lvlc 
g++ -c vlcmedia.cpp -fPIC -I #{headers} -lvlc 
g++ -c vlcmedialist.cpp -fPIC -I #{headers} -lvlc
g++ -c vlcmediaplayer.cpp -fPIC -I #{headers} -lvlc

g++ -shared vlcmediaplayer.o vlcdummyoutput.o vlcmedialist.o vlcmedia.o libvlc.o libvlc_wrap.o -o libvlc.so -lvlc `sdl-config --cflags --libs`
}
    




  end
end 
