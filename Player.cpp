#include "Player.h"

Player::Player()
{
    dead = false;
    silenced = false;
    voteCount = 0;
    inDanger = false;
}

void Player::setName(std::string _name){ name = _name; }

std::string Player::getName(){ return name; }

bool Player::isSilenced(){return silenced; }

bool Player::isDead(){ return dead; }

void Player::setInDanger()
{
    inDanger = true;
}

void Player::die()
{
    dead = true;
}

void Player::increaseVoteCount()
{
    voteCount++;
}

int Player::getVote(){ return voteCount; }

void Player::healed()
{
    inDanger = false;
}

void Player::silence()
{
    silenced = true;
}

bool Player::isInDanger(){ return inDanger;}

void Player::clearPlayersVotes(std::vector <Player*> &players)
{
    for(int i = 0; i < players.size(); i++)
        players[i]->voteCount = 0;
}

void Player::reset()
{
    silenced = false;
    voteCount = 0;
    inDanger = false;
}

