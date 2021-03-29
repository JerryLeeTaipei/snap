# alsa-utils

This snap provides a set of utilities to work with the ALSA subsystem
of the Linux kernel to manage audio.

## Development

Building the snap is a matter of

```
 $ snapcraft  --destructive-mode
```

Install the snap
```
sudo snap install alsa-utils_1.1.2-6-dev_amd64.snap --dangerous
```

Execute the snap
```
$ rm *.snap record.wav
$ sudo snap remove alsa-utils
$ sudo snap install alsa-utils_1.2.4-j-17_arm64.snap --dangerous
$ sudo snap connect alsa-utils:alsa :alsa
$ sudo snap connect alsa-utils:home :home
### do some amixer settings: skipped here ###
$ sudo alsa-utils.arecord -f S16_LE -c2 -r48000 /root/snap/alsa-utils/common/record.wav
$ sudo alsa-utils.aplay -f S16_LE -c2 -r48000 /root/snap/alsa-utils/common/record.wav
```
