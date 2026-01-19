#ifndef HARDWARE_HPP
#define HARDWARE_HPP

// Abstract base class for hardware components
class Hardware {
public:
    virtual void init() = 0;                     // initialize hardware
    virtual ~Hardware() {};
};

#endif