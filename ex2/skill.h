#ifndef __SKILL_H__
#define __SKILL_H__

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

namespace mtm{

    class Skill
    {
        int id;
        string name;
        int points;

        public:
        class Exceptions: public std::exception{};
        class NegativePoints:public Exceptions{};


        Skill(const int id, const string name, int points_for_skill);
        Skill() = delete;
        Skill(const Skill&) = default;

        //const int getId();
        const int getId() const;
        //const string getName();
        const string getName() const;
        int getRequiredPoints() const;

        friend ostream& operator<<(ostream& os, const Skill& my_skill);
        bool operator<(const Skill& skill_to_check);
        bool operator>(const Skill& skill_to_check);
        bool operator<=(const Skill& skill_to_check);
        bool operator>=(const Skill& skill_to_check);
        bool operator==(const Skill& skill_to_check);
        bool operator!=(const Skill& skill_to_check);
        Skill operator++(int);
        Skill& operator+=(const int points_to_add);
        Skill& operator=(const Skill& skill);

        

    };

   ostream& operator<<(ostream& os, const Skill& my_skill);
   Skill& operator+(const int points, Skill& skill);
   Skill& operator+(Skill& skill, const int points);





}
#endif