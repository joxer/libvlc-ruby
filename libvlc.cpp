#include "libvlc.hpp"
#include <ruby.h>
LibVLC::LibVLC(int argc, const char* const* argv ){

  instance = libvlc_new(argc, argv);
  if(instance == NULL){
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "can't create istance");
    
  }

  

}

LibVLC::~LibVLC(){

  //  libvlc_release(instance);
  
}

void LibVLC::setUserAgent(const char* name , const char* http){

  libvlc_set_user_agent(instance, name,http);

}

const char* LibVLC::getVersion(){

  return libvlc_get_version();

}

VLCMedia LibVLC::addMedia(const char* path){

  libvlc_media_t *current_media = libvlc_media_new_path(instance, path);



  if(fopen (path,"r") == NULL){
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "media doesn't exist");

 //    throw VLCRubyException();
  }
  
  return VLCMedia(current_media);
}

VLCMediaList LibVLC::createPlayList(){

  return VLCMediaList(instance);

}
