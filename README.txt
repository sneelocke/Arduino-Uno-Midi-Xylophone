
Xylophone project notes

4/8/18  The goal of this project is to make a MIDI controlled xylophone (actually
glockenspiel) from a $25 instrument purchased on Craigslist.  In the end I decided to 
use a $4 knockoff Arduino Nano, and two IO expander chips to get all the IO lines required.
The MIDi library used comes from a MIT archive.  

MIDI library - MIT License Copyright (c) 2016 Francois Best

It reads MIDI from the Arduino RX line
so a MIDI connector and opto isolator is required to convey MIDI from other sources to the
Arduino's RX pin.  I drive this setup with the Windows media player which if it sees a MIDI
device plugged into a USB port will send MIDI codes to the device, not play the coresponding
sounds on the computer's speakers.  To get this working I had to purchase a USB MIDI adapter
so the Media player would send the MIDI codes out this adapter's MIDI out connector, and that
connector is plugged into my instrument's MIDI input connector.

4/10/18  Some Arduino boards have a USB interface chip with ATMEL 16U2 stamped on it.
These can be reflashed so when plugged into a PC computer they look like a midi device.
This is called "USBMIDI" and makes the device a "USB MIDI" device.   Windows will then 
send it midi codes thinking it is a real music instrument that can receive MIDI.  

This removes the need for a USB to MIDI adapter cable and the interface chips associated
with a MIDI IN port on the Arduino project.  There are also Arduino boards with two USB
connectors allowing them to use the second USB connector in "NATIVE USB" mode.  These are
the Due, Zero, and 101 board.

This video describes this...    https://www.youtube.com/watch?v=tmFtMAZOGZo
This descibes USB MIDI HOST/DEVICE...   https://youtu.be/neXswJJcatc

Making this change prohibits flashing future sketches into your Arduino board.   The board
can still be reflashed back to its original state with several tools.  

hiduino is the code flashed to the USB controller chip.  This involves using an Arduino as an
ICSP (In circuit Serial Programmer).   I'm in too much a hurry to figure out this method, but
will eventually persue a solution that doesn't require a USB->MIDI adaptor or opto isolators and
MIDI input connectors.  Not sure how in that design one sends MIDI data, but some utility must exist
to send them out through a USB cable to the Arduino.  Bluetooth connections are also possible
removing the need for all cables.

My cheap clones don't have the 16U2 or 8U2 chips, so I was forced to go the adaptor route. My next
MIDI project will probably use an Arduino Zero.

To learn more...  Search "USB MIDI DEVICE", or "USB MIDI HOST" and start reading. 

My code is compiled with Arduino IDE V 1.0.5
I use the MIDI library described above.
I use the Adafruit MCP23017 I2C I/O expander chip library.

parts come from...

digikey.com
jameco.com

4/20/18  First music out of the device and it sounds really good!  It only has
12 notes as I'm waiting for expander chips to arrive to add the rest of the notes.
I need more drinking straws from Taco Bell.  They are the right size and clear. 60 turns of any 
thin magnet wire makes perfect launchers with a signal transistor.  The wooden pegs are held
at the right high with spacers in the holes and a tiny cobalt magnet is superglued to the
bottom of the pegs to make them launch.  Careful assembly is required... all coils same direction,
all magnets glued to pegs with correct pole up.  Solder all coils in the same orientation.
Smaller diameter straws produce stronger coils, and use smaller(cheaper and ligher magnets).  
Transparent straws allow curious kids to see what is really going on.  When plastic straws
become yet another forbidden product, paper straws will work. There is a youtube that
describes how to make your own straws from a 2 liter bottle as a last resort!

4/21/18 Second batch of 5 straws from Taco Bell produced only 2 of the original
diameter.  Not sure why they come in two diameters.  This could be a problem.
Working on 16 note version with a single expander chip.  

4/22/18 Third batch of 7 straws produced 4 of the correct size.
Coded in the MCP23017 I2C expander chips.  Made 12 new coils and mallets.  Last is
to wire in the expander chips.

Got 28 of the 30 notes working with the expander chips.  Now running Xylo_30_notes
code.   Last two notes will require me to cut into the xylophone to gain access to 
them from below.  Metal brackets interfere.  Really sounds great with 28 notes!

4/25/18 ALL 30 notes working and Irish folk songs sound great.  This is a wonderful
music box.  A really welcome addition to my coffee table. 

Some of the included images are from other similar projects on the NET.  They should be
given credit where credit is due.  I can't remember where all the details came from, but
thanks to all who provided input.

Several youtube videos exist.  This is one...   https://youtu.be/NnbJBZafTNM

Enjoy.  Hope others build one.  -Andy




