#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <iostream>
#include <vector>

#include "Team.hpp"


using namespace std;
namespace ariel{};

class SmartTeam : public Team{

    private:
        

    public:
        SmartTeam(Character* leader);
        
        SmartTeam();

        void print();
    
        Character* findLowestPointsFighter(const Team &team) const;

        Character* findClosestAliveFighter(const Team &team, const Character *leader) const;

        
        void attack(Team* other);

        int getNumberOfNinjas();

        int getNumberOfCowboys();



};
#endif