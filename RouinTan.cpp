#include "RouinTan.h"

RouinTan::RouinTan()
    :Villager()
{
    onceDied = false;
}

void RouinTan::reset()
{
    Player::reset();
}

bool RouinTan::isAlreadyDied(){ return onceDied;}

void RouinTan::setOnceDead()
{
    onceDied = true;
}

Player::Role RouinTan::getRole(){ return Player::ROUINTAN; }