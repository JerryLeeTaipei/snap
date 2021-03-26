---
title: "Device-specific initial ALSA state configuration"
table_of_contents: True
---

# Device-specific initial ALSA state configuration

The alsa-utils snap supports importing a mixer state file from the device
gadget snap. It defines a [content
interface](https://snapcraft.io/docs/reference/interfaces) plug which will be
connected to a slot on the gadget snap which then allows both snaps to share
the initial ALSA state configuration.

Here's a simple example of how to modify the gadget snap's `snapcraft.yaml` to
provide the necessary content interface slot:

```
# This part adds the state file to the snap in the path expected by the
# content stanza below
parts:
    alsa-state:
        plugin: dump
        source: alsa
        organize:
            asound.state: alsa-conf/asound.state

slots:
    alsa:
        content: alsa-conf
        interface: content
        read:
            - alsa-conf
```

*NOTE:* The alsa-utils snap expects the content field to specify `alsa-conf`.

After installing the alsa-utils snap you will need to manually connect the
content interface and restart the alsa-utils service, like so:

```
$ snap disable alsa-utils
$ rm -f /var/snap/alsa-utils/common/asound.state
$ snap connect alsa-utils:device-conf <your-snap>:alsa
$ snap enable alsa-utils
```

*NOTE:* Because of a [bug in snapd](https://bugs.launchpad.net/bugs/1645731)
you currently need to take some additional manual steps to ensure that the file
is properly imported. The full set of steps is as follows:

```
$ snap disable alsa-utils
$ rm -f /var/snap/alsa-utils/common/asound.state
$ snap connect alsa-utils:device-conf <your-snap>:alsa
$ /usr/lib/snapd/snap-discard-ns alsa-utils
$ snap enable alsa-utils
```
