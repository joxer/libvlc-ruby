// data: sabato, dicembre  4 2010

#include <vlc/vlc.h>


#ifndef VLCMEDIA_HPP
#define VLCMEDIA_HPP

#include "vlcdummyoutput.hpp"

class VLCMedia{

  const char* chroma;
  int width,height,pitch;
  

  VLCDummyOutput *dummy;
  libvlc_media_t *current_media;
  libvlc_media_player_t *current_player;

public:
  VLCMedia(libvlc_media_t *);
  virtual ~VLCMedia();
  
  void setVideoFormat(const char*, int,int,int);
  void pauseMedia();
  void playMedia();
  const char* getTitleMedia();
  const char* getArtistMedia();
  const char* getDescriptionMedia();
  const char* getUrl();
  
};

#endif
