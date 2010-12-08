RUBY_VERSION=$(shell ruby -rrbconfig -e 'print RbConfig::CONFIG["ruby_version"]')
RUBY_SHORT=$(shell echo ${RUBY_VERSION} | cut -c 1-3)
RUBY_HEADERS=$(shell if [ "${RUBY_SHORT}"  = "1.9" ]; then ruby${RUBY_VERSION} -rrbconfig -e 'print RbConfig::CONFIG["rubyhdrdir"]';else ruby -rrbconfig -e 'print RbConfig::CONFIG["archdir"]';fi;)
RUBY_CONFIG_HEADERS=$(shell if [ "${RUBY_SHORT}" = "1.9" ]; then ruby${RUBY_VERSION} -rrbconfig -e 'print RbConfig::CONFIG["rubyhdrdir"]+"/"+  RbConfig::CONFIG["arch"]'; fi;)

all: 

	swig -ruby -c++ libvlc.i
	g++ -c libvlc_wrap.cxx -fPIC -I ${RUBY_HEADERS} -I ${RUBY_CONFIG_HEADERS} -lvlc
	g++ -c vlcdummyoutput.cpp -fPIC -I ${RUBY_HEADERS} -I ${RUBY_CONFIG_HEADERS} -lvlc `sdl-config --cflags --libs`
	g++ -c libvlc.cpp -fPIC -I ${RUBY_HEADERS} -I ${RUBY_CONFIG_HEADERS} -lvlc 
	g++ -c vlcmedia.cpp -fPIC -I ${RUBY_HEADERS} -I ${RUBY_CONFIG_HEADERS} -lvlc 
	g++ -c vlcmedialist.cpp -fPIC -I ${RUBY_HEADERS} -I ${RUBY_CONFIG_HEADERS} -lvlc

	g++ -shared vlcdummyoutput.o vlcmedialist.o vlcmedia.o libvlc.o libvlc_wrap.o -o libvlc.so -lvlc `sdl-config --cflags --libs`
