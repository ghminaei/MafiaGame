#ifndef Vote_H
#define Vote_H
#include <iostream>
#include "Player.h"

class Vote
{
    public:
    Vote(Player*, Player*);
    std::string getVoterName();
    void increaseVoteeVoteCount();
    void changeVotee(Vote*);

    private:
    Player* voterPlayer;
    Player* voteePlayer;
};

#endif
