#ifndef Player_H
#define Player_H
#include <iostream>
#include <vector>
#include <map>

class Player
{
    public:
    Player();
    enum Role {JOKER, VILLAGER, DETECTIVE, DOCTOR, ROUINTAN, MAFIA, GODFATHER, SILENCER};
    virtual void reset(); 
    void setName(std::string);
    virtual Role getRole() = 0;
    std::string getName();
    bool isSilenced();
    bool isInDanger();
    bool isDead();
    void increaseVoteCount();
    void test();
    int getVote();
    void die();
    void setInDanger();
    void healed();
    void silence();
    static void clearPlayersVotes(std::vector <Player*>&);
    
    protected:
    std::string name;
    bool silenced;
    bool dead;
    int voteCount;
    bool inDanger;

};

#endif
