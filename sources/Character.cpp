#include <iostream>
#include <cmath>
#include "Character.hpp"

using namespace std;

Character :: Character (){
    this ->location = Point(0,0);
    this ->name = "Doesn't matter";
    this ->alivePoints = 10;
    this ->isInTeam = false;
}

Character :: Character(string name, Point location, int alivePoints): location(location){
    this -> name = name;
    this ->alivePoints = alivePoints;
    this ->isInTeam = false;
    this -> type = "character";
}

Character :: Character(string name, Point location): location(location){
    this -> name = name;
    this ->isInTeam = false;
}

Character :: Character(Character* other){
    this ->name = other->name;
    this ->location = Point(other->location);
    this ->isInTeam = false;
}

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
    this ->setAlivePoints(-numPoints);
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

void Character :: setAlivePoints(int toAdd){
    this ->alivePoints += toAdd;
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


