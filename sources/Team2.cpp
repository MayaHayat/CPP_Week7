#include <iostream>
#include <limits>

#include "Team2.hpp"

Team2 :: Team2(Character* leader){
    // Make sure no leader
    if (leader->isTaken() ){
        string name = leader ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    // must add leader only after checking
    this ->setLeader(leader);
    this ->addToMembers(leader);
    leader->inTeam();
}

Team2 :: Team2() : Team(){}

void  Team2 :: attack(Team* other){
    // make sure no errors should be thrown
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
    // Also fighting closest first
    Character* toAttack = findClosestAliveFighter(*other, getLeader());
    for (Character* fighter : this->getFighters()){
        if(other->stillAlive() == 0){
            break;
        }
        if (toAttack->isAlive() == false){
            toAttack = findClosestAliveFighter(*other, getLeader());
        }
        // when reaching ninjas slash
        if(fighter->getType() == "Ninja" && fighter->isAlive()){
            Ninja* nja = static_cast<Ninja *>(fighter);
            if(nja->distance(toAttack) <= 1){
                nja->slash(toAttack);
            } 
            else{
                nja->move(toAttack);
            }           
        }
        // when cowboys are reached they shoot
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

// find closest fighter to leader
Character* Team2 ::findClosestAliveFighter(const Team &team, const Character *leader) const{
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

// printing whoever was added first
void Team2 :: print(){
    for (size_t i = 0; i < this->getFighters().size(); ++i) {
        if(this->getFighters().at(i)->getType() == "Cowboy")
            cout << this->getFighters().at(i)->print() << endl;

        if(this->getFighters().at(i)->getType() == "Ninja")
            cout << this->getFighters().at(i)->print() << endl;
    }
    // print leader at the end
    cout <<" The leader is " <<this->getLeader()->print() << endl;

}