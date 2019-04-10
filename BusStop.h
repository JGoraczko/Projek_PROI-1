#ifndef BUSSTOP_H
#define BUSSTOP_H
#include<array>
#include"BusSchedule.h"

class BusStop {
private:
    std::array<int, 1440> passengers;
public:   
    BusStop(BusStop&) = default;
    BusStop(std::array<int, 1440>);
    int evaluatePenalty(BusSchedule);
};

#endif /* BUSSTOP_H */

