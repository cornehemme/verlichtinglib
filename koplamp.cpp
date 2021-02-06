#include "Arduino.h"
#include "koplamp.h"

koplamp::koplamp(byte led1, byte led2)
{
  _led1 = led1;
  _led2 = led2;
  pinMode(_led1, OUTPUT);
  pinMode(_led2, OUTPUT);
}

void koplamp::update()
{
  if ((millis() - _delayStart) >= _DELAY_TIME)
  {
    _delayStart = millis();
    switch (_state)
    {
    case 1:
      digitalWrite(_led1, HIGH);
      _DELAY_TIME = 400;
      _state = 2;
      break;
    
    case 2:
      digitalWrite(_led1, LOW);
      digitalWrite(_led2, HIGH);
      _DELAY_TIME = 400;
      _state = 3;
      break;
    
    case 3:
      digitalWrite(_led2,LOW);
      if (_count < 5)
      {
        _DELAY_TIME = 0;
        _state = 1;
        _count ++;
      } else {
        _DELAY_TIME = 400;
        _state = 4;
        _count = 0;
      }
      break;
    
    case 4:
      digitalWrite(_led1, HIGH);
      digitalWrite(_led2, HIGH);
      _DELAY_TIME = 100;
      _state = 5;
      break;

    case 5:
      digitalWrite(_led1, LOW);
      digitalWrite(_led2, LOW);
      if (_count < 2)
      {
        _DELAY_TIME = 40;
        _state = 4;
        _count ++;
      } else {
        _DELAY_TIME = 0;
        _count = 0;
        _state = 6;
      }
      break;

    case 6:
      _DELAY_TIME = 300;
      if (_count2 < 3)
      {
        _state = 4;
        _count2 ++;
      } else {
        _state = 1;
        _count2 = 0;
      }
      break;

    default:
      break;
    }
  }
}
