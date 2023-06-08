#include <iostream>
#include "Cowboy.hpp"



void Cowboy :: shoot(Character* other){
    if (this == other){
        throw std::runtime_error ("You can't shoot yourself");
    }
    if (this ->isAlive() == false){
        throw std::runtime_error ("Dead cowboys can't shoot");
    }
    if (other ->isAlive() == false){
        throw std::runtime_error ("Can't attack dead characters");
    }
    if (this ->hasboolets() == false){
        return;
    }
    other->hit(10);
    this->numBullets-=1;
}

int Cowboy :: getNumBullets(){
    return this->numBullets;
}

bool Cowboy :: hasboolets(){
    if (numBullets > 0){
        return true;
    }
    return false;
}

void Cowboy :: reload(){
    if (this->isAlive() == false){
        throw std :: runtime_error ("Cowboy is dead");
    }
    this ->numBullets = 6;
} 
