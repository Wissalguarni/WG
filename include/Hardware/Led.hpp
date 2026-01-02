#ifndef LED_HPP
#define LED_HPP
#include "Hardware.hpp"
class LED: public Hardware{
 public:
 virtual void   ON()=0;
 virtual void   OFF()=0;
 virtual void   blink(int period)=0;// LED blinks with period in ms
 virtual ~LED() {};


};






#endif