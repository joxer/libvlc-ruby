require "./"+File.dirname(__FILE__) + '/../libvlc'

include Libvlc
playlist = VLCMediaList.new
playlist.addMedia("example.avi")
playlist.addMedia("example.avi")
playlist.addMedia("example.avi")
puts "list size: #{playlist.count}"
puts "removing media"
playlist.removeMedia(0)
puts "list size: #{playlist.count}"
puts "removing media"
playlist.removeMedia(0)
puts "list size: #{playlist.count}"
puts "removing media"
playlist.removeMedia(0)
puts "list size: #{playlist.count}"
