#pragma once

#include <string>
#include <iostream>

class Point{
    double xval;
    double yval;

public:
    Point(double xval, double yval);
    double distance(const Point& other);
    void print();
    static Point moveTowards(Point src, Point des, double dis);
};
