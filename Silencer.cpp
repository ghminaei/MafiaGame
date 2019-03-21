#include "Silencer.h"

Silencer::Silencer()
    :Mafia()
{
    silencedOnce = false;
}

void Silencer::reset()
{
    silencedOnce = false;
    Player::reset();
}

Player::Role Silencer::getRole(){ return Player::SILENCER; }

bool Silencer::isAlreadySilenced(){ return silencedOnce; }

void Silencer::setSilenced()
{
    silencedOnce = true;
}
