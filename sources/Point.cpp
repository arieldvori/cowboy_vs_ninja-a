#include "Point.hpp"
using namespace std;

Point::Point(double x, double y) : xval(x), yval(y) {}
double Point::distance(const Point &other) { 
  return 0.0;
}
void Point::print() {
  cout << "part_a" << endl; 
}
Point Point::moveTowards(Point src, Point dest, double distance) {
  return src;
}
