/*Werkstatt Arpeggiator 
  Moog Music Inc. 2014
  Written by Chris David Howe
  Circuit consists of one 10kΩ resistor and a 2.2µf capacitor low pass filter.
*/

#include <werkstatt.h>

const int POTENTIOMETER_PIN0 = A0; // Arduino pin connected to Potentiometer pin 0
const int POTENTIOMETER_PIN1 = A1; // Arduino pin connected to Potentiometer pin 1
const int POTENTIOMETER_PIN4 = A4; // Arduino pin connected to Potentiometer pin 2



arpeggiator arpeggiator(6); //initiate and name the arpeggiator class (Output pin)

/* 
notes are assigned in intervals: tonic, minor2nd, major2nd, minor3rd,
major3rd, fourth, tritone, fifth, minor6th, major6th, minor7th,
major7th, octave. 
*/
  int notes[] = {tonic, fifth, minor3rd, octave}; // VCO EXP config


// note values: w, h, q, qt, e, et, sx, sxt, th, sxf 
  int note_values[] = {e,e,e,e}; //VCO EXP config

  
void setup() {
  Serial.begin(9600);
}      



void loop() {
    int analogValue = analogRead(POTENTIOMETER_PIN0); // read the input on analog pin
    int analogValue1 = analogRead(POTENTIOMETER_PIN1); // read the input on analog pin
    int analogValue4 = analogRead(POTENTIOMETER_PIN4); // read the input on analog pin


    byte mappedValue = map(analogValue, 0, 1023, 1, 13);
    byte mappedValue1 = map(analogValue1, 0, 1023, 1, 13);
    int mappedValue4 = map(analogValue4, 0, 677, 90, 400);

    Serial.println(mappedValue);
    switch (mappedValue){
    case 1:
      notes[0] = tonic;
      break;
    case 2:
      notes[0] = minor2nd;
      break;
    case 3:
      notes[0] = major2nd;
      break;
    case 4:
      notes[0] = minor3rd;
      break;
    case 5:
      notes[0] = major3rd;
      break;
    case 6:
      notes[0] = fourth;
      break;
    case 7:
      notes[0] = tritone;
      break;
    case 8:
      notes[0] = fifth;
      break;
    case 9:
      notes[0] = minor6th;
      break;
    case 10:
      notes[0] = major6th;
      break;
    case 11:
      notes[0] = minor7th;
      break;
    case 12:
      notes[0] = major7th;
      break;
    case 13:
      notes[0] = octave;
      break;
    }



     switch (mappedValue1){
    case 1:
      notes[1] = tonic;
      break;
    case 2:
      notes[1] = minor2nd;
      break;
    case 3:
      notes[1] = major2nd;
      break;
    case 4:
      notes[1] = minor3rd;
      break;
    case 5:
      notes[1] = major3rd;
      break;
    case 6:
      notes[1] = fourth;
      break;
    case 7:
      notes[1] = tritone;
      break;
    case 8:
      notes[1] = fifth;
      break;
    case 9:
      notes[1] = minor6th;
      break;
    case 10:
      notes[1] = major6th;
      break;
    case 11:
      notes[1] = minor7th;
      break;
    case 12:
      notes[1] = major7th;
      break;
    case 13:
      notes[1] = octave;
      break;
    }
    
for (int i = 0; i < ( sizeof(notes)/sizeof(int) ); i++)
  {
   //define a BPM and run the arpeggiator.play function
   //Serial.println(mappedValue4);
   arpeggiator.play(mappedValue4, notes[i], note_values[i]); 
   }
}
