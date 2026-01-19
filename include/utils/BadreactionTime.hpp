// BadReactionTime.hpp
#ifndef BADREACTIONTIME_HPP
#define BADREACTIONTIME_HPP

#include <exception>
// Exception for a bad reaction time(did not manage to make it work with an exception in ScoreManager)
class BadreactionTime : public std::exception {
public:
    const char* what() const noexcept override {
        return "t nul";
    }
};

#endif
