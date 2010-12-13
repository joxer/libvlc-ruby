#include "vlcdummyoutput.hpp"


void* lock(void *data, void **p_pixels){

  Ctx *ctx = static_cast<Ctx*>(data);

  SDL_LockMutex(ctx->mutex);
  SDL_LockSurface(ctx->surf);
  *p_pixels = ctx->surf->pixels;
  return NULL;
  

}
void unlock(void *data, void *id, void *const *p_pixels){
  Ctx *ctx = static_cast<Ctx*>(data);

 
  uint32_t *pixels = static_cast<uint32_t*>(*p_pixels);
  int x, y;

  SDL_UnlockSurface(ctx->surf);
  SDL_UnlockMutex(ctx->mutex);
  
  assert(id == NULL);
  
  
}
void display(void *data, void *id){

  
  (void) data;
  assert(id == NULL);
}



VLCDummyOutput::VLCDummyOutput(libvlc_media_t* media){

  chroma = "RV16";
  width = 1024;
  height = 768;
  pitch = width*2;

  current_media = media;
  done = 0;
  action = 0;
  pause = 0;
  n = 0;
  
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD) == -1)
    {
      printf("cannot initialize SDL\n");
    }
  
  empty = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height,  32, 0, 0, 0, 0);

}
void VLCDummyOutput::playMedia(){

  mp = libvlc_media_player_new_from_media(current_media);
  if(mp == NULL){
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "can't create media");
  }
  libvlc_video_set_callbacks(mp,
			     lock,
			     unlock,
			     display,
			     &ctx);
  libvlc_video_set_format(mp, chroma,width, height, pitch);
  if(libvlc_media_player_play(mp) == -1){
    static VALUE vlcerror = rb_define_class("VLCException", rb_eStandardError);
    rb_raise(vlcerror, "can't create media");
  }
    
    ctx.surf = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height,
				    16, 0, 0, 0, 0);
  
  ctx.mutex = SDL_CreateMutex();


  
  screen = SDL_SetVideoMode(width, height, 0, SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF);
  if(!screen)
    {
      printf("cannot set video mode\n");

    }

  while(!done)
    { 
      action = 0;
      
      while( SDL_PollEvent( &event ) ) 
	{ 
	  switch(event.type)
	    {
	    case SDL_QUIT:
	      done = 1;
	      break;
	    case SDL_KEYDOWN:
	      action = event.key.keysym.sym;
	      break;
	    }
	}
      
      switch(action)
	{
	case SDLK_ESCAPE:
	  done = 1;
	  break;
	case SDLK_RETURN:
	  break;
	case ' ':
	  libvlc_media_player_pause(mp);
	  break;
	}
      
      SDL_LockMutex(ctx.mutex);
      SDL_BlitSurface(ctx.surf, NULL, screen, NULL);
      SDL_UnlockMutex(ctx.mutex);
      
      SDL_Flip(screen);
      SDL_Delay(10);
      
      SDL_BlitSurface(empty, NULL, screen, &rect);
      
    }
      libvlc_media_player_stop(mp);
}


void VLCDummyOutput::setOption(const char* cchroma, int w,int h,int p){

  chroma = cchroma;
  width = w;
  height = h;
  pitch = p;

}


VLCDummyOutput::~VLCDummyOutput(){
  libvlc_media_player_release(mp);
  SDL_DestroyMutex(ctx.mutex);
  SDL_FreeSurface(ctx.surf);
  SDL_FreeSurface(empty);
}
