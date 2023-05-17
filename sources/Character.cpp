#include "Character.hpp"

Character::Character(string name, const Point &location, int life)
    : _name(name), _location(location), _life(life) {}

bool Character::isAlive() { 
    return true; 
}
double Character::distance(const Character &other) {
    return 0.0; 
}
void Character::hit(int damage) {}
string Character::getName() {
    return "default"; 
}
Point Character::getLocation() {
    return _location; 
}
string Character::print() {
    return _name; 
}
int Character::getLife() {
    return _life; 
}