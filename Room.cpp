#include "Room.h"

const int FIRSTDAY = 1;

Room::Room(std::string _roomName)
    : roomName(_roomName)
{
    initRoleCounts();
    currentPhase = Room::START;
    detectCount = 0;
    healCount = 0;
    silentCount = 0;
    dayNum = 1;
}

const std::string Room::ROLENAMES[8] = {"Joker",
                                        "Villager",
                                        "Detective",
                                        "Doctor",
                                        "RouinTan",
                                        "Mafia",
                                        "GodFather",
                                        "Silencer"};

Room::~Room()
{
    for(int i = 0; i < players.size(); i++)
        delete players[i];
    for(int i = 0; i < votes.size(); i++)
        delete votes[i];

}

std::ostream& operator<<(std::ostream& out, const Player::Role value)
{
    static std::map<Player::Role, std::string> strings;
    strings.insert({Player::JOKER, "Joker"});
    strings.insert({Player::VILLAGER, "Villager"});
    strings.insert({Player::DETECTIVE, "Detective"});
    strings.insert({Player::DOCTOR, "Doctor"});
    strings.insert({Player::ROUINTAN, "RouinTan"});
    strings.insert({Player::MAFIA, "Mafia"});
    strings.insert({Player::GODFATHER, "GodFather"});
    strings.insert({Player::SILENCER, "Silencer"});
    return out << strings[value];
}

void Room::initRoleCounts()
{
    for (int i = 0; i < NUMBEROFROLES; i++)
    {
        roleCounts[i] = 0;
    }
}

std::string Room::getName() { return roomName; }

bool Room::isRoleAvailable(std::string roleString)
{
    return roleString == ROLENAMES[0] || roleString == ROLENAMES[1] || roleString == ROLENAMES[2] ||
           roleString == ROLENAMES[3] || roleString == ROLENAMES[4] || roleString == ROLENAMES[5] ||
           roleString == ROLENAMES[6] || roleString == ROLENAMES[7];
}

bool Room::isRolesAvailable(std::vector<std::string> pureStrings)
{
    for (int i = 0; i < pureStrings.size(); i += 2)
    {
        if (!isRoleAvailable(pureStrings[i]))
            throw WrongRoleEx();
    }
    return true;
}

bool Room::isNumberRight(std::string numString)
{
    int num;
    try{
        num = Gstoi(numString);
        return num >= 0;
    } catch(...)
    {
        return false;
    }
}

bool Room::isNumbersRight(std::vector<std::string> pureStrings)
{
    for (int i = 1; i < pureStrings.size(); i += 2)
    {
        if (!isNumberRight(pureStrings[i]))
            throw WrongNumberEx();
    }
    return true;
}

bool Room::verifyPlayersInp(std::vector<std::string> pureStrings)
{
    isRolesAvailable(pureStrings);
    isNumbersRight(pureStrings);
}

void Room::setSumAllPlayers()
{
    int sum = 0;
    for (int i = 0; i < NUMBEROFROLES; i++)
        sum += roleCounts[i]; 
    allRolesCount = sum;
}

bool Room::isCountsRight()
{
    if (roleCounts[2] + roleCounts[3] + roleCounts[4] > roleCounts[1])
        return false;
    if (roleCounts[6] + roleCounts[7] > roleCounts[5])
        return false;
    return true;
}

void Room::setRoleCounts(std::vector<std::string> pureStrings)
{
    for (int i = 0; i < pureStrings.size(); i += 2)
        for (int roleIter = 0; roleIter < NUMBEROFROLES; roleIter++)
        {
            if (ROLENAMES[roleIter] == pureStrings[i])
            {
                roleCounts[roleIter] = Gstoi(pureStrings[i + 1]);
            }
        }
    if (!isCountsRight())
        throw WrongCountEx();
    roleCounts[5] -= roleCounts[6] + roleCounts[7];
    roleCounts[1] -= roleCounts[2] + roleCounts[3] + roleCounts[4];
    setSumAllPlayers();
}

void Room::addJoker(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new Joker);
}
void Room::addVillager(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new Villager);
}

