
all:
	snapcraft build alsa-lib --destructive-mode --enable-experimental-target-arch --target-arch=armhf

prepare:
	sudo apt install gcc-aarch64-linux-gnu

alsa-lib:
	snapcraft build alsa-lib --destructive-mode --enable-experimental-target-arch --target-arch=armhf

alsa-utils:
	snapcraft build alsa-utils --destructive-mode --enable-experimental-target-arch --target-arch=armhf

clean:
	snapcraft clean --destructive-mode
