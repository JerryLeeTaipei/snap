# "/usr/include/openssl/e_os2.h:13:11: fatal error: openssl/opensslconf.h: No such file or directory"
# ==> 
#     $ sudo ln -s /usr/include/x86_64-linux-gnu/openssl/opensslconf.h /usr/include/openssl/opensslconf.h
#

all:
	snapcraft --destructive-mode --enable-experimental-target-arch --target-arch=arm64

#prepare:
#	sudo apt install gcc-aarch64-linux-gnu

#alsa-lib:
#	snapcraft build alsa-lib --destructive-mode --enable-experimental-target-arch --target-arch=arm64

#alsa-utils:
#	snapcraft build alsa-utils --destructive-mode --enable-experimental-target-arch --target-arch=arm64

clean:
	snapcraft clean --destructive-mode
