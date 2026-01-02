#ifndef HARDWARE_H
#define HARDWARE_H
//Hardware is abstract
class Hardware {
public:
    virtual void init() = 0;                     // init hardware
    virtual ~Hardware() {};
};

#endif