void Room::addDetective(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new Detective);
}

void Room::addDoctor(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new Doctor);
}

void Room::addRouinTan(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new RouinTan);
}

void Room::addMafia(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new Mafia);
}

void Room::addGodFather(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new GodFather);
}

void Room::addSilencer(int count)
{
    for (int i = 0; i < count; i++)
        players.push_back(new Silencer);
}

void Room::makeOnePlayer(std::string role, int count)
{
    //assert(count >= 0);
    if (role == ROLENAMES[0])
        addJoker(count);
    else if (role == ROLENAMES[1])
        addVillager(count);
    else if (role == ROLENAMES[2])
        addDetective(count);
    else if (role == ROLENAMES[3])
        addDoctor(count);
    else if (role == ROLENAMES[4])
        addRouinTan(count);
    else if (role == ROLENAMES[5])
        addMafia(count);
    else if (role == ROLENAMES[6])
        addGodFather(count);
    else if (role == ROLENAMES[7])
        addSilencer(count);
}

void Room::makePlayers()
{
    for (int i = 0; i < NUMBEROFROLES; i++)
        makeOnePlayer(ROLENAMES[i], roleCounts[i]);
}

void Room::setPlayers(std::vector<std::string> pureStrings)
{
    try
    {
        setRoleCounts(pureStrings);
        makePlayers();
    }
    catch (std::exception &e)
    {
        throw;
    }
}

void Room::readPlayers(std::string inp)
{
    std::vector<std::string> pureStrings;
    try
    {
        pureStrings = refineString(inp);
        verifyPlayersInp(pureStrings);
        setPlayers(pureStrings);
    }
    catch (std::exception &e)
    {
        throw;
    }
}

void Room::printRole(Player *player, std::string playerName)
{
    std::cout << playerName << " is " << player->getRole();
}

void Room::assignRoles()
{
    if(!isUniqueVector(playerNames))
    {
        playerNames.clear();
        throw DuplicateNameEx();
    }
    std::vector<int> randomNums = generateUniqueRandomNums(allRolesCount, allRolesCount);
    for (int i = 0; i < allRolesCount; i++)
    {
        int rndIndex = randomNums[i];
        players[i]->setName(playerNames[rndIndex]);
        printRole(players[i], playerNames[rndIndex]);
        std::cout << std::endl;
    }
    currentPhase = GamePhases::DAY;
    dayEvents();
}

void Room::joinPlayers(std::string givenLine)
{
    if (currentPhase != GamePhases::START)
        throw WrongPhaseEx();
    std::vector<std::string> givenPlayerNames;
    givenPlayerNames = splitString(givenLine);
    //assert(givenPlayerNames.size()!=0);
    
    addVectorToVector(givenPlayerNames, playerNames);
    if (playerNames.size() > allRolesCount)
    {
        playerNames.clear();
        throw ManyUsersEx();
    }
    else if (playerNames.size() == allRolesCount)
        assignRoles();
}

Player *Room::findPlayer(std::string playerName)
{
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i]->getName() == playerName)
            return players[i];
    }
    return NULL;
}

Vote *Room::findVotersFirstVote(Vote *preVote)
{
    for (int i = 0; i < votes.size(); i++)
    {
        if (votes[i]->getVoterName() == preVote->getVoterName())
            return votes[i];
    }
    return NULL;
}

void Room::addVote(Vote *newVote)
{
    Vote *preVote = findVotersFirstVote(preVote);
    if (preVote == NULL)
        votes.push_back(newVote);
    else
        preVote->changeVotee(newVote);
}

int Room::aliveMafiaCount() { return roleCounts[5] + roleCounts[6] + roleCounts[7]; }

int Room::aliveVillagerCount() { return roleCounts[1] + roleCounts[2] + roleCounts[3] + roleCounts[4]; }

