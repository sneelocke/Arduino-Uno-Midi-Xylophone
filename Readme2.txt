

A. Kinsman
2/8/20 Additional notes


I've uploaded photos of other parts of the project.  Photo of the USB-MIDI interface cable
easily found on Ebay.   Several more hand drawn schematics.  Note the instrument launcher
pegs are driven by 4 "AA" batteries because to draw that much current from any USB cable would
exceed the available power supply.  The transistors are shorted across the battery pack for
10 ms pulses.  There are no protection diodes on the coils.  After two years no transistor
has failed yet, but they must be taking a beating.   I have a box of several thousand, clearly
a lifetime supply.  


Future improvements...

The instrument uses two power supplies, one USB cable for the Arduino power, and the internal 
battery pack for the launchers.  A second USB cable used for the incoming MIDI stream seems
a bit much.  Ideally a single USB cable providing Arduino power and a MIDI serial stream would
simplify the project.  Or two battery power supplies inside the instrument would make setup
easier.   I have run the instrument on a USB wall charger for the Arduino, and a G2GO connector
from my Samsung S3 cell phone.  I use the Synthesia App on the phone to make the MIDI stream
to feed the instrument.  Works well and is more portable than a PC to drive it.

