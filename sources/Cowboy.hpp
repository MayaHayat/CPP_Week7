#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel{};

class Cowboy : public Character{

    private:
       int numBullets; 

    public:
        Cowboy(string name, Point location) : Character(name, location, 110), numBullets(6){
            this->setType("Cowboy");
        }
        
        void shoot(Character* other);

        bool hasboolets(); // checks if there are bullets left in the gun

        void reload(); // adds 6 bullets to gun

        int getNumBullets();

        

};


#endif