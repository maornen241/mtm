#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <exception>

namespace mtm{
class Exceptions: public std::exception{};
class SkillAlreadyLearned:public Exceptions{};
class CanNotLearnSkill:public Exceptions{};
class DidNotLearnSkill:public Exceptions{};
class NegativePoints:public Exceptions{};
class EmployeeAlreadyHired: public Exceptions{};
class EmployeeNotHired: public Exceptions{};
class EmployeeNotSelected: public Exceptions{};
class ManagerIsNotHired: public Exceptions{};
class ManagerAlreadyHired: public Exceptions{};
class CanNotHireManager: public Exceptions{};
class EmployeeNotAccepted: public Exceptions{};


}


































#endif