all: 
	swig -ruby -c++ libvlc.i
	g++ -c libvlc_wrap.cxx -fPIC -I/usr/lib64/ruby/1.8/x86_64-linux -lvcl
	g++ -c vlcdummyoutput.cpp -fPIC -I/usr/lib64/ruby/1.8/x86_64-linux -lvlc `sdl-config --cflags --libs`
	g++ -c libvlc.cpp -fPIC -I/usr/lib64/ruby/1.8/x86_64-linux -lvlc -lvlc 
	g++ -c vlcmedia.cpp -fPIC -I/usr/lib64/ruby/1.8/x86_64-linux -lvlc -lvlc
	g++ -c vlcmedialist.cpp -fPIC -I/usr/lib64/ruby/1.8/x86_64-linux -lvlc-lvlc

	g++ -shared vlcdummyoutput.o vlcmedialist.o vlcmedia.o libvlc.o libvlc_wrap.o -o libvlc.so -lvlc -lvlc `sdl-config --cflags --libs`