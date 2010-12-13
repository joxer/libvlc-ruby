require "./"+File.dirname(__FILE__) + '/../libvlc'

# 3 ways to open a file

include Libvlc

vlc = LibVLC.new
begin
  vlc.addMedia("example.avi")
rescue
  puts "media not found --- LibVLC"
end

media = VLCMedia.new
begin
  media.setMedia("example.avi")
rescue
  puts "media not found --- VLCMEDIA"
end 

playlist = VLCMediaList.new
begin
  playlist.addMedia("example.avi").getMedia(0)
  
rescue
  puts "media not found --- VLCMediaList"
end


