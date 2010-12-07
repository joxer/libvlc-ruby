require 'libvlc'

a = Libvlc::LibVLC.new

p a.addMedia("examplea.avi").playMedia

