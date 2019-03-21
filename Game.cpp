#include "Game.h"

Game::Game() 
{
    srand(time(0));
}

bool Game::isDuplicateRoom(std::string givenName)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getName() == givenName)
            return true;
    }
    return false;
}

Room *Game::makeRoom(std::string roomName)
{
    if (!isDuplicateRoom(roomName))
        return (new Room(roomName));
    else
        throw DuplicateRoomNameEx();
}

void Game::handleCreateRoomReq()
{
    std::string line, roomName;
    std::cin >> roomName;
    getline(std::cin, line);
    Room *newRoom;
    try
    {
        newRoom = makeRoom(roomName);
        newRoom->readPlayers(line);
        rooms.push_back(newRoom);
        currentRoom = newRoom;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

Room *Game::findRoom(std::string roomName)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getName() == roomName)
            return rooms[i];
    }
    throw InvalidRoomNameEx();
}

void Game::changeRoomTo(std::string roomName)
{
    currentRoom = findRoom(roomName);
}

void Game::handleSwitchRoomReq()
{
    std::string roomName;
    std::cin >> roomName;
    try
    {
        changeRoomTo(roomName);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

void Game::handleNotValidReq()
{
    std::string useless;
    try
    {
        getline(std::cin, useless, '\n');
        throw WrongCommandEx();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

void Game::handleJoinReq()
{
    std::string line;
    getline(std::cin, line);
    //assert(currentRoom);
    try
    {
        currentRoom->joinPlayers(line);
        if (!currentRoom)
            throw NotInARoomEx();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

void Game::handleActionReq(Room::Action act)
{
    std::string line;
    getline(std::cin, line);
    try
    {
        if (!currentRoom)
            throw NotInARoomEx();
        currentRoom->readAction(act, line);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

void Game::handleEndVoteReq()
{
    try
    {
        if (!currentRoom)
            throw NotInARoomEx();
        currentRoom->endVote(); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

void Game::handleRoomStateReq()
{
    try
    {
        currentRoom->getState();
        if (!currentRoom)
            throw NotInARoomEx();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

void Game::readInputs()
{
    std::string input;
    while (std::cin >> input)
    {
        if (input == "Create_room")
        {
            handleCreateRoomReq();
        }
        else if (input == "Switch_room")
        {
            handleSwitchRoomReq();
        }
        else if (input == "Join")
        {
            handleJoinReq();
        }
        else if (input == "Vote")
        {
            handleActionReq(Room::VOTE);
        }
        else if (input == "End_vote")
        {
            handleEndVoteReq();
        }
        else if (input == "Detect")
        {
            handleActionReq(Room::DETECT);
        }
        else if (input == "Heal")
        {
            handleActionReq(Room::HEAL);
        }
        else if (input == "Silent")
        {
            handleActionReq(Room::SILENT);
        }
        else if (input == "Get_room_state")
        {
            handleRoomStateReq();
        }
        else if (input == "phase")
        {
            std::cout << currentRoom->getCurrentPhase() << "\n";
        }
        else
        {
            handleNotValidReq();
        }
    }
}
