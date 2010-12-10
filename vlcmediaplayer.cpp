#include "vlcmediaplayer.hpp"

VLCMediaPlayer::VLCMediaPlayer( libvlc_instance_t* _instance, libvlc_media_t* media){

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

  
  if(media == NULL){
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "media is NULL");
  }
  else{

    current_player = libvlc_media_player_new(instance);
    libvlc_media_player_set_media(current_player, media);
  }
}

VLCMediaPlayer::~VLCMediaPlayer(){
  libvlc_media_player_release(current_player);
  if(create_instance == true)
    libvlc_release(instance);
  
}


void VLCMediaPlayer::setXWindow(int xwindow){


  libvlc_media_player_set_xwindow(current_player, static_cast<uint32_t>(xwindow));

}


void VLCMediaPlayer::play(){

  libvlc_media_player_play(current_player);

}
void VLCMediaPlayer::pause(){

  libvlc_media_player_pause(current_player);

}
void VLCMediaPlayer::stop(){
  libvlc_media_player_stop(current_player);
}

void VLCMediaPlayer::setChapter(int chapter){
  libvlc_media_player_set_chapter(current_player,chapter);
}
  
void VLCMediaPlayer::setPosition(float pos){
  libvlc_media_player_set_position(current_player,pos);
}

float VLCMediaPlayer::getFps(){
  return libvlc_media_player_get_fps(current_player);
}

