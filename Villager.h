#ifndef Villager_H
#define Villager_H
#include "Player.h"

class Villager : public Player
{
    public:
    Villager();
    virtual Role getRole();
    void reset();
};

#endif
