#include <iostream>
#include <limits>
#include <algorithm>

#include "SmartTeam.hpp"


SmartTeam :: SmartTeam(Character* leader){
    // Make sure leader is free
    if (leader->isTaken() ){
        string name = leader ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    this ->setLeader(leader);
    this ->addToMembers(leader);
    leader->inTeam();
}



void  SmartTeam :: attack(Team* other){
    //CHECK FOR ERRORS 
    if (other == nullptr){
        throw std::invalid_argument("No team was given to attack");
    }
    if (other->stillAlive() == 0){
        throw std::runtime_error("All teammates are already dead");
    }
    if (this ->getLeader()->isAlive() == false){
        this->setLeader(findClosestAliveFighter(*this, getLeader()));
    }
    if (other->stillAlive() == 0){
        return;
    }

    // If there are enough cowboys to kill a fighter without having to move
    int numOfCowboys = getNumberOfCowboys();
    for (Character* fighter : other->getFighters()){
        if (fighter->getAlivePoints() <= numOfCowboys*10){
            Character* toAttack = findClosestAliveFighter(*other, getLeader());

        }
    }
    
    Character* toAttack = findLowestPointsFighter(*other);
    for (Character* fighter : this->getFighters()){

        if(other->stillAlive() == 0){
            break;
        }
        if (toAttack->isAlive() == false){
            toAttack = findLowestPointsFighter(*other);
        }

        if(fighter->getType() == "Ninja" && fighter->isAlive()){
            Ninja* nja = static_cast<Ninja *>(fighter);
            if(nja->distance(toAttack) <= 1){
                nja->slash(toAttack);
            } 
            else{
                nja->move(toAttack);
            }           
        }

        if(fighter->getType() == "Cowboy" && fighter->isAlive()){
            Cowboy* cboy = static_cast<Cowboy *>(fighter);
            if(cboy->hasboolets()){
                cboy->shoot(toAttack);
            } 
            else{
                cboy->reload();
            }           
        }
    }

}


int SmartTeam :: getNumberOfCowboys(){
    int count = 0;
    for (Character* fighter : this -> getFighters()){
        if (fighter->getType() == "Cowboy" && fighter->isAlive()){
            count++;
        }
    }
    return count;
}


int SmartTeam :: getNumberOfNinjas() {
    int count = 0;
    for (Character* fighter : this -> getFighters()){
        if (fighter->getType() == "Ninja" && fighter->isAlive()){
            count++;
        }
    }
    return count;
}


Character* SmartTeam ::findClosestAliveFighter(const Team &team, const Character *leader) const{
    double minDistance = std::numeric_limits<double>::max();
    Character* closestAlive = nullptr;
    for (Character* member : team.getFighters()) {
        if(member->isAlive()){
            if (leader->distance(member) < minDistance){
                minDistance = leader->distance(member);
                closestAlive = member;
            }
        }
    }
    return closestAlive;
}

// find fighter who is closest to die so it can be taken out
Character* SmartTeam ::findLowestPointsFighter(const Team &team) const{
    double maxPoints = 200;
    Character* leastAlive = nullptr;
    for (Character* member : team.getFighters()) {
        if(member->isAlive()){
            if (member->getAlivePoints() < maxPoints){
                maxPoints = member->getAlivePoints();
                leastAlive = member;
            }
        }
    }
    return leastAlive;
}




// Printing based on living points from smallest to largest
void SmartTeam :: print() {
    std::vector<Character*> fighters = getFighters();
    std::sort(fighters.begin(), fighters.end(), [](Character* a, Character* b) {
        return a->getAlivePoints() < b->getAlivePoints();
    });

    for (Character* fighter : fighters) {
        std::cout << "Fighter Type: " << fighter->getType() << ", Living Points: " << fighter->getAlivePoints() << ", Status: " << (fighter->isAlive() ? "Alive" : "Dead") << std::endl;
    }
}

