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
snap connect alsa-utils:alsa :alsa
snap connect alsa-utils:home :home
```
