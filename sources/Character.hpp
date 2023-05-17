#pragma once

#include "Point.hpp"

using namespace std;

class Character {
  Point _location;
  string _name;
  int _life;

public:
  Character(string name,  const Point &location, int life);
  bool isAlive();
  double distance(const Character &other);
  void hit(int number);
  string getName();
  Point getLocation();
  string print();
  int getLife();
};
