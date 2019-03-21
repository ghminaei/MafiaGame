#include "Vote.h"

Vote::Vote(Player* _voterPlayer, Player* _voteePlayer)
    : voterPlayer(_voterPlayer), voteePlayer(_voteePlayer) {}

std::string Vote::getVoterName() {return voterPlayer->getName(); }
void Vote::increaseVoteeVoteCount()
{
    voteePlayer->increaseVoteCount();
}

void Vote::changeVotee(Vote* newVote)
{
    this->voteePlayer = newVote->voteePlayer; 
}