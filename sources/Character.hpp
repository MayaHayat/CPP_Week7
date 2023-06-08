#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"

using namespace std;
namespace ariel{};

class Character{

    private:
        Point location;

        int alivePoints;

        string name;

        bool isInTeam;

        string type;

    public:

        Character(string name, Point& location, int alivePoints): name(name), location(location),alivePoints(alivePoints),isInTeam(false), type("Character"){}

        Character(){}

        virtual ~Character() = default;

        int getAlivePoints()const;

        bool isAlive();

        double distance(Character* other) const;

        void hit(int numPoints);

        string getName();

        Point getLocation();

        void setLocation(const Point &other);

        void inTeam();

        bool isTaken();


        string print();


        void setType(string type);

        string getType();


        Character (Character&); // Copy Constructor.
        Character(Character&& ) noexcept; // Move Constructor.
        Character& operator = (const Character&); // Copy assignment operator.
        Character& operator = (Character&&) noexcept; // Move assignment operator.


};



#endif