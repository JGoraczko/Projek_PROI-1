#include<cstdlib>
#include<vector>
#include<iostream>
#include<array>

#include"BusSchedule.h"
#include"BusStop.h"
#include"Genetic.h"


int main(int argc, char** argv) {
    
    std::array<int, 1440> passengers;
    for(int i = 0; i < 1440; ++i)
        passengers[i] = 0;

  /*  for(int i = 0; i < 360; ++i)
        if(i%60 == 0)
            passengers[i] = 1;
    for(int i = 360; i < 540; ++i)
        if(i%10 == 0)
            passengers[i] = 5;  
    for(int i = 540; i < 900; ++i)
        if(i%30 == 0)
            passengers[i] = 5;
    for(int i = 900; i < 1100; ++i)
        if(i%10 == 0)
            passengers[i] = 5; 
    for(int i = 1100; i < 1440; ++i)
        if(i%30 == 0)
            passengers[i] = 2;  */
    
   // passengers[570] = 1000;
    
 /*   for(int i = 0; i < 1440; ++i)
        passengers[i] = 1;  */
    
    
    for(int i = 0; i < 1440; ++i)
        if(i%60 == 0)
            passengers[i] = 50;
    
    BusStop stop(passengers);
    
    
  /*  BusSchedule sch(2, 60, 30);
    sch.departures[0] = 0;
    sch.departures[1] = 0;
    std::cout << stop.evaluatePenalty(sch);*/
    
    
    Genetic genetic(100, 30, 60, 30, stop);
    std::cout << "penalty: " << stop.evaluatePenalty(genetic.bestSchedule()) << std::endl;
    genetic.evolution(100);
    BusSchedule winner = genetic.bestSchedule();
    std::cout << "penalty:" << stop.evaluatePenalty(winner) << std::endl;
    for(int i = 0; i < 30; ++i)
        std::cout << i+1 << ": " << winner.getDepartures()[i]/60 << ":" << winner.getDepartures()[i]%60 << std::endl;  
    
    
 /*   BusSchedule sch1(10, 60, 30);
    BusSchedule sch2(10, 60, 30);
    BusSchedule sch3(10, 60, 30);
    sch3 = sch1.cross(sch2);
    for(int i = 0; i < 10; ++i)
        std::cout << sch1.getDepartures()[i] << " " << sch2.getDepartures()[i] << " " << sch3.getDepartures()[i] << std::endl;*/
        
        
    /*BusSchedule sch4(10, 60, 30);
    BusSchedule sch5(10, 60, 30);
    sch5 = sch4.mutate();
    for(int i = 0; i < 10; ++i)
        std::cout << sch4.getDepartures()[i] << " " << sch5.getDepartures()[i] << std::endl;   */
        
    return 0;
}

