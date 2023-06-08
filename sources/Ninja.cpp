#include <iostream>
#include "Ninja.hpp"


void Ninja :: move(Character* other){
    this->setLocation(this->getLocation().moveTowards(this->getLocation(),other->getLocation(),this->speed));
}

void Ninja :: slash(Character* other){
    if (this == other){
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