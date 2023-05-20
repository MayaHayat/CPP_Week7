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

        static int nextId;

        bool isInTeam;



    public:
        int id;

        string type;


        Character(string name, Point location, int alivePoints);

        Character(string name, Point location);

        Character();

        Character(Character *other);


        int getAlivePoints()const;

        void setAlivePoints(int toAdd);

        bool isAlive();

        double distance(Character* other) const;

        void hit(int numPoints);

        string getName();

        Point getLocation();

        void setLocation(const Point &other);

        void inTeam();

        bool isTaken();

        // string to_string();

        string print();


};



#endif