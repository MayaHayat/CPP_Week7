#include <iostream>
#include <limits>

#include "Team2.hpp"

Team2 :: Team2(Character* leader){
    if (leader->isTaken() ){
        string name = leader ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    this ->leader = leader;
    this ->addToMembers(leader);
    leader->inTeam();
}

Team2 :: Team2() : Team(){
    
}



void  Team2 :: attack(Team* other){
    if (other == nullptr){
        throw std::invalid_argument("No team was given to attack");
    }
    if (other->stillAlive() == 0){
        throw std::runtime_error("All teammates are already dead");
    }
    if (this ->leader->isAlive() == false){
        this->leader = findClosestAliveFighter(*this, this->leader);
    }
    if (other->stillAlive() == 0){
        return;
    }
    Character* toAttack = findClosestAliveFighter(*other, this->leader);
    for (Character* fighter : this->getFighters()){
        if(other->stillAlive() == 0){
            break;
        }
        if (toAttack->isAlive() == false){
            toAttack = findClosestAliveFighter(*other, this->leader);
        }

        if(fighter->type == "Ninja" && fighter->isAlive()){
            Ninja* nja = static_cast<Ninja *>(fighter);
            if(nja->distance(toAttack) <= 1){
                nja->slash(toAttack);
            } 
            else{
                nja->move(toAttack);
            }           
        }

        if(fighter->type == "Cowboy" && fighter->isAlive()){
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

void Team2 :: print(){
    for (size_t i = 0; i < this->getFighters().size(); ++i) {
        if(this->getFighters().at(i)->type == "Cowboy")
            cout << this->getFighters().at(i)->print() << endl;

        if(this->getFighters().at(i)->type == "Ninja")
            cout << this->getFighters().at(i)->print() << endl;
    }
    
    cout <<" The leader is " <<this->leader->print() << endl;

}

