#include "Mafia.h"

Mafia::Mafia()
    : Player(){}

Player::Role Mafia::getRole(){ return Player::MAFIA; }

void Mafia::reset()
{
    Player::reset();
}
