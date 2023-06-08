#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;
namespace ariel{};

class Point{

    private:
        double x_c;

        double y_c;

    public:
        Point(){}

        Point(double x_c, double y_c) :x_c(x_c), y_c(y_c){}


        double getX() const;

        double getY() const;

        double distance(Point other) const;

        static Point moveTowards(Point origin, Point destination, double distance);

        string print();

        
};


#endif