void Room::prepareVote(std::string voter, std::string votee)
{
    Player *voterPlayer = findPlayer(voter);
    Player *voteePlayer = findPlayer(votee);
    if (voterPlayer == NULL || voteePlayer == NULL)
        throw UserNotJoinEx();
    if (voterPlayer->isDead())
        throw UserCantVoteEx();
    if (voteePlayer->isDead())
        throw UserAlreadyDiedEx();
    if (currentPhase == Room::DAY && voterPlayer->isSilenced())
        throw UserSilencedEx();
    if (currentPhase == Room::NIGHTVOTE)
    {
        if (!isMafia(voterPlayer))
            throw UserCantVoteEx();
    }
    addVote(new Vote(voterPlayer, voteePlayer));
    if (currentPhase == Room::NIGHTVOTE && votes.size() == aliveMafiaCount())
            endVote();
}

int Room::findHighestVote()
{
    int highestVote = players[0]->getVote();
    for (int i = 1; i < players.size(); i++)
    {
        if (highestVote < players[i]->getVote())
            highestVote = players[i]->getVote();
    }
    return highestVote;
}

std::vector<Player *> Room::findHighestVotes(int highestVote)
{
    std::vector<Player *> highestVotes;
    for (int i = 0; i < players.size(); i++)
    {
        if (highestVote == players[i]->getVote())
            highestVotes.push_back(players[i]);
    }
    return highestVotes;
}

Player *Room::findVotedPlayer()
{
    int highestVote = findHighestVote();
    std::vector<Player *> highestVotes = findHighestVotes(highestVote);
    std::vector<int> temp = generateUniqueRandomNums(highestVotes.size(), 1);
    return findPlayer(highestVotes[temp[0]]->getName());
}

void Room::countVotes()
{
    for (int i = 0; i < votes.size(); i++)
        votes[i]->increaseVoteeVoteCount();
}

void Room::declareDiedPlayer(std::string playerName)
{
    std::cout << "Died " << playerName << std::endl;
}

void Room::declareInDangerPlayer(std::string playerName)
{
    std::cout << "Mafia try to kill " << playerName << std::endl;
}

void Room::checkJoker(Player* deadPlayer)
{
    if(deadPlayer->getRole() == Player::JOKER)
    {
        currentPhase = GamePhases::ENDGAME;
        std::cout << "Do I look like a guy with a plan?" << std::endl;
    }
}

void Room::endVote()
{
    if (currentPhase != GamePhases::DAY && currentPhase != GamePhases::NIGHTVOTE)
        throw WrongPhaseEx();
    countVotes();
    Player *votedPlayer = findVotedPlayer();
    if (currentPhase == Room::DAY)
    {
        votedPlayer->die();
        declareDiedPlayer(votedPlayer->getName());
        decreaseCountPlayer(votedPlayer);
        currentPhase = GamePhases::NIGHTVOTE;
        checkJoker(votedPlayer);
        checkEndGame();
        if(currentPhase != GamePhases::ENDGAME)
            nightEvents();
    }
    else if (currentPhase == Room::NIGHTVOTE)
    {
        votedPlayer->setInDanger();
        declareInDangerPlayer(votedPlayer->getName());
        inDangerPlayer = votedPlayer;
        currentPhase = GamePhases::DETECTIVE;
        checkPhase();
    }
    //else
        //assert(false);
}

void Room::checkAllDetect()
{
    detectCount++;
    if (detectCount == roleCounts[2])
    {
        currentPhase = GamePhases::HEALER;
        checkPhase();
    }
}

bool Room::isMafia(Player *p)
{
    return p->getRole() == Player::GODFATHER ||
           p->getRole() == Player::MAFIA ||
           p->getRole() == Player::SILENCER;
}

void Room::detect(Detective* &detector, Player* &suspect)
{
    if (suspect->getRole() == Player::GODFATHER)
        std::cout << "No" << std::endl;
    else if (isMafia(suspect))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    detector->setAsked();
    checkAllDetect();
}

