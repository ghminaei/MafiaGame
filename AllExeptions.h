#ifndef AllExeptions_H
#define AllExeptions_H
#include <exception>

class DuplicateRoomNameEx: public std::exception
{
  virtual const char* what() const throw();
};

class InvalidRoomNameEx: public std::exception
{
  virtual const char* what() const throw();
};

class WrongCommandEx: public std::exception
{
  virtual const char* what() const throw();
};

class WrongRoleEx: public std::exception
{
  virtual const char* what() const throw();
};

class WrongNumberEx: public std::exception
{
  virtual const char* what() const throw();
};

class BadFormatEx: public std::exception
{
  virtual const char* what() const throw();
};

class WrongCountEx: public std::exception
{
  virtual const char* what() const throw();
};

class ManyUsersEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserNotJoinEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserCantVoteEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserAlreadyDiedEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserSilencedEx: public std::exception
{
  virtual const char* what() const throw();
};

class DetectiveAlreadyAskedEx: public std::exception
{
  virtual const char* what() const throw();
};

class PersonIsDeadEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserCantAskEx: public std::exception
{
  virtual const char* what() const throw();
};

class DoctorAlreadyHealedEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserCantHealEx: public std::exception
{
  virtual const char* what() const throw();
};

class UserCantSilenceEx: public std::exception
{
  virtual const char* what() const throw();
};

class SilencerAlreadySilencedEx: public std::exception
{
  virtual const char* what() const throw();
};

class WrongPhaseEx: public std::exception
{
  virtual const char* what() const throw();
};

class NotInARoomEx: public std::exception
{
  virtual const char* what() const throw();
};

class DuplicateNameEx: public std::exception
{
  virtual const char* what() const throw();
};

#endif