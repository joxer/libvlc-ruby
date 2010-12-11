require './libvlc.so'

# Extension for ruby of libvlc written in c++ using swig.

module LibVLC
  
  #Core class of libvlc that holds all the core functions like creation of media and playlist and setting the user agent

  class LibVLC

    # Allocate a new LibVLC in memory
    
    def initialize()
      
      @lib = Libvlc::LibVLC.new
      
    end

    # Set the user agent of class, name is the application's name and http the http user agent

    def setUserAgent(name,http)
      @lib.setUserAgent(name,http)
    end
    
    # Return the version of current libvlc

    def getVersion
      @lib.getVersion
    end

    # Create a new VLCMedia class with the path passed as argument

    def addMedia(path)
      @lib.addMedia(path)
    end

    # Create a new Playlist and return it

    def createPlayList
      @lib.createPlayList
    end

  end

  # Implementation of a media, this class holds all information about the media file, you can try to have a dummy output using playMedia.


  class VLCMedia

    def initialize
      @media = Libvlc::VLCMedia.new
    end

    # Return a MediaPlayer

    def playMedia
      
      @media.playMedia

    end

    # Set the current media to argument

    def setMedia(path)

      @media.setMedia(path)

    end

    # Return the information passed as argument
    # Argument can be: Title, Description, Url, Artist

    def getMeta(meta)

      @media.getMeta(meta)

    end

  end

  # Implementation of vlc media player for linux

  class VLCMediaPlayer

    def initialize

      @player = VLCMediaPlayer.new

    end

    # Set current XWindow id for output

    def setXWindow(id)
      @player.setXWindow(id)
    end

    # Play media

    def play

      @player.play

    end

    # Stop Media

    def stop

      @player.stop

    end

    # Set to passed chapter
    
    def setChapter(n)

      @player.setChapter(n)

    end

    # Set stream to passed position

    def setPosition(pos)

      @player.setPosition(pos)
      
    end

    # Return the FPS of current stream

    def getFPS

      @player.getFps

    end

  end

  # Implementation of vlc's playlist

  class VLCMediaList

    def initialize

      @list =Libvlc::VLCMediaList.new

    end

    # This method requires the absolute path of media and then is added to playlist

    def addMedia(path)
      
      @list.addMedia(path)
      

    end
    
    # This method removes the n-th element from the playlist

    def removeMedia(n)
      
      @list.remove(n)
      
    end

    # return the VLCMedia at the n-th position in playlist

    def getMedia(n)

      @list.getMedia(n)

    end

    # Return the size of the current playlist

    def count

      @list.count

    end

  end
  

end
