// data: domenica, dicembre  5 2010

#include <vlc/vlc.h>
#include "vlcmedia.hpp"
#include "exception.hpp"

#ifndef VLCMEDIALIST_HPP
#define VLCMEDIALIST_HPP

class VLCMediaList{

  libvlc_media_list_t *current_list;
  libvlc_instance_t *current_instance;
public:
  
  VLCMediaList(libvlc_instance_t* );
  virtual ~VLCMediaList();
  void addMedia(const char*);
  void removeMedia(int);
  VLCMedia getMedia(int);
  int count();
};


#endif
