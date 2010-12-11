

#include <vlc/vlc.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include <SDL/SDL.h>
#include <SDL/SDL_mutex.h>

#include <ruby.h>
#ifndef VLCDUMMYOUTPUT_HPP
#define VLCDUMMYOUTPUT_HPP

struct Ctx
{
  SDL_Surface *surf;
  SDL_mutex *mutex;
};


class VLCDummyOutput {
  
  const char* chroma;
  int width, height, pitch;
  

  SDL_Surface *screen, *empty;
  SDL_Event event;
  SDL_Rect rect;
  int done, action, pause, n;
 
  struct Ctx ctx;
  libvlc_media_player_t *mp;
  libvlc_media_t *current_media;
 public:
  
  VLCDummyOutput(libvlc_media_t*);
 ~VLCDummyOutput();
  void playMedia();
  void setOption(const char*, int,int,int);


 
};


#endif
