#include"Genetic.h"
#include"BusSchedule.h"
#include"BusStop.h"
#include<vector>
#include<utility>
#include<algorithm>
#include<chrono>
#include<random>
#include<iostream>


unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator1(seed1);

bool sortbysec(const std::pair<BusSchedule, int> &a, 
              const std::pair<BusSchedule, int> &b) 
{ 
    return (a.second < b.second); 
} 


Genetic::Genetic(int pop_count, int nr_departures, int max_cap, int comfy_cap, BusStop n_stop):
    bus_stop(n_stop), population_count(pop_count)
{
    for(int i = 0; i < population_count; ++i)
    {
        BusSchedule new_schedule(nr_departures, max_cap, comfy_cap);
        population.push_back(std::make_pair(new_schedule, bus_stop.evaluatePenalty(new_schedule)));
    }
    std::sort(population.begin(), population.end(), sortbysec);
}


BusSchedule Genetic::bestSchedule(){
    return population[0].first;
}


void Genetic::newGeneration(){
    std::vector<std::pair<BusSchedule, int> > childreen;
    std::uniform_int_distribution<int> distribution_best_parents(0, (population_count/8)-1);
    std::uniform_int_distribution<int> distribution_worst_parents(population_count/8, population_count-1);
    std::bernoulli_distribution bernoulli(0.75);
    for(int i = 0; i < population_count; ++i)
    {
        int first_parent_nr = distribution_best_parents(generator1);
        int second_parent_nr;
        if(bernoulli(generator1))
            second_parent_nr = distribution_best_parents(generator1);
        else
            second_parent_nr = distribution_worst_parents(generator1);
        BusSchedule child(population[first_parent_nr].first.cross(population[second_parent_nr].first));  
        if(!bernoulli(generator1))
           child.mutate();
        childreen.push_back(std::make_pair(child, bus_stop.evaluatePenalty(child)));    
    }
    population = childreen;
    std::sort(population.begin(), population.end(), sortbysec);     
}

BusSchedule Genetic::evolution(int nr_generations){
    for(int i = 0; i < nr_generations; ++i)
        newGeneration();
    BusSchedule best(bestSchedule());
    return best;
}