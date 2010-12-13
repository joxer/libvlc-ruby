require "./"+File.dirname(__FILE__) + '/../libvlc'

include Libvlc

media = VLCMedia.new
begin
  media.setMedia("example.avi")
  media.playMedia #using dummy output
rescue
  puts "media not found --- VLCMEDIA"
end 
