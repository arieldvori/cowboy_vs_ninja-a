#pragma once
#include "Character.hpp"

class Cowboy : public Character {
  int bullets;

public:
  Cowboy(string name,const Point &location);
  void shoot(Character* enemy);
  bool hasBullets();
  void reload();
};