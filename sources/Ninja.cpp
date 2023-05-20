#include <iostream>
#include "Ninja.hpp"


Ninja :: Ninja (string name, Point location,int alivePoints, int speed): Character(name, location, alivePoints){
    this ->speed  = speed;
    this->type = "Ninja";

    
}

void Ninja :: move(Character* other){
    this->setLocation(this->getLocation().moveTowards(this->getLocation(),other->getLocation(),this->speed));
}

void Ninja :: slash(Character* other){
    if (this ->id == other->id){
        throw std::runtime_error ("You can't slush yourself");
    }
    if (this ->isAlive() == false){
        throw std::runtime_error ("Dead ninjas can't slash");
    }
    if (other ->isAlive() == false){
        throw std::runtime_error ("Can't attack dead characters");
    }
    if (this->getLocation().distance(other->getLocation()) <= 1){
        other->hit(40);
    }
}

int Ninja :: getSpeed()const{
    return this ->speed;
}