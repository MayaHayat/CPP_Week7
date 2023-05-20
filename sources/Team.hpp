#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel{};

class Team{

    private:
        int numberMembers;


        static const int maxMembers = 10;

        vector <Character*> members;

    public:

    // ---------------------- HELP FUNCTIONS ------------------------

        void addToMembers(Character* newChar);

        std::vector <Character*> getFighters() const{
            return members;
        }

        Character* findClosestAliveFighter(const Team &team, const Character *leader) const;


    // -------------------- REQUESTED FUNCTIONS ----------------------

        Character *leader;

        Team(Character* leader);

        Team();
        
        ~Team();
    
        void add(Character* newChr);

        void attack(Team* other);

        int stillAlive();

        void print();

};


#endif