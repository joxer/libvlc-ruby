// data: sabato, dicembre  4 2010

#include "vlcmedia.hpp"
#include "vlcmedialist.hpp"
#include "exception.hpp"
#include <vlc/vlc.h>
#include <cstdlib>

#ifndef LIBVLC_HPP
#define LIBVLC_HPP
class LibVLC{
  
  libvlc_log_t *log;
  libvlc_instance_t * instance;

public:

  LibVLC(int = 0, const char *const * = NULL, bool = false);
  ~LibVLC();
  void setUserAgent(const char* , const char* );
  const char* getVersion();
  VLCMedia addMedia(const char* path);
  VLCMediaList createPlayList();
};



#endif
