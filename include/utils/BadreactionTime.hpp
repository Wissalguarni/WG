// BadReactionTime.hpp
#ifndef BADREACTIONTIME_HPP
#define BADREACTIONTIME_HPP

#include <exception>

class BadreactionTime : public std::exception {
public:
    const char* what() const noexcept override {
        return "t nul";
    }
};

#endif
