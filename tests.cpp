#include<cstdlib>
#include<vector>
#include<iostream>
#include<array>

#include"BusSchedule.h"
#include"BusStop.h"
#include"Genetic.h"
#include"tests.h"


void test1(){
    std::cout << "szuakmy rozkładu z 30 autobusami i podróżnymi przychodzącymi równomiernie na przystanek" << std::endl;
    std::array<int, 1440> passengers;
    for(int i = 0; i < 1440; ++i)
        passengers[i] = 1;
    
    BusStop stop(passengers);
    Genetic genetic(100, 30, 60, 30, stop);
    std::cout << "czas oczekiwania najlepszego rozkładu 1. pokolenia: " << stop.evaluatePenalty(genetic.bestSchedule()) << std::endl;
    genetic.evolution(100);
    BusSchedule winner = genetic.bestSchedule();
    std::cout << "czas oczekiwania najlepszego rozkładu 100. pokolenia: " << stop.evaluatePenalty(winner) << std::endl;
    for(int i = 0; i < 30; ++i)
        std::cout << i+1 << ": " << winner.getDepartures()[i]/60 << ":" << winner.getDepartures()[i]%60 << std::endl;          
}

void test2(){
    std::cout << "szuakmy rozkładu z 24 autobusami i podróżnymi przychodzącymi co godzinę na przystanek" << std::endl;
    std::array<int, 1440> passengers;
    for(int i = 0; i < 1440; ++i)
    {
        passengers[i] = 0;
        if(i%60 == 0)
            passengers[i] = 50;
    }   
    
    BusStop stop(passengers);
    Genetic genetic(100, 24, 60, 30, stop);
    std::cout << "czas oczekiwania najlepszego rozkładu 1. pokolenia: " << stop.evaluatePenalty(genetic.bestSchedule()) << std::endl;
    genetic.evolution(100);
    BusSchedule winner = genetic.bestSchedule();
    std::cout << "czas oczekiwania najlepszego rozkładu 100. pokolenia: " << stop.evaluatePenalty(winner) << std::endl;
    for(int i = 0; i < 24; ++i)
        std::cout << i+1 << ": " << winner.getDepartures()[i]/60 << ":" << winner.getDepartures()[i]%60 << std::endl;          
}

void test3(){
    std::cout << "szuakmy rozkładu z 30 autobusami i podróżnymi przychodzącymi głównie rano i po południu" << std::endl;
    std::array<int, 1440> passengers;
    for(int i = 0; i < 1440; ++i)
        passengers[i] = 0;          
    for(int i = 0; i < 360; ++i)
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
            passengers[i] = 2;
    
    BusStop stop(passengers);
    Genetic genetic(100, 30, 60, 30, stop);
    std::cout << "czas oczekiwania najlepszego rozkładu 1. pokolenia: " << stop.evaluatePenalty(genetic.bestSchedule()) << std::endl;
    genetic.evolution(100);
    BusSchedule winner = genetic.bestSchedule();
    std::cout << "czas oczekiwania najlepszego rozkładu 100. pokolenia: " << stop.evaluatePenalty(winner) << std::endl;
    for(int i = 0; i < 30; ++i)
        std::cout << i+1 << ": " << winner.getDepartures()[i]/60 << ":" << winner.getDepartures()[i]%60 << std::endl;          
}


void test4(){
    std::cout << "szuakmy rozkładu z 15 autobusami i podróżnymi przychodzącymi dokładnie o 10:00" << std::endl;
    std::array<int, 1440> passengers;
    for(int i = 0; i < 1440; ++i)
        passengers[i] = 0;          
    passengers[600] = 1000;
    
    BusStop stop(passengers);
    Genetic genetic(100, 15, 60, 30, stop);
    std::cout << "czas oczekiwania najlepszego rozkładu 1. pokolenia: " << stop.evaluatePenalty(genetic.bestSchedule()) << std::endl;
    genetic.evolution(100);
    BusSchedule winner = genetic.bestSchedule();
    std::cout << "czas oczekiwania najlepszego rozkładu 100. pokolenia: " << stop.evaluatePenalty(winner) << std::endl;
    for(int i = 0; i < 15; ++i)
        std::cout << i+1 << ": " << winner.getDepartures()[i]/60 << ":" << winner.getDepartures()[i]%60 << std::endl;          
}