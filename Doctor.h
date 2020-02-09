#ifndef Doctor_H
#define Doctor_H
#include "Villager.h"

class Doctor : public Villager
{
    public:
    Doctor();
    virtual Role getRole();
    bool isAlreadyHealed();
    void setHealed();
    void reset();

    private:
    bool healedOnce;
};

#endif
