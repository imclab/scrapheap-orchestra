#include "StepOsc.h"
#include "OscUtils.h"
#include "Osc.h"
#include "Runner.h"
#include "MidiMap.h"


void setup() {
  
 // addStepOsc(midimap(CHANNEL_1), 8, 9, 10, 11);
  addOsc(midimap(CHANNEL_2), 12);
  addOsc(midimap(CHANNEL_3), 13);
  //addOsc(midimap(CHANNEL_4), 4);

  
  startMidi();

}







void loop() {
  updateMidi();
  
  oscClock();
  doAllTicks();
}
