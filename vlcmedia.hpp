// data: sabato, dicembre  4 2010

#include <vlc/vlc.h>


#ifndef VLCMEDIA_HPP
#define VLCMEDIA_HPP

#include "vlcdummyoutput.hpp"

class VLCMedia{

  const char* chroma;
  int width,height,pitch;
  
  bool create_instance;
  libvlc_instance_t * instance;
  VLCDummyOutput *dummy;
  libvlc_media_t *current_media;
  libvlc_media_player_t *current_player;

public:
  VLCMedia(  libvlc_instance_t * = NULL, libvlc_media_t * = NULL);
  ~VLCMedia();
  
  void setVideoFormat(const char*, int,int,int);
  void pauseMedia();
  void playMedia();
  void setMedia(const char*);

  const char* getMeta(const char*);

  
};

#endif
