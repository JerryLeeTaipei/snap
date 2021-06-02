# "Failed to update the package cache: Some files could not be downloaded:"
# Prefix "[arch=amd64]" to https://. For ex., deb [arch=amd64] https:

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
