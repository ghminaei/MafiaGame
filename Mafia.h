#ifndef Mafia_H
#define Mafia_H
#include "Player.h"

class Mafia : public Player
{
    public:
    Mafia();
    virtual Role getRole();
    void reset();
};

#endif
