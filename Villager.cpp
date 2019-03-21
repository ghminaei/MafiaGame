#include "Villager.h"

Villager::Villager()
    :Player(){}

Player::Role Villager::getRole(){ return Player::VILLAGER; }

void Villager::reset()
{
    Player::reset();
}