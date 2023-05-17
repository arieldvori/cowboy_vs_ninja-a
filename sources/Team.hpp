#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>

namespace ariel {};

class Team {
  vector<Character *> team;
  Character *leader;

public:
  Team(const Team& other);
  Team(Character *leader);
  Team(Team&& other)noexcept;
  Team& operator=(const Team& other);
  Team& operator=( Team&& other)noexcept;
  void add(Character *teamate);
  void attack(Team *oponnent);
  int stillAlive();
  void print();
  ~Team();
};
