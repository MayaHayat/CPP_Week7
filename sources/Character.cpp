#include <iostream>
#include <cmath>
#include "Character.hpp"

using namespace std;


bool Character :: isAlive(){
    return this ->alivePoints > 0;
}

double Character :: distance(Character* other) const{
    return this->location.distance(other->getLocation());
}

void Character :: hit(int numPoints){
    if (numPoints < 0 ){
        throw std::invalid_argument ("Can't be a negative number");
    }
    this ->alivePoints = (alivePoints-numPoints);
}

string Character :: getName(){
    return this ->name;
}

Point Character :: getLocation(){
    return this ->location;
}

void Character :: setLocation(const Point &other){
    this ->location = other;
}

string Character :: print(){
    string alive = to_string(this ->alivePoints) + " ";
    string s = this -> name +  " is standing at " + (this ->location.print()) + " and has " + alive + " lives left.";
    return s;
}

int Character :: getAlivePoints()const{
    return this ->alivePoints;
}

void Character :: inTeam(){
    this ->isInTeam = true;
}

bool Character :: isTaken(){
    return isInTeam;
}


void Character :: setType(string type){
    this ->type = type;
}

string Character :: getType(){
    return this-> type;
}


