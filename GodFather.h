#ifndef GodFather_H
#define GodFather_H
#include "Mafia.h"

class GodFather : public Mafia
{
    public:
    GodFather();
    virtual Role getRole();
    void reset();
};

#endif
