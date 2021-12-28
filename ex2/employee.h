#include <iostream>
#include "skill.h"
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::vector<Skill>;


namespace mtm
{
    class Employee:public Citizen
    {
        int salary;
        int score;
        vector<Skill> skills;
        
        public:
        class Exceptions: public std::exception{};
        class SkillAlreadyLearned:public Exceptions{};
        class CanNotLearnSkill:public Exceptions{};
        class DidNotLearnSkill:public Exceptions{};

        Employee(const int id, const string first_name, 
                const string last_name, const int birth_year,
                 int salary=0, int score=0);

        ~Employee() = default;
        Employee(const Employee& employee) = default;

        int getSalary() const;
        int getScore() const;

        void learnSkill(const Skill skill);
        void forgetSkill(const int skill_id);
        bool hasSkill(const int skill_id) const;
        void setSalary(const int raise);
        void setScore(const int score_to_add);

        virtual ostream printShort(ostream os);
        virtual ostream printLong(ostream os);

        virtual Citizen* clone();
        
    };
    



















}