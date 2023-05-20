#include <iostream>
#include <limits>
#include "Team.hpp"



Team :: Team(){

    this ->leader = new Character();
}

Team :: Team(Character* leader) {
    if (leader-> isTaken()){
        string name = leader ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    this->leader = leader;
    this -> members.push_back(leader);
    //leader -> inTeam();
    leader->inTeam();
}




Team::~Team(){
    for (Character *fighter : members)
        delete fighter;
}
    
void Team :: add(Character* newChr){
    if (this ->members.size() == 10){
        throw std :: runtime_error("Team is full, can't add more mates");
    }
    if (newChr->isTaken() ){
        string name = newChr ->getName();
        throw std::runtime_error (name + " is already in another team");
    }
    //cout << members.size()  << " BEFORE "<< endl;
    this-> members.push_back(newChr);
    this -> numberMembers += 1;
    newChr -> inTeam();
    //cout << members.size() << " AFTER " << endl;
}

void  Team :: attack(Team* other){
    if (other == nullptr){
        throw std::invalid_argument("No team was given to attack");
    }
    if (other->stillAlive() == 0){
        throw std::runtime_error("All teammates are already dead");
    }
    if (this ->leader->isAlive() == false){
        this ->leader = findClosestAliveFighter(*this, this->leader);
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
        
    }

    

}



Character* Team::findClosestAliveFighter(const Team &team, const Character *leader) const{
    double minDistance = std::numeric_limits<double>::max();
    Character* closestAlive = nullptr;
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
    for (size_t i = 0; i < members.size(); i++){
        if (members.at(i)->isAlive() == false){
            members.erase(members.begin() + static_cast<std::vector<Character>::difference_type>(i));
        }
    }
    return this -> members.size();
}

void Team :: print(){
    for (size_t i = 0; i < members.size(); ++i) {
        if(members.at(i)->type == "Cowboy")
            cout << members.at(i)->print() << endl;
    }
    for (size_t i = 0; i < members.size(); ++i) {
        if(members.at(i)->type == "Ninja")
            cout << members.at(i)->print() << endl;
    }

    cout <<" The leader is " <<this->leader->print() << endl;
}

void Team :: addToMembers(Character* newChar){
    this ->members.push_back(newChar);
}