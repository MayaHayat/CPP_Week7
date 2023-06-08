#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include <iostream>
#include "Ninja.hpp"

using namespace std;
namespace ariel{};

class YoungNinja : public Ninja{

    private:

    public:
    
        YoungNinja(string name, Point location): Ninja(name, location, 100, 14){}


};


#endif