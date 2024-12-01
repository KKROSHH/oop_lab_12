#include <iostream>
#include <string>
#pragma once

class Transportation {
protected:
    std::string Vehicle;
    int Transportation_ID;
    int Transportation_Time;
    int Break_Time;
    std::string Departure;
    std::string Destination;

    int Remain_Time() const {
        return Transportation_Time - Break_Time;
    }

public:
    Transportation()
        : Vehicle("None"), Transportation_ID(0), Transportation_Time(0), Break_Time(0), Departure("None"), Destination("None") {}

    virtual ~Transportation() = default;
};
