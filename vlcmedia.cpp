#include "vlcmedia.hpp"

VLCMedia::VLCMedia(  libvlc_instance_t * _instance,libvlc_media_t *media){

  chroma = NULL;
  width = -1;
  height = -1;
  pitch = -1;
  drawable_xwindow = -1;

  
  create_instance = false;

  if(_instance == NULL){
    create_instance = true;
    instance = libvlc_new(0, NULL);
    if(instance == NULL){
      static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
      rb_raise(vlcerror, "can't create istance");
    }
    }
  else{
    instance = _instance;
  }

  current_media = media;
  if(media != NULL){
    
    libvlc_media_parse(current_media);
  }
  current_player = NULL;
  
}

VLCMedia::~VLCMedia(){
  

  if(create_instance == true){
    libvlc_release(instance);
    libvlc_media_release(current_media);
  }
}
  
void VLCMedia::setMedia(const char* path){

  libvlc_media_t *media = libvlc_media_new_path(instance, path);
  
  if(media == NULL || fopen (path,"r") == NULL){
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
										 rb_raise(vlcerror, "media doesn't exist");
    
  }

  current_media = media;

}


void VLCMedia::playMedia(){

  //for now it will use a dummy output done with sdl

  if(current_media != NULL){

    VLCDummyOutput* dummy = new VLCDummyOutput(current_media);
    dummy->playMedia();
    delete(dummy);

  }

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


const char* VLCMedia::getMeta(const char* type){

  if(current_media != NULL){
    if(strcmp(type,"Title"))
      return libvlc_media_get_meta(current_media, libvlc_meta_Title );
    else if(strcmp(type,"Artist"))
          return libvlc_media_get_meta(current_media, libvlc_meta_Artist );
    else if(strcmp(type,"Description"))
          return libvlc_media_get_meta(current_media, libvlc_meta_Description );
    else if(strcmp(type,"Url"))
      return libvlc_media_get_meta(current_media, libvlc_meta_URL );
    else{
      static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
      rb_raise(vlcerror, "meta not found");
    }
  }
  else{
    
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "media is not initialitiated");
    
  }
}

VLCMediaPlayer VLCMedia::getPlayer(){
  if(current_media != NULL)
    {

      return VLCMediaPlayer(instance, current_media);    
    }
  static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
  rb_raise(vlcerror, "media is not initialitiated");

}
