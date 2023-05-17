#pragma once
#include "Character.hpp"

constexpr int Y_life = 100;
constexpr int Y_speed = 14;
constexpr int O_life = 150;
constexpr int O_speed = 18;
constexpr int T_life = 120;
constexpr int T_speed = 12;

class Ninja : public Character {
  int speed;

public:
  Ninja(string name, const Point &location, int life, int speed);
  void move(const Character *enemy);
  void slash(Character *enemy);
};

class TrainedNinja : public Ninja {

public:
  TrainedNinja(string name, const Point &location)
  : Ninja(std::move(name), location, T_life, T_speed) {}
};

class YoungNinja : public Ninja {

public:
  YoungNinja(string name, const Point &location)
  : Ninja(std::move(name), location, Y_life, Y_speed) {}
};


class OldNinja : public Ninja {

public:
  OldNinja(string name, const Point &location)
      : Ninja(std::move(name), location, O_life, O_speed) {}
};