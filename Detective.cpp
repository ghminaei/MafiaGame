#include "Detective.h"

Detective::Detective()
    :Villager()
{
    askedOnce = false;
}

void Detective::reset()
{
    askedOnce = false;
    Player::reset();
}

Player::Role Detective::getRole(){ return Player::DETECTIVE;}

bool Detective::isAlreadyAsked(){ return askedOnce; }

void Detective::setAsked(){ askedOnce = true;}