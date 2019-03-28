#include<vector>
#include "BusSchedule.h"
#include<random>
#include <algorithm>  

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);

BusSchedule::BusSchedule(int nr_departures, int max_cap, int comfy_cap){
    max_bus_cap = max_cap;
    comfy_bus_cap = comfy_cap;
    std::vector<int> n_departures;
    std::uniform_int_distribution<int> distribution_0_1440(0,1440);
    for(int i = 0; i < nr_departures; i++)
        n_departures.push_back(distribution_0_1440(generator));
    std::sort(n_departures.begin(), n_departures.end());
    departures = n_departures;
}

