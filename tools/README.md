# tools

This directory contains tools I put together while creating the example programs.

## note_type_0

Generate the data values for a type 0 note, which has a fixed frequency and duration.

```sh
./note_type_0 <channel-0-to-3> <freq-in-hz> <atn> <duration-in-frames>
```

* **channel-0-to-3** The channel number, 0 = noise, 1-3 = tone channels
* **freq-in-hz** The frequency in hertz
* **atn** the Attenuation value from 0 to 15, larger is softer.
* **duration-in-frames** The desired duration in frames (16.67ms, aka 1/60th second)

Building:

```sh
gcc -onote_type_0 note_type_0.c
```
