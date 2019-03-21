#include "GodFather.h"

GodFather::GodFather()
    : Mafia(){}

Player::Role GodFather::getRole(){ return Player::GODFATHER; }

void GodFather::reset()
{
    Player::reset();
}