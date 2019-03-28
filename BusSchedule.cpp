#include<vector>
#include"BusSchedule.h"
#include<random>
#include<algorithm>  
#include<chrono>

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

std::vector<int> BusSchedule::getDepartures(){
    return departures;
}

int BusSchedule::getMaxCap(){
    return max_bus_cap;
}

int BusSchedule::getComfyCap(){
    return comfy_bus_cap;
}


BusSchedule BusSchedule::cross(BusSchedule partner){
    std::uniform_int_distribution<int> distribution_01(0,1);
    for(int i = 0; i < partner.departures.size(); ++i)
        if(distribution_01(generator))
            partner.departures[i] = departures[i];
    return partner;
}

BusSchedule BusSchedule::mutate(){
    BusSchedule mutated = *this;
    std::uniform_int_distribution<int> distribution_dep_size(0,departures.size()-1);
    std::uniform_int_distribution<int> distribution_20(-20, 20);
    mutated.departures[distribution_dep_size(generator)] +=  distribution_20(generator);
    return mutated;
}