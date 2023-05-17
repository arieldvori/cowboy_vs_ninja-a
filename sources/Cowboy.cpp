#include "Cowboy.hpp"
#include "Character.hpp"
Cowboy::Cowboy(string name, const Point &location)
    : Character(name, location, 110), bullets(6) {}
void Cowboy::shoot(Character *enemy) {}
bool Cowboy::hasBullets() { 
    return true; 
}
void Cowboy::reload() {}