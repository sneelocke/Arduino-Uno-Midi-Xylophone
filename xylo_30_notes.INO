/* A,Kinsman - read midi data and output to one of the 30 available bits used to control
 the 30 keys on the xylophone configuration to be used when MIDI output
 cable arrives. 
 
 MCP23017 I/O expander chips arrived. Now 30 notes working.
 
 MIDI interface cable arrived, so instrument can receive MIDI from Windows Media Player.
 
 We can't use RX,TX serial debug as MIDI data is arriving on it for this MIDI library.
 
 4/15/18  compiled on version 1.0.5 Arduino IDE
          compiled and used on Arduino UNO
          compiled and used on Arduino NANO - final instrument processor.
 */

#include <MIDI.h>                      // 2016 Francois Best MIT MIDI library
#include <Wire.h>
#include <Adafruit_MCP23017.h>

MIDI_CREATE_DEFAULT_INSTANCE();        // init MIDI library

byte note;
byte velocity;
byte channel;
byte pin;            // selected from table

#define MIN_NOTE 55
#define MAX_NOTE 84

// NOTES FOUND ON MY XYLOPHONE
// Notes supported by I/O pin - MIDDLE C is 60 or C4
// the real lowest note on the xylophone is two octives above the MIDI notes requested.
const byte pins[]={ 
  //NOTE  G     A     B  C     D     E  F     G     A     B  C     D     E  F     G     A     B  C
  //MIDI 55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84
          0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13};

// specify which expander chip the music note is located on          
const byte bank[]={
  //NOTE  G     A     B  C     D     E  F     G     A     B  C     D     E  F     G     A     B  C
  //MIDI 55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


//int statusLed = 3;   // use if you want a status LED on PIN 3 - CAN'T USE THIS

Adafruit_MCP23017 mcp0;          // bank 0
Adafruit_MCP23017 mcp1;          // bank 1

Adafruit_MCP23017 *mcps[] = { 
  &mcp0, &mcp1 };    // pointers to banks

void setup() {

  //  Serial.begin(115200);      // MIDI library is in control of the RX/TX lines

  mcp0.begin(0);                  // start first I2C expander chip
  mcp1.begin(1);                  // start second I2C expander chip

  // define output pins and set them low.
  for(int i=0;i<=15;i++)
  {
    mcp0.pinMode(i, OUTPUT);
    mcp0.digitalWrite(i,LOW);
    mcp1.pinMode(i, OUTPUT);
    mcp1.digitalWrite(i,LOW);
  }

  // Initiate MIDI communications, listen to all incoming channels    
  // only my instrument so turn off thru to boost speed - frees up one I/O bit (TX) too.
  MIDI.begin(MIDI_CHANNEL_OMNI);   
  MIDI.turnThruOff(); 
  MIDI.setHandleNoteOn(HandleNoteOn);  // set note on

    //  MIDI.setHandleNoteOff(HandleNoteOff);  // set note off, no need instrument doesn't support
}

// MIDI library does a call back on this registered routine to request a note start playing
void HandleNoteOn(byte channel, byte note, byte velocity){    //turn note on if note signal is recieved.

#ifdef UNDEF
  Serial.print("Chan ");          // debug
  Serial.print(channel,DEC);
  Serial.print(" Note ");
  Serial.print(note,DEC);
  Serial.print(" Vel ");
  Serial.println(velocity,DEC);
#endif

  if( note>=MIN_NOTE && note<=MAX_NOTE)    // process only notes instrument can handle
  {
    pin=pins[note-MIN_NOTE];       // I/O pin from table
    mcps[bank[note-MIN_NOTE]]->digitalWrite(pin,HIGH);  // pulse the actuator
    delay(10);                   // use velocity to determine length coil pulse?
    mcps[bank[note-MIN_NOTE]]->digitalWrite(pin,LOW);
  }
}

void loop() {
  MIDI.read();   // Call MIDI.read the fastest you can for real-time performance.
}