void Room::prepareDetect(std::string detector, std::string suspect)
{
    Player *detectivePlayer = findPlayer(detector);
    Player *suspectPlayer = findPlayer(suspect);
    if (detectivePlayer == NULL || suspectPlayer == NULL)
        throw UserNotJoinEx();
    if (detectivePlayer->isDead() || detectivePlayer->getRole() != Player::DETECTIVE)
        throw UserCantAskEx();
    Detective *detectiveP = dynamic_cast<Detective *>(detectivePlayer);
    //assert(detectiveP);
    if (detectiveP->isAlreadyAsked())
        throw DetectiveAlreadyAskedEx();
    if (suspectPlayer->isDead())
        throw PersonIsDeadEx();
    detect(detectiveP, suspectPlayer);
}

void Room::checkAllHeal()
{
    healCount++;
    if (healCount == roleCounts[3])
    {    
        currentPhase = GamePhases::SILENCER;
        checkPhase();
    }
}

void Room::heal(Doctor* &doctor, Player* &person)
{
    person->healed();
    doctor->setHealed();
    checkAllHeal();
}

void Room::prepareHeal(std::string doctor, std::string person)
{
    Player *doctorPlayer = findPlayer(doctor);
    Player *personPlayer = findPlayer(person);
    if (doctorPlayer == NULL || personPlayer == NULL)
        throw UserNotJoinEx();
    if (doctorPlayer->isDead() || doctorPlayer->getRole() != Player::DOCTOR)
        throw UserCantHealEx();
    Doctor *doctorP = dynamic_cast<Doctor *>(doctorPlayer);
    //assert(doctorP);
    if (doctorP->isAlreadyHealed())
        throw DoctorAlreadyHealedEx();
    if (personPlayer->isDead())
        throw PersonIsDeadEx();
    heal(doctorP, personPlayer);
}

void Room::checkAllSilenced()
{
    silentCount++;
    if (silentCount == roleCounts[7])
    {
        currentPhase = GamePhases::DAY;
        dayEvents();
    }
}

void Room::addToSilencedList(Player* person)
{
    if(!person->isSilenced())
        silencedList.push_back(person);
    person->silence();
}

void Room::silent(Silencer* &silencer, Player* &person)
{
    silencer->setSilenced();
    addToSilencedList(person);
    checkAllSilenced();
}

void Room::prepareSilent(std::string silencer, std::string person)
{
    Player *silencerPlayer = findPlayer(silencer);
    Player *personPlayer = findPlayer(person);
    if (silencerPlayer == NULL || personPlayer == NULL)
        throw UserNotJoinEx();
    if (silencerPlayer->isDead() || silencerPlayer->getRole() != Player::SILENCER)
        throw UserCantSilenceEx();
    Silencer *silencerP = dynamic_cast<Silencer *>(silencerPlayer);
    //assert(silencerP);
    if (silencerP->isAlreadySilenced())
        throw SilencerAlreadySilencedEx();
    if (personPlayer->isDead())
        throw PersonIsDeadEx();
    silent(silencerP, personPlayer);
}

void Room::checkRightPhase(Action command)
{
    if (command == Action::VOTE &&
        !(currentPhase == GamePhases::DAY || currentPhase == GamePhases::NIGHTVOTE))
        throw WrongPhaseEx();

    if (command == Action::DETECT && currentPhase != GamePhases::DETECTIVE)
        throw WrongPhaseEx();

    if (command == Action::HEAL && currentPhase != GamePhases::HEALER)
        throw WrongPhaseEx();

    if (command == Action::SILENT && currentPhase != GamePhases::SILENCER)
        throw WrongPhaseEx();
}

void Room::readAction(Action command, std::string givenLine)
{
    checkRightPhase(command);
    std::vector<std::string> givenNames;
    givenNames = splitString(givenLine);
    if (givenNames.size() != 2)
        throw BadFormatEx();
    std::string firstName = givenNames[0],
                secName = givenNames[1];
    if (command == Room::VOTE)
        prepareVote(firstName, secName);
    else if (command == Room::DETECT)
        prepareDetect(firstName, secName);
    else if (command == Room::HEAL)
        prepareHeal(firstName, secName);
    else if (command == Room::SILENT)
        prepareSilent(firstName, secName);
    //else
        //assert(false);
}

void Room::printDayNum()
{
    std::cout << "Day " << dayNum << std::endl;
}

