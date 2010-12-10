require './libvlc'

a = Libvlc::VLCMedia.new
a.setMedia("example.avi")
b = a.getPlayer

