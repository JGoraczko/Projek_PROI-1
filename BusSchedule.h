#ifndef BUSSCHEDULE_H
#define BUSSCHEDULE_H
#include<vector>
class BusSchedule{
private:
    std::vector<int> departures;
    int max_bus_cap;
    int comfy_bus_cap;
public:  
   // BusSchedule() = default;
    BusSchedule(const BusSchedule&) = default;
    BusSchedule(int nr_departures, int max_cap, int comfy_cap);
    std::vector<int> getDepartures();
    int getMaxCap();
    int getComfyCap();
    BusSchedule cross(BusSchedule);
    BusSchedule mutate();
};

#endif /* BUSSCHEDULE_H */

