require './libvlc.so'
module LibVLC
  
  class LibVLC
    
    def initialize()
      
      @lib = Libvlc::LibVLC.new
      
    end

    def setUserAgent(name,http)
      @lib.setUserAgent(name,http)
    end
    
    def getVersion
      @lib.getVersion
    end

    def addMedia(path)
      @lib.addMedia(path)
    end

    def createPlayList
      @lib.createPlayList
    end

  end


  class VLCMedia

    def initialize
      @media = Libvlc::VLCMedia.new
    end

    def playMedia
      
      @media.playMedia

    end

    def setMedia(path)

      @media.setMedia(path)

    end

    def getMeta(meta)

      @media.getMeta(meta)

    end

  end

  class VLCMediaPlayer

    def initialize

      @player = VLCMediaPlayer.new

    end

    def setXWindow(id)
      @player.setXWindow(id)
    end

    def play

      @player.play

    end

    def stop

      @player.stop

    end

    def setChapter(n)

      @player.setChapter(n)

    end

    def setPosition(pos)

      @player.setPosition(pos)
      
    end

    def getFPS

      @player.getFps

    end

  end

  class VLCMediaList

    def initialize

      @list =Libvlc::VLCMediaList.new

    end

    def addMedia(path)
      
      @list.addMedia(path)
      

    end
    
    def removeMedia(n)
      
      @list.remove(n)
      
    end

    def getMedia(n)

      @list.getMedia(n)

    end

    def count

      @list.count

    end

  end
  

end
