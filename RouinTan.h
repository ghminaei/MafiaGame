#ifndef RouinTan_H
#define RouinTan_H
#include "Villager.h"

class RouinTan : public Villager
{
    public:
    RouinTan();
    virtual Player::Role getRole();
    bool isAlreadyDied();
    void setOnceDead();
    void reset();

    private:
    bool onceDied;
};

#endif
