// data: sabato, dicembre  4 2010

#include <vlc/vlc.h>

#include "vlcdummyoutput.hpp"
#include "vlcmediaplayer.hpp"


#ifndef VLCMEDIA_HPP
#define VLCMEDIA_HPP
class VLCMedia{

  const char* chroma;
  int width,height,pitch;
  
  bool create_instance;
  libvlc_instance_t * instance;
  VLCDummyOutput *dummy;
  libvlc_media_t *current_media;
  libvlc_media_player_t *current_player;
  uint32_t drawable_xwindow;


public:
  VLCMedia(  libvlc_instance_t * = NULL, libvlc_media_t * = NULL);
  ~VLCMedia();
  
  void setVideoFormat(const char*, int,int,int);

  void playMedia();
  void setXWindow(int);
  VLCMediaPlayer getPlayer();

  void setMedia(const char*);

  const char* getMeta(const char*);

  
};

#endif
