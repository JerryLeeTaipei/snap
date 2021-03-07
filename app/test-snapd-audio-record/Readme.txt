

Build:

$ snapcraft --destructive-mode --debug

Install:

$ snap install --dangerous ./test-snapd-audio-record_1_amd64.snap
$ snap connect test-snapd-audio-record:audio-record :audio-record

Test:

$ test-snapd-audio-record.record record.wav
$ test-snapd-audio-record.play record.wav