void Room::printNightNum()
{
    std::cout << "Night " << dayNum << std::endl;
}

void Room::declareKilled(std::string userName)
{
    std::cout << "Killed " << userName << std::endl;
}

void Room::decreaseCountPlayer(Player *deadPlayer)
{
    if (deadPlayer->getRole() == Player::JOKER)
        roleCounts[0]--;
    else if (deadPlayer->getRole() == Player::VILLAGER)
        roleCounts[1]--;
    else if (deadPlayer->getRole() == Player::DETECTIVE)
        roleCounts[2]--;
    else if (deadPlayer->getRole() == Player::DOCTOR)
        roleCounts[3]--;
    else if (deadPlayer->getRole() == Player::ROUINTAN)
        roleCounts[4]--;
    else if (deadPlayer->getRole() == Player::MAFIA)
        roleCounts[5]--;
    else if (deadPlayer->getRole() == Player::GODFATHER)
        roleCounts[6]--;
    else if (deadPlayer->getRole() == Player::SILENCER)
        roleCounts[7]--;
}

void Room::setDieStatus()
{
    if (inDangerPlayer->isInDanger())
    {
        if (inDangerPlayer->getRole() == Player::ROUINTAN)
        {
            RouinTan *rouintanP = dynamic_cast<RouinTan *>(inDangerPlayer);
            //assert(rouintanP);
            if (rouintanP->isAlreadyDied())
            {
                declareKilled(inDangerPlayer->getName());
                inDangerPlayer->die();
                decreaseCountPlayer(inDangerPlayer);
            }
            else
                rouintanP->setOnceDead();
        }
        else
        {
            declareKilled(inDangerPlayer->getName());
            inDangerPlayer->die();
            decreaseCountPlayer(inDangerPlayer);
        }
    }
    checkEndGame();
}

bool Room::comparePlayer(Player* first, Player* sec)
{
    return first->getName() < sec->getName();
}

void Room::showSilencedPlayers()
{
    if (silencedList.size() > 0)
    {
        std::sort(silencedList.begin(), silencedList.end(), Room::comparePlayer);
    
        std::cout << "Silenced ";
        for (int i = 0; i < silencedList.size(); i++)
        {
            std::cout << silencedList[i]->getName();
            if (i != silencedList.size()-1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Room::dayEvents()
{
    if (dayNum == FIRSTDAY)
        printDayNum();
    else
    {
        printDayNum();
        votes.clear();
        Player::clearPlayersVotes(players);
        setDieStatus();
        showSilencedPlayers();
    }
}

void Room::getState()
{
    std::cout << "Mafia = " << aliveMafiaCount() << std::endl
              << "Villager = " << aliveVillagerCount() << std::endl;
}

void Room::checkEndGame()
{
    if (aliveMafiaCount() == 0)
    {
        currentPhase = Room::ENDGAME;
        std::cout << "Victory!" << std::endl;
    }
    else if (aliveVillagerCount() <= aliveMafiaCount())
    {
        currentPhase = Room::ENDGAME;
        std::cout << "Loose!" << std::endl;
    }
}

void Room::resetPlayers()
{
    for (int i = 0; i < players.size(); i++)
        players[i]->reset();
}

void Room::nightEvents()
{
    printNightNum();
    votes.clear();
    Player::clearPlayersVotes(players);
    inDangerPlayer = NULL;
    detectCount = 0;
    healCount = 0;
    silentCount = 0;
    silencedList.clear();
    resetPlayers();
    dayNum++;
}

void Room::checkPhase()
{
    if (currentPhase == GamePhases::DETECTIVE && roleCounts[2] == 0)
        currentPhase = GamePhases::HEALER;

    if (currentPhase == GamePhases::HEALER && roleCounts[3] == 0)
        currentPhase = GamePhases::SILENCER;

    if (currentPhase == GamePhases::SILENCER && roleCounts[7] == 0)
    {
        currentPhase = GamePhases::DAY;
        dayEvents();
    }
}

Room::GamePhases Room::getCurrentPhase() { return currentPhase; }
