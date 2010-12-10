
%module libvlc
%include "typemaps.i"

%{



#include "libvlc.hpp"
#include "vlcmedia.hpp"
#include "vlcmedialist.hpp"
#include "vlcdummyoutput.hpp"
#include "vlcmediaplayer.hpp"

#include "exception.hpp"

#include <vlc/vlc.h>
#include <cstdlib>
#include <exception>
%}



class LibVLC{

  libvlc_log_t *log;
  libvlc_instance_t * instance;

 public:
  LibVLC(int = 0,const char *const * = NULL, bool = NULL);
  ~LibVLC();
  void setUserAgent(const char* , const char* );
  const char* getVersion();
  VLCMedia addMedia(const char* path);
  VLCMediaList createPlayList();
};

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

  void playMedia();
  void setMedia(const char*);
  VLCMediaPlayer getPlayer();
  const char* getMeta(const char*);
  
};



class VLCMediaList{
  bool create_instance;
  libvlc_media_list_t *current_list;
  libvlc_instance_t * instance;

public:
  
  VLCMediaList(libvlc_instance_t* = NULL);
  ~VLCMediaList();

  void addMedia(const char*);
  void removeMedia(int);
  VLCMedia getMedia(int);
  int VLCMediaList::count();

};

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
  
  struct ctx ctx;
  libvlc_media_player_t *mp;
  libvlc_media_t *current_media;
 public:
  
  VLCDummyOutput(libvlc_media_t*);
   ~VLCDummyOutput();
  void playMedia();
  void setOption(const char*,int,int,int);
  //  void pauseMedia();
  
 private:

};


class VLCMediaPlayer{

  bool create_instance;
  libvlc_instance_t* instance;
  libvlc_media_player_t* current_player;

 public:
  VLCMediaPlayer(libvlc_instance_t*, libvlc_media_t*);
  ~VLCMediaPlayer();

  void setXWindow(int);
  void play();
  void pause();
  void stop();
  void setChapter(int);
  void setPosition(float);
  float getFps();

};
