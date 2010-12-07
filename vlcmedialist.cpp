#include "vlcmedialist.hpp"
  
VLCMediaList::VLCMediaList(libvlc_instance_t* instance){

  current_instance = instance;
  current_list = libvlc_media_list_new(instance);

}
VLCMediaList::~VLCMediaList(){
  
  //if i enable this it will cause abort of program

  //libvlc_media_list_release(current_list);

}
void VLCMediaList::addMedia(const char* position){


  libvlc_media_t* added_media = libvlc_media_new_location(current_instance, position);
  
  if(added_media == NULL){
    throw VLCRubyException();
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
  return VLCMedia(temp_media);
  
}
