#include "AllExeptions.h"

const char* DuplicateRoomNameEx::what() const throw()
{
    return "Duplicate room name\n";
}

const char* InvalidRoomNameEx::what() const throw()
{
    return "Invalid room name\n";
}

const char* WrongCommandEx::what() const throw()
{
    return "Invalid command\n";
}

const char* WrongRoleEx::what() const throw()
{
    return "Invalid Role\n";
}

const char* WrongNumberEx::what() const throw()
{
    return "Invalid Number\n";
}

const char* BadFormatEx::what() const throw()
{
    return "Foramt is not right\n";
}

const char* WrongCountEx::what() const throw()
{
    return "Count of roles is not right\n";
}

const char* ManyUsersEx::what() const throw()
{
    return "many users\n";
}

const char* UserNotJoinEx::what() const throw()
{
    return "User not joined\n";
}

const char* UserCantVoteEx::what() const throw()
{
    return "This user can not vote\n";
}

const char* UserAlreadyDiedEx::what() const throw()
{
    return "User already died\n";
}

const char* UserSilencedEx::what() const throw()
{
    return "This user has been silenced before\n";
}

const char* DetectiveAlreadyAskedEx::what() const throw()
{
    return "Detective has alreay asked\n";
}

const char* PersonIsDeadEx::what() const throw()
{
    return "Person is dead\n";
}

const char* UserCantAskEx::what() const throw()
{
    return "User can not ask\n";
}

const char* DoctorAlreadyHealedEx::what() const throw()
{
    return "Doctor has alreay healed\n";
}

const char* UserCantHealEx::what() const throw()
{
    return "User can not heal\n";
}

const char* UserCantSilenceEx::what() const throw()
{
    return "User can not silence\n";
}

const char* SilencerAlreadySilencedEx::what() const throw()
{
    return "Silencer has alreay silenced\n";
}

const char* WrongPhaseEx::what() const throw()
{
    return "Room is not in this phase\n";
}

const char* NotInARoomEx::what() const throw()
{
    return "You are not in a room yet\n";
}

const char* DuplicateNameEx::what() const throw()
{
    return "User has already joined, try again\n";
}