#include "Doctor.h"

Doctor::Doctor()
    :Villager()
{
    healedOnce = false;
}

void Doctor::reset()
{
    healedOnce = false;
    Player::reset();
}

Player::Role Doctor::getRole(){ return Player::DOCTOR; }

void Doctor::setHealed()
{
    healedOnce = true;
}

bool Doctor::isAlreadyHealed(){ return healedOnce;}