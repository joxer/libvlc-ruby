require './libvlc'

b = Libvlc::VLCMediaList.new()
b.addMedia("example.avi")
b.addMedia("example.avi")
b.getMedia(1).playMedia
