#include <vlc/vlc.h>
#include <cstdlib>
#include <ruby.h>

#ifndef VLCMEDIAPLAYER_HPP
#define VLCMEDIAPLAYER_HPP

class VLCMediaPlayer{

  bool create_instance;
  libvlc_instance_t* instance;
  libvlc_media_player_t* current_player;

public:
  VLCMediaPlayer( libvlc_instance_t*, libvlc_media_t* );
  ~VLCMediaPlayer();

  void setXWindow(int);
  void play();
  void pause();
  void stop();
  
  void setChapter(int);
  void setPosition(float);
  float getFps();

};

#endif
