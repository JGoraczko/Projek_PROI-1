#include<iostream>
#include"BusStop.h"
#include"BusSchedule.h"
#include<array>
#include<algorithm>

BusStop::BusStop(std::array<int, 1440> n_passengers) {
    passengers = n_passengers;
}

int BusStop::evaluatePenalty(BusSchedule schedule){
    int people_waiting = 0;
    int penalty = 0;
    for(int i = 0; i < 1440; ++i)
    {
        people_waiting += passengers[i];       
        for(int j: schedule.getDepartures())
            if(j == i)
            {
                int passengers_taken = people_waiting < schedule.getMaxCap() ? people_waiting : schedule.getMaxCap();               
                people_waiting -= passengers_taken;          
                penalty += std::max(passengers_taken - schedule.getComfyCap() , 0);
            }
        penalty += people_waiting;     
    }
    return penalty;
}