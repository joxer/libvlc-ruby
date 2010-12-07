%module libvlc
%include "typemaps.i"

%{



#include "libvlc.hpp"
#include "vlcmedia.hpp"
#include "vlcmedialist.hpp"
#include "vlcdummyoutput.hpp"
#include "exception.hpp"

#include <vlc/vlc.h>
#include <cstdlib>
#include <exception>
%}
class LibVLC{

  libvlc_instance_t * instance;
  libvlc_exception_t vlcexcep;
 public:
  LibVLC(int = 0,const char *const * = NULL);
  virtual ~LibVLC();
  void setUserAgent(const char* , const char* );
  const char* getVersion();
  VLCMedia addMedia(const char* path);
  VLCMediaList createPlayList();
};


class VLCMedia{

  libvlc_media_t *current_media;
  VLCDummyOutput* dummy;
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


class VLCMediaList{

  libvlc_media_list_t *current_list;
  libvlc_instance_t *current_instance;
public:
  
  VLCMediaList(libvlc_instance_t* );
  virtual ~VLCMediaList();

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



  SDL_Surface *screen, *empty;
  SDL_Event event;
  SDL_Rect rect;
  int done, action, pause, n;
  
  struct ctx ctx;
  libvlc_media_player_t *mp;
  libvlc_media_t *current_media;
 public:
  
  VLCDummyOutput(libvlc_media_t*);
  virtual ~VLCDummyOutput();
  void playMedia();
  void setOption(const char*,int,int,int);
  //  void pauseMedia();
  
 private:

};



