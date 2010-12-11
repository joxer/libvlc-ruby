#include <vlc/vlc.h>
#include "vlcmedia.hpp"

#ifndef VLCMEDIALIST_HPP
#define VLCMEDIALIST_HPP

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
  int count();
};


#endif
