#ifndef HARDWARE_HPP
#define HARDWARE_HPP

//Hardware is abstract
class Hardware {
public:
    virtual void init() = 0;                     // init hardware
    virtual ~Hardware() {};
};

#endif