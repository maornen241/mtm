
#include <iostream>
#include "skill.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

namespace mtm
{
    Skill::Skill(const int id, const string name, int points_for_skill):
    id(id), name(name), points(points_for_skill){}

    const int Skill::getId() const
    {
        return id;
    }

    const string Skill::getName() const
    {
        return name;
    }

    int Skill::getRequiredPoints() const
    {
        return points;
    }

        //ostream& operator<<(ostream& os, const Skill& my_skill);


    bool Skill::operator<(const Skill& skill_to_check)
    {
        return (id < skill_to_check.id);
    }


    bool Skill::operator>(const Skill& skill_to_check)
    {
        return (id > skill_to_check.id);
    }

    bool Skill::operator<=(const Skill& skill_to_check)
    {
        return (id <= skill_to_check.id);            
    }

    bool Skill::operator>=(const Skill& skill_to_check)
    {
        return (id >= skill_to_check.id);            
    }

    bool Skill::operator==(const Skill& skill_to_check)
    {
        return (id == skill_to_check.id);            
    }

    bool Skill::operator!=(const Skill& skill_to_check)
    {
        return (id != skill_to_check.id);            
    }


    Skill Skill::operator++(int)
    {
        Skill copied_skill(*this);
        (this->points) += 1;
        return copied_skill;
    }

    Skill& Skill::operator+=(const int points_to_add)
    {
        //we need to add an exception if point_to_add < 0
        (this->points) += points_to_add;
        return *this;
    }

   int operator+(const int points, const Skill& skill)
   {
       return points+(skill.getRequiredPoints());
   }

    int operator+(const Skill& skill)
   {
       return points+(skill.getRequiredPoints());
   }


}


