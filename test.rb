require './libvlc'

a = Libvlc::LibVLC.new

a.addMedia("example.avi").playMedia

