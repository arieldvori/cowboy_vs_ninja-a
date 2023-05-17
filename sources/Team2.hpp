#pragma once
#include "Team.hpp"
#include <vector>

namespace ariel {};

class Team2:public Team{
  vector<Character *> team;
  Character *leader;

public:
  Team2(const Team2& other);
  Team2(Character *leader);
  Team2(Team2&& other)noexcept;
  Team2& operator=(const Team2& other);
  Team2& operator=( Team2&& other)noexcept;
  void add(Character *teamate);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~Team2();
};
