
#include "Osc.h"
#include <Arduino.h>

unsigned long us;

//int out = 0;
void initOsc(Osc &o, int pin) {
  pinMode(pin, OUTPUT);
  o.pin = pin;
  o.uPeriod = 0;
  o.halfPeriod = 0;
  o.out = 0;
}

void oscClock() {
    us = micros();
}

int mtof(int midiNote) {
  float freq = 440.0 * exp( 0.057762265 * ( midiNote-69.0 ) );
  return freq;
}


void playOsc(Osc &o, int note) {
  float f = mtof(note);
  float u = 1000000.f/f;
  o.uPeriod = u;
  o.halfPeriod = o.uPeriod/4;
}

void stopOsc(Osc &o) {
  o.uPeriod = 0;
  o.halfPeriod = 0;
}


void tickOsc(Osc &o) {
  if(o.uPeriod>0) {
    unsigned long pos = us % o.uPeriod;
    if(pos>o.halfPeriod != !o.out) {
      o.out ^= 1;
      digitalWrite(o.pin, o.out);
    }
  }
}

