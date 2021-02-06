#ifndef koplamp_h
#define koplamp_h

#include "Arduino.h"

class koplamp
{
private:
  byte _led1;
  byte _led2;
  byte _state = 1;
  byte _count = 0;
  byte _count2 = 0;

  unsigned long _DELAY_TIME = 0; 
  unsigned long _delayStart = 0; // the time the delay started
public:
  koplamp(byte led1, byte led2, unsigned long startdelay);
  void update();
};

#endif