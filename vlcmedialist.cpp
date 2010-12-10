#include "vlcmedialist.hpp"
  
VLCMediaList::VLCMediaList(libvlc_instance_t* _instance){
  
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

  current_list = libvlc_media_list_new(instance);
  
}
VLCMediaList::~VLCMediaList(){
  
  //if i enable this it will cause abort of program

  libvlc_media_list_release(current_list);  
  if(create_instance == true){
    libvlc_release(instance);

  }
}
void VLCMediaList::addMedia(const char* position){


  libvlc_media_t* added_media = libvlc_media_new_location(instance, position);
  
  if(added_media == NULL){
     static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "media doesn't exist");

  }


  libvlc_media_list_lock(current_list);
  libvlc_media_list_add_media(current_list, added_media);
  libvlc_media_list_unlock(current_list);


}

void VLCMediaList::removeMedia(int pos){
  libvlc_media_list_lock(current_list);
  libvlc_media_list_remove_index(current_list,pos);
  libvlc_media_list_unlock(current_list);
}

int VLCMediaList::count(){

  return libvlc_media_list_count(current_list);
}

VLCMedia VLCMediaList::getMedia(int pos){

  libvlc_media_t* temp_media = libvlc_media_list_item_at_index(current_list, pos);
  //CHECK if null
  if(temp_media == NULL){
     static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "media doesn't exist in list");
  }
  else
    return VLCMedia(instance,temp_media);
  
}
