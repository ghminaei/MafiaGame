#ifndef Game_H
#define Game_H
#include <iostream>
#include <vector>
#include "AllExeptions.h"
#include "Room.h"

class Game
{
    public:
    Game();
    void readInputs();

    private:
    Room* currentRoom;
    Room* makeRoom(std::string);
    Room* findRoom(std::string roomName);
    bool isDuplicateRoom(std::string);
    void handleRoomStateReq();
    void handleActionReq(Room::Action);
    void handleCreateRoomReq();
    void handleSwitchRoomReq();
    void handleJoinReq();
    void handleNotValidReq();
    void handleEndVoteReq();
    void changeRoomTo(std::string);
    std::vector <Room*> rooms;
    
};

#endif
