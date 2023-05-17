#pragma once
#include "Team.hpp"
#include <vector>

namespace ariel {};

class SmartTeam : public Team {
  vector<Character *> team;
  Character *leader;
public:
  SmartTeam(const SmartTeam &other);
  SmartTeam(Character *leader);
  SmartTeam(SmartTeam &&other) noexcept;
  SmartTeam &operator=(const SmartTeam &other);
  SmartTeam &operator=(SmartTeam &&other) noexcept;
  void add(Character *teamate);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~SmartTeam();
};

