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

        Character *leader;

        vector <Character*> members;

    public:

    // ---------------------- HELP FUNCTIONS ------------------------

        void addToMembers(Character* newChar);

        void setLeader(Character *leader);

        Character* getLeader();

        std::vector <Character*> getFighters() const{
            return members;
        }

        Character* findClosestAliveFighter(const Team &team, const Character *leader) const;



        Team (Team&) = delete; // Copy Constructor.
        Team (Team&&) noexcept = delete; // Move Constructor.
        Team& operator = (const Team&) = delete; // Copy assignment operator.
        Team& operator = (Team&&) noexcept = delete; // Move assignment operator.
    

    // -------------------- REQUESTED FUNCTIONS ----------------------


        Team(Character* leader);

        Team();
        
        virtual ~Team();
    
        void add(Character* newChr);

        void attack(Team* other);

        int stillAlive();

        void print();

};


#endif