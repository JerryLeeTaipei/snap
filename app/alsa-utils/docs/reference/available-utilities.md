---
title: "Available utilities"
table_of_contents: True
---

# Available utilities

The alsa-utils snap comes with a wide range of utilities which all serve different
purposes. In the following chapters the available utilites are described shortly.

More documentation about ALSA in general can be found on the [project wiki](http://www.alsa-project.org/main/index.php/Documentation).

## speaker-test

A command-line speaker test tone generator.

**Example:**

```
  # Produce stereo sound from one stereo jack
  $ alsa-utils.speaker-test -c2
```

**Usage:**

```
Usage: speaker-test [OPTION]...
-h,--help	help
-D,--device	playback device
-r,--rate	stream rate in Hz
-c,--channels	count of channels in stream
-f,--frequency	sine wave frequency in Hz
-F,--format	sample format
-b,--buffer	ring buffer size in us
-p,--period	period size in us
-P,--nperiods	number of periods
-t,--test	pink=use pink noise, sine=use sine wave, wav=WAV file
-l,--nloops	specify number of loops to test, 0 = infinite
-s,--speaker	single speaker test. Values 1=Left, 2=right, etc
-w,--wavfile	Use the given WAV file as a test sound
-W,--wavdir	Specify the directory containing WAV files
-m,--chmap	Specify the channel map to override
-X,--force-frequency	force frequencies outside the 30-8000hz range
-S,--scale	Scale of generated test tones in percent (default=80)

Recognized sample formats are: S8 S16_LE S16_BE FLOAT_LE S32_LE S32_BE
```

## alsactl

Can be used to control advanced settings for the ALSA soundcard drivers. It
supports multiple soundcards.

**Example:**

```
  # Store the current driver configuration to the specified file
  $ alsactl store -f /tmp/alsa.state

  # Restore the driver configuration from the state file
  $ alsactl restore -f /tmp/alsa.state
```

**Usage:**

```
Usage: alsactl <options> command

global options:
  -h,--help        this help
  -d,--debug       debug mode
  -v,--version     print version of this program

Available state options:
  -f,--file #      configuration file (default /var/lib/alsa/asound.state)
  -l,--lock        use file locking to serialize concurrent access
  -L,--no-lock     do not use file locking to serialize concurrent access
  -O,--lock-state-file #  state lock file path (default /var/lock/asound.state.lock)
  -F,--force       try to restore the matching controls as much as possible
                     (default mode)
  -g,--ignore      ignore 'No soundcards found' error
  -P,--pedantic    do not restore mismatching controls (old default)
  -I,--no-init-fallback  
                   don't initialize even if restore fails
  -r,--runstate #  save restore and init state to this file (only errors)
                     default settings is 'no file set'
  -R,--remove      remove runstate file at first, otherwise append errors
  -p,--period #    store period in seconds for the daemon command
  -e,--pid-file #  pathname for the process id (daemon mode)

Available init options:
  -E,--env #=#     set environment variable for init phase (NAME=VALUE)
  -i,--initfile #  main configuation file for init phase
                     (default /usr/share/alsa/init/00main)
  -b,--background  run daemon in background
  -s,--syslog      use syslog for messages
  -n,--nice #      set the process priority (see 'man nice')
  -c,--sched-idle  set the process scheduling policy to idle (SCHED_IDLE)

Available commands:
  store     <card>  save current driver setup for one or each soundcards
                      to configuration file
  restore   <card>  load current driver setup for one or each soundcards
                      from configuration file
  nrestore  <card>  like restore, but notify the daemon to rescan soundcards
  init      <card>  initialize driver to a default state
  daemon    <card>  store state periodically for one or each soundcards
  rdaemon   <card>  like daemon but do the state restore at first
  kill      <cmd>   notify daemon to quit, rescan or save_and_quit
  monitor   <card>  monitor control events
```

## amixer

Allows command-line control of the mixer for the ALSA soundcard driver. amixer
supports multiple soundcards.

**Example:**

```
 # Show information about the currently used audio card
 $ amixer info
 Card default 'HDMI'/'HDA Intel HDMI at 0xf1630000 irq 34'
  Mixer name	: 'Intel Haswell HDMI'
  Components	: 'HDA:80862807,80860101,00100000'
  Controls      : 21
  Simple ctrls  : 3
```

**Usage:**

```
Usage: amixer <options> [command]

Available options:
  -h,--help       this help
  -c,--card N     select the card
  -D,--device N   select the device, default 'default'
  -d,--debug      debug mode
  -n,--nocheck    do not perform range checking
  -v,--version    print version of this program
  -q,--quiet      be quiet
  -i,--inactive   show also inactive controls
  -a,--abstract L select abstraction level (none or basic)
  -s,--stdin      Read and execute commands from stdin sequentially
  -R,--raw-volume Use the raw value (default)
  -M,--mapped-volume Use the mapped volume

Available commands:
  scontrols       show all mixer simple controls
  scontents	  show contents of all mixer simple controls (default command)
  sset sID P      set contents for one mixer simple control
  sget sID        get contents for one mixer simple control
  controls        show all controls for given card
  contents        show contents of all controls for given card
  cset cID P      set control contents for one control
  cget cID        get control contents for one control
```

## aplay

A command-line soundfile recorder for the ALSA soundcard driver. It supports
several file formats and multiple soundcards with multiple devices. If
recording with interleaved mode samples the file is automatically split
before the 2GB filesize.

**Example:**

```
  # Play a song stored in a .wav file
  $ aplay /tmp/my-song.wav
```

**Usage:**

```
Usage: aplay [OPTION]... [FILE]...

-h, --help              help
    --version           print current version
-l, --list-devices      list all soundcards and digital audio devices
-L, --list-pcms         list device names
-D, --device=NAME       select PCM by name
-q, --quiet             quiet mode
-t, --file-type TYPE    file type (voc, wav, raw or au)
-c, --channels=#        channels
-f, --format=FORMAT     sample format (case insensitive)
-r, --rate=#            sample rate
-d, --duration=#        interrupt after # seconds
-M, --mmap              mmap stream
-N, --nonblock          nonblocking mode
-F, --period-time=#     distance between interrupts is # microseconds
-B, --buffer-time=#     buffer duration is # microseconds
    --period-size=#     distance between interrupts is # frames
    --buffer-size=#     buffer duration is # frames
-A, --avail-min=#       min available space for wakeup is # microseconds
-R, --start-delay=#     delay for automatic PCM start is # microseconds
                        (relative to buffer size if <= 0)
-T, --stop-delay=#      delay for automatic PCM stop is # microseconds from xrun
-v, --verbose           show PCM structure and setup (accumulative)
-V, --vumeter=TYPE      enable VU meter (TYPE: mono or stereo)
-I, --separate-channels one file for each channel
-i, --interactive       allow interactive operation from stdin
-m, --chmap=ch1,ch2,..  Give the channel map to override or follow
    --disable-resample  disable automatic rate resample
    --disable-channels  disable automatic channel conversions
    --disable-format    disable automatic format conversions
    --disable-softvol   disable software volume control (softvol)
    --test-position     test ring buffer position
    --test-coef=#       test coefficient for ring buffer position (default 8)
                        expression for validation is: coef * (buffer_size / 2)
    --test-nowait       do not wait for ring buffer - eats whole CPU
    --max-file-time=#   start another output file when the old file has recorded
                        for this many seconds
    --process-id-file   write the process ID here
    --use-strftime      apply the strftime facility to the output file name
    --dump-hw-params    dump hw_params of the device
    --fatal-errors      treat all errors as fatal
Recognized sample formats are: S8 U8 S16_LE S16_BE U16_LE U16_BE S24_LE S24_BE U24_LE U24_BE S32_LE S32_BE U32_LE U32_BE FLOAT_LE FLOAT_BE FLOAT64_LE FLOAT64_BE IEC958_SUBFRAME_LE IEC958_SUBFRAME_BE MU_LAW A_LAW IMA_ADPCM MPEG GSM SPECIAL S24_3LE S24_3BE U24_3LE U24_3BE S20_3LE S20_3BE U20_3LE U20_3BE S18_3LE S18_3BE U18_3LE U18_3BE G723_24 G723_24_1B G723_40 G723_40_1B DSD_U8 DSD_U16_LE DSD_U32_LE DSD_U16_BE DSD_U32_BE
Some of these may not be available on selected hardware
The available format shortcuts are:
-f cd (16 bit little endian, 44100, stereo)
-f cdr (16 bit big endian, 44100, stereo)
-f dat (16 bit little endian, 48000, stereo)
```

## aseqnet

An ALSA sequencer client which sends and receives event packets over network.

**Example:**

```
  # Open a server on the current host
  $ aseqnet
```

**Usage:**

```
aseqnet - network client/server on ALSA sequencer
  Copyright (C) 1999 Takashi Iwai
usage:
  server mode: aseqnet [-options]
  client mode: aseqnet [-options] server_host
options:
  -p,--port # : specify TCP port (digit or service name)
  -s,--source addr : read from given addr (client:port)
  -d,--dest addr : write to given addr (client:port)
  -v, --verbose : print verbose messages
  -i, --info : print certain received events
```

## alsatplg

The topology tool which allows to covert a topology text configuration file to
a binary format. See https://alsa-project.org/main/index.php/ALSA_topology for
more details.

**Example:**

```
  $ alsatplg -c test.conf -o output.tplg
```

**Usage:**

```
Usage: alsatplg [OPTIONS]...

-h, --help              help
-c, --compile=FILE      compile file
-v, --verbose=LEVEL     set verbosity level (0...1)
-o, --output=FILE       set output file
```

## arecordmidi

A command-line utility that records a Standard MIDI File from one or more ALSA
sequencer ports.

**Example:**

```
  # Record MIDI to my-song.mid
  $  arecordmidi -p 65:0 my-song.mid
```

**Usage:**

```
Usage: arecordmidi [options] outputfile

Available options:
  -h,--help                  this help
  -V,--version               show version
  -l,--list                  list input ports
  -p,--port=client:port,...  source port(s)
  -b,--bpm=beats             tempo in beats per minute
  -f,--fps=frames            resolution in frames per second (SMPTE)
  -t,--ticks=ticks           resolution in ticks per beat or frame
  -s,--split-channels        create a track for each channel
  -m,--metronome=client:port play a metronome signal
  -i,--timesig=nn:dd         time signature
```

## amidi

amidi is a command-line utility which allows one to receive and send SysEx
(system exclusive) data from/to external MIDI devices. It can also send any
other MIDI commands.

**Example:**

```
  # Send the MIDI commands in my_settings.syx to port hw:0.
  $  amidi -p hw:0 -s my_settings.syx
```

**Usage:**

```
Usage: amidi options

-h, --help             this help
-V, --version          print current version
-l, --list-devices     list all hardware ports
-L, --list-rawmidis    list all RawMIDI definitions
-p, --port=name        select port by name
-s, --send=file        send the contents of a (.syx) file
-r, --receive=file     write received data into a file
-S, --send-hex="..."   send hexadecimal bytes
-d, --dump             print received data as hexadecimal bytes
-t, --timeout=seconds  exits when no data has been received
                       for the specified duration
-a, --active-sensing   don't ignore active sensing bytes
```

## alsaloop

Allows to create a PCM loopback between a PCM capture device and a PCM playback device.

alsaloop supports multiple soundcards, adaptive  clock synchronization, adaptive
rate resampling using the samplerate library (if available in the system). Also,
mixer controls can  be redirected from one card to another (for example Master and PCM).

**Example:**

```
  # Loop audio from one hardware device to another one
  $ alsaloop -C hw:0,0 -P hw:1,0
```

**Usage:**

```
Usage: alsaloop [OPTION]...

-h,--help      help
-g,--config    configuration file (one line = one job specified)
-d,--daemonize daemonize the main process and use syslog for errors
-P,--pdevice   playback device
-C,--cdevice   capture device
-X,--pctl      playback ctl device
-Y,--cctl      capture ctl device
-l,--latency   requested latency in frames
-t,--tlatency  requested latency in usec (1/1000000sec)
-f,--format    sample format
-c,--channels  channels
-r,--rate      rate
-n,--resample  resample in alsa-lib
-A,--samplerate use converter (0=sincbest,1=sincmedium,2=sincfastest,
                               3=zerohold,4=linear)
-B,--buffer    buffer size in frames
-E,--period    period size in frames
-s,--seconds   duration of loop in seconds
-b,--nblock    non-block mode (very early process wakeup)
-S,--sync      sync mode(0=none,1=simple,2=captshift,3=playshift,4=samplerate,
                         5=auto)
-a,--slave     stream parameters slave mode (0=auto, 1=on, 2=off)
-T,--thread    thread number (-1 = create unique)
-m,--mixer	redirect mixer, argument is:
		    SRC_SLAVE_ID(PLAYBACK)[@DST_SLAVE_ID(CAPTURE)]
-O,--ossmixer	rescan and redirect oss mixer, argument is:
		    ALSA_ID@OSS_ID  (for example: "Master@VOLUME")
-e,--effect    apply an effect (bandpass filter sweep)
-v,--verbose   verbose mode (more -v means more verbose)
-w,--workaround use workaround (serialopen)
-U,--xrun      xrun profiling
-W,--wake      process wake timeout in ms
-z,--syslog    use syslog for errors

Recognized sample formats are: S8 U8 S16_LE S16_BE U16_LE U16_BE S24_LE S24_BE U24_LE U24_BE S32_LE S32_BE U32_LE U32_BE FLOAT_LE FLOAT_BE FLOAT64_LE FLOAT64_BE IEC958_SUBFRAME_LE IEC958_SUBFRAME_BE MU_LAW A_LAW IMA_ADPCM MPEG GSM SPECIAL S24_3LE S24_3BE U24_3LE U24_3BE S20_3LE S20_3BE U20_3LE U20_3BE S18_3LE S18_3BE U18_3LE U18_3BE G723_24 G723_24_1B G723_40 G723_40_1B DSD_U8 DSD_U16_LE DSD_U32_LE DSD_U16_BE

Tip #1 (usable 500ms latency, good CPU usage, superb xrun prevention):
  alsaloop -t 500000
Tip #2 (superb 1ms latency, but heavy CPU usage):
  alsaloop -t 1000
```

## alsaucm

The ALSA use case manager.

**Example:**

```
  # List available ALSA cards
  $ alsaucm listcards
  0: DAISY-I2S
    Daisy internal card
  1: GoogleNyan
    Nyan internal card
  2: Manta-I2S
  3: Manta-SPDIF
  4: PAZ00
    PAZ00 alc5632
  5: PandaBoard
  6: PandaBoardES
  7: SDP4430
  8: Tuna
  9: apq8064-tabla-snd-card
  10: broadwell-rt286
  11: msm8974-taiko-mtp-snd-card
  12: tegra-rt5640
  13: tegraalc5632
```

**Usage:**

```
Usage: alsaucm <options> [command]

Available options:
  -h,--help                  this help
  -c,--card NAME             open card NAME
  -i,--interactive           interactive mode
  -b,--batch FILE            batch mode (use '-' for the stdin input)
  -n,--no-open               do not open first card found

Available commands:
  open NAME                  open card NAME
  reset                      reset sound card to default state
  reload                     reload configuration
  listcards                  list available cards
  list IDENTIFIER            list command
  get IDENTIFIER             get string value
  geti IDENTIFIER            get integer value
  set IDENTIFIER VALUE       set string value
  h,help                     help
  q,quit                     quit
```

## aconnect

A utility to connect and disconnect two existing ports on ALSA sequencer system.
The ports with the arbitrary subscription permission, such as created by aseqview,
can be connected to any (MIDI) device ports using aconnect.

**Example:**

```
  # Connect port 64:0 to 65:0
  $ aconnect 64:0 65:0
```

**Usage:**

```
aconnect - ALSA sequencer connection manager
Copyright (C) 1999-2000 Takashi Iwai
Usage:
 * Connection/disconnection between two ports
   aconnect [-options] sender receiver
     sender, receiver = client:port pair
     -d,--disconnect     disconnect
     -e,--exclusive      exclusive connection
     -r,--real #         convert real-time-stamp on queue
     -t,--tick #         convert tick-time-stamp on queue
 * List connected ports (no subscription action)
   aconnect -i|-o [-options]
     -i,--input          list input (readable) ports
     -o,--output         list output (writable) ports
     -l,--list           list current connections of each port
 * Remove all exported connections
     -x, --removeall
```

## iecset

A small utility to set or dump the IEC958 (or so-called "S/PDIF") status bits of
the specified sound card via ALSA control API.

**Example:**

```
  # Displays the current IEC958 status bits on the second card.
  $ iecset -Dhw:1
```

**Usage:**

```
Usage: iecset [options] [cmd arg...]
Options:
    -D device   specifies the control device to use
    -c card     specifies the card number to use (equiv. with -Dhw:#)
    -n number   specifies the control index number (default = 0)
    -x          dump the dump the AESx hex code for IEC958 PCM parameters
    -i          read commands from stdin
Commands:
    professional (common)
	off = consumer mode, on = professional mode
    audio (common)
	on = audio mode, off = non-audio mode
    rate (common)
	sample rate in Hz (0 = not indicated)
    emphasis (common)
	0 = none, 1 = 50/15us, 2 = CCITT
    lock (prof.)
	off = rate unlocked, on = rate locked
    sbits (prof.)
	sample bits 2 = 20bit, 4 = 24bit, 6 = undef
    wordlength (prof.)
	0=no, 2=22-18bit, 4=23-19bit, 5=24-20bit, 6=20-16bit
    category (consumer)
	0-0x7f
    copyright (consumer)
	off = non-copyright, on = copyright
    original (consumer)
	off = 1st-gen, on = original
```

## alsabat

ALSABAT(ALSA  Basic  Audio  Tester) is a simple command-line utility intended to
help automate audio driver and sound server testing with little human interaction.
ALSABAT can be used to test audio quality, stress test features and test audio
before and after PM state changes.

**Example:**

```
  # Start automated testing
  $ alsabat
```

**Usage:**

```
Usage: alsabat [-options]...

  -h, --help             this help
  -D                     pcm device for both playback and capture
  -P                     pcm device for playback
  -C                     pcm device for capture
  -f                     sample format
  -c                     number of channels
  -r                     sampling rate
  -n                     frames to playback or capture
  -k                     parameter for frequency detecting threshold
  -F                     target frequency
  -p                     total number of periods to play/capture
      --log=#            file that both stdout and strerr redirecting to
      --file=#           file for playback
      --saveplay=#       file that storing playback content, for debug
      --local            internal loop, set to bypass pcm hardware devices
Recognized sample formats are: U8 S16_LE S24_3LE S32_LE
The available format shotcuts are:
-f cd (16 bit little endian, 44100, stereo)
-f dat (16 bit little endian, 48000, stereo)
```

## aseqdump

A command-line utility that prints the sequencer events it receives as text.

**Example:**

```
  # Dump all incoming sequencer events
  $ aseqdump
```

**Usage:**

```
Usage: aseqdump [options]

Available options:
  -h,--help                  this help
  -V,--version               show version
  -l,--list                  list input ports
  -p,--port=client:port,...  source port(s)
```

## aplaymidi

aplaymidi is  a command-line  utility that plays the specified MIDI file(s)
to one or more ALSA sequencer ports.

**Example:**

```
  # Play MIDI from my my-song.mid
  $  aplaymidi -p 65:0 my-song.mid
```

**Usage:**

```
Usage: aplaymidi -p client:port[,...] [-d delay] midifile ...
-h, --help                  this help
-V, --version               print current version
-l, --list                  list all possible output ports
-p, --port=client:port,...  set port(s) to play to
-d, --delay=seconds         delay after song ends
```

## alsamixer

alsamixer is an ncurses mixer program for use with the ALSA soundcard drivers.
It supports multiple soundcards with multiple devices.

**Example:**

```
  # Start the ncurses based UI
  $ alsamixer
```

**Usage:**

```
Usage: alsamixer [options]
Useful options:
  -h, --help              this help
  -c, --card=NUMBER       sound card number or id
  -D, --device=NAME       mixer device name
  -V, --view=MODE         starting view mode: playback/capture/all
Debugging options:
  -g, --no-color          toggle using of colors
  -a, --abstraction=NAME  mixer abstraction level: none/basic
```

## arecord

A command-line soundfile recorder for the ALSA soundcard driver. It supports
several file formats and multiple soundcards with multiple devices. If recording
with interleaved mode samples the file is automatically split before the 2GB filesize.

**Example:**

```
  # Record currently played audio to a file
  $ arecord /tmp/recorded-audio.wav
```

**Usage:**

```
Usage: arecord [OPTION]... [FILE]...

-h, --help              help
    --version           print current version
-l, --list-devices      list all soundcards and digital audio devices
-L, --list-pcms         list device names
-D, --device=NAME       select PCM by name
-q, --quiet             quiet mode
-t, --file-type TYPE    file type (voc, wav, raw or au)
-c, --channels=#        channels
-f, --format=FORMAT     sample format (case insensitive)
-r, --rate=#            sample rate
-d, --duration=#        interrupt after # seconds
-M, --mmap              mmap stream
-N, --nonblock          nonblocking mode
-F, --period-time=#     distance between interrupts is # microseconds
-B, --buffer-time=#     buffer duration is # microseconds
    --period-size=#     distance between interrupts is # frames
    --buffer-size=#     buffer duration is # frames
-A, --avail-min=#       min available space for wakeup is # microseconds
-R, --start-delay=#     delay for automatic PCM start is # microseconds
                        (relative to buffer size if <= 0)
-T, --stop-delay=#      delay for automatic PCM stop is # microseconds from xrun
-v, --verbose           show PCM structure and setup (accumulative)
-V, --vumeter=TYPE      enable VU meter (TYPE: mono or stereo)
-I, --separate-channels one file for each channel
-i, --interactive       allow interactive operation from stdin
-m, --chmap=ch1,ch2,..  Give the channel map to override or follow
    --disable-resample  disable automatic rate resample
    --disable-channels  disable automatic channel conversions
    --disable-format    disable automatic format conversions
    --disable-softvol   disable software volume control (softvol)
    --test-position     test ring buffer position
    --test-coef=#       test coefficient for ring buffer position (default 8)
                        expression for validation is: coef * (buffer_size / 2)
    --test-nowait       do not wait for ring buffer - eats whole CPU
    --max-file-time=#   start another output file when the old file has recorded
                        for this many seconds
    --process-id-file   write the process ID here
    --use-strftime      apply the strftime facility to the output file name
    --dump-hw-params    dump hw_params of the device
    --fatal-errors      treat all errors as fatal
Recognized sample formats are: S8 U8 S16_LE S16_BE U16_LE U16_BE S24_LE S24_BE U24_LE U24_BE S32_LE S32_BE U32_LE U32_BE FLOAT_LE FLOAT_BE FLOAT64_LE FLOAT64_BE IEC958_SUBFRAME_LE IEC958_SUBFRAME_BE MU_LAW A_LAW IMA_ADPCM MPEG GSM SPECIAL S24_3LE S24_3BE U24_3LE U24_3BE S20_3LE S20_3BE U20_3LE U20_3BE S18_3LE S18_3BE U18_3LE U18_3BE G723_24 G723_24_1B G723_40 G723_40_1B DSD_U8 DSD_U16_LE DSD_U32_LE DSD_U16_BE DSD_U32_BE
Some of these may not be available on selected hardware
The available format shortcuts are:
-f cd (16 bit little endian, 44100, stereo)
-f cdr (16 bit big endian, 44100, stereo)
-f dat (16 bit little endian, 48000, stereo)
```
