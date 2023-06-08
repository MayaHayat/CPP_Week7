#include <iostream>
#include <limits>
#include "Team.hpp"


Team :: Team(){
}

Team :: Team(Character* leader) {
    // Make sure leader is available
    if (leader-> isTaken()){
        string name = leader ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    // must add leader only after checking
    this->leader = leader;
    this -> members.push_back(leader);
    leader->inTeam();
}

    
void Team :: add(Character* newChr){
    // check adding is possible
    if (this ->members.size() == 10){
        throw std :: runtime_error("Team is full, can't add more mates");
    }
    // make sure not taken
    if (newChr->isTaken() ){
        string name = newChr ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    this-> members.push_back(newChr);
    newChr -> inTeam();
}


void Team :: setLeader(Character *leader){
    this ->leader = leader;
}

Character* Team :: getLeader(){
    return this ->leader;
}

void  Team :: attack(Team* other){
    // check all possible errors
    if (other == nullptr){
        throw std::invalid_argument("No team was given to attack");
    }
    if (other->stillAlive() == 0){
        throw std::runtime_error("All teammates are already dead");
    }
    // change leader
    if (this ->leader->isAlive() == false){
        this ->leader = findClosestAliveFighter(*this, this->leader);
    }
    // end if dead
    if (other->stillAlive() == 0){
        return;
    }
    // start attacking after using help func
    Character* toAttack = findClosestAliveFighter(*other, this->leader);
    for (Character* fighter : this->getFighters()){
        if(other->stillAlive() == 0){
            break;
        }
        if (toAttack->isAlive() == false){
            toAttack = findClosestAliveFighter(*other, this->leader);
        }
        //make sure cowboys shoot first
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
    for (Character* fighter : this->getFighters()){
        if(other->stillAlive() == 0){
            break;
        }
        if (toAttack->isAlive() == false){
            toAttack = findClosestAliveFighter(*other, this->leader);
        }
        // only then ninjas slash
        if(fighter->getType() == "Ninja" && fighter->isAlive()){
            Ninja* nja = static_cast<Ninja *>(fighter);
            if(nja->distance(toAttack) <= 1){
                nja->slash(toAttack);
            } 
            else{
                nja->move(toAttack);
            }           
        } 
    } 

}



Character* Team::findClosestAliveFighter(const Team &team, const Character *leader) const{
    double minDistance = std::numeric_limits<double>::max();
    Character* closestAlive = nullptr;
    // go through team and find min dist to leader
    for (Character* member : team.members) {
        if(member->isAlive()){
            if (leader->distance(member) < minDistance){
                minDistance = leader->distance(member);
                closestAlive = member;
            }
        }
    }
    return closestAlive;
}

int Team :: stillAlive(){
    int count = 0;
    for (size_t i = 0; i < members.size(); i++){
        if (members.at(i)->isAlive()){
            count++;
            //members.erase(members.begin() + static_cast<std::vector<Character>::difference_type>(i));
        }
    }
    return count;
}

void Team :: print(){
    //print cowboys first
    for (size_t i = 0; i < members.size(); ++i) {
        if(members.at(i)->getType() == "Cowboy")
            cout << members.at(i)->print() << endl;
    }
    // then print ninjas
    for (size_t i = 0; i < members.size(); ++i) {
        if(members.at(i)->getType() == "Ninja")
            cout << members.at(i)->print() << endl;
    }

    cout <<" The leader is " <<this->leader->print() << endl;
}

void Team :: addToMembers(Character* newChar){
    this ->members.push_back(newChar);
}



