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


        Team (Team&) = delete; 
        Team (Team&&) noexcept = delete;
        Team& operator = (const Team&) = delete; 
        Team& operator = (Team&&) noexcept = delete;
    

    // -------------------- REQUESTED FUNCTIONS ----------------------


        Team(Character* leader);

        Team();
        
        virtual ~Team(){
        for(size_t i=0 ; i<members.size() ;i++){
            delete members.at(i);
            }
        }
    
        void add(Character* newChr);

        virtual void attack(Team* other);

        int stillAlive();

        void print();

};


#endif