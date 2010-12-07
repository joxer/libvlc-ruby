#include "vlcmedia.hpp"

VLCMedia::VLCMedia(libvlc_media_t *media){

  chroma = NULL;
  width = -1;
  height = -1;
  pitch = -1;


  current_media = media;
  libvlc_media_parse(current_media);

  current_player = NULL;
  
}

VLCMedia::~VLCMedia(){
  
  //libvlc_media_release(current_media);
  
}
  

void VLCMedia::playMedia(){

  //for now it will use a dummy output done with sdl

  VLCDummyOutput* dummy = new VLCDummyOutput(current_media);
  dummy->playMedia();

}

void VLCMedia::pauseMedia(){

  libvlc_media_player_pause(current_player);

}


void VLCMedia::setVideoFormat(const char* cchroma, int w ,int h ,int p){

  chroma = cchroma;
  width = w;
  height = h;
  pitch = p;

}


const char* VLCMedia::getTitleMedia(){

  return libvlc_media_get_meta(current_media, libvlc_meta_Title );

}

const char* VLCMedia::getArtistMedia(){

  return libvlc_media_get_meta(current_media, libvlc_meta_Artist );

}

const char* VLCMedia::getDescriptionMedia(){

  return libvlc_media_get_meta(current_media, libvlc_meta_Description );

}

const char* VLCMedia::getUrl(){

  return libvlc_media_get_meta(current_media, libvlc_meta_URL );

}



