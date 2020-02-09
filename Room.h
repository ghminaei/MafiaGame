#ifndef Room_H
#define Room_H
#include <vector>
#include <iostream>
#include "Player.h"
#include "Joker.h"
#include "Villager.h"
#include "Detective.h"
#include "Doctor.h"
#include "RouinTan.h"
#include "Mafia.h"
#include "GodFather.h"
#include "Silencer.h"
#include "commonTools.h"
#include "AllExeptions.h"
#include "Vote.h"
//#include <assert.h>
const int NUMBEROFROLES = 8;

class Room
{
    public:
    Room(std::string);
    ~Room();
    enum GamePhases {START, DAY, NIGHTVOTE, DETECTIVE, HEALER, SILENCER, ENDGAME};
    enum Action {VOTE, DETECT, HEAL, SILENT};
    void readAction(Action, std::string);
    void readPlayers(std::string);
    void joinPlayers(std::string);
    void getState();
    void endVote();
    
    std::string getName();
    GamePhases getCurrentPhase();

    private:
    void checkPhase();
    GamePhases currentPhase;
    void addJoker(int);
    void addVillager(int);
    void addDetective(int);
    void addDoctor(int);
    void addRouinTan(int);
    void addMafia(int);
    void addGodFather(int);
    void addSilencer(int);

    void checkJoker(Player*);
    void checkRightPhase(Action);
    void printNightNum();
    void resetPlayers();
    void nightEvents();
    void decreaseCountPlayer(Player*);
    void setDieStatus();
    void declareKilled(std::string);
    void printDayNum();
    static bool comparePlayer(Player*, Player*);
    void showSilencedPlayers();
    void dayEvents();
    int dayNum;

    void checkEndGame();

    void checkAllSilenced();
    void silent(Silencer*&, Player*&);
    void prepareSilent(std::string, std::string);
    void checkAllHeal();
    void heal(Doctor*&, Player*&);
    void prepareHeal(std::string, std::string);
    void checkAllDetect();
    bool isMafia(Player*);
    void detect(Detective*&, Player*&);
    void prepareDetect(std::string, std::string);
    std::vector <Player*> findHighestVotes(int);
    void declareDiedPlayer(std::string);
    void declareInDangerPlayer(std::string);
    int findHighestVote();
    Player* findVotedPlayer();
    void countVotes();
    Vote* findVotersFirstVote(Vote*);
    void addVote(Vote*);
    Player* findPlayer(std::string);
    void prepareVote(std::string, std::string);
    void printRole(Player*, std::string);
    void assignRoles();
    void setSumAllPlayers();
    void makeOnePlayer(std::string, int);
    void makePlayers();
    void initRoleCounts();
    bool isNumberRight(std::string);
    bool isNumbersRight(std::vector <std::string>);
    bool isRoleAvailable(std::string);
    bool isRolesAvailable(std::vector <std::string>);
    bool isCountsRight();
    static const std::string ROLENAMES[NUMBEROFROLES];
    int roleCounts[NUMBEROFROLES];
    void setRoleCounts(std::vector <std::string>);
    void setPlayers(std::vector <std::string>);
    bool verifyPlayersInp(std::vector <std::string>);
    std::vector <Player*> players;
    std::vector <Vote*> votes;
    std::vector <std::string> playerNames;
    void setPlayers();
    std::string roomName; 
    int allRolesCount;
    int detectCount;
    int healCount;
    int silentCount;
    int aliveMafiaCount();
    int aliveVillagerCount();
    Player* inDangerPlayer;
    void addToSilencedList(Player*);
    std::vector <Player*> silencedList;
};

#endif
