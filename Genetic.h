#ifndef GENETIC_H
#define GENETIC_H
#include"BusSchedule.h"
#include"BusStop.h"
#include<vector>
#include<utility>

class Genetic {
private:
    BusStop bus_stop;
    std::vector<std::pair<BusSchedule, int> > population;
    int population_count;
    
public:    
    Genetic(int pop_count, int nr_departures, int max_cap, int comfy_cap, BusStop n_stop);   
    void newGeneration();
    BusSchedule bestSchedule();
    BusSchedule evolution(int);
};

#endif /* GENETIC_H */

