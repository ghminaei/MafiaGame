#ifndef Silencer_H
#define Silencer_H
#include "Mafia.h"

class Silencer : public Mafia
{
    public:
    Silencer();
    virtual Role getRole();
    bool isAlreadySilenced();
    void setSilenced();
    void reset();

    private:
    bool silencedOnce;
};

#endif
