#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include "skill.h"
#include "citizen.h"




namespace mtm
{
    class Employee : public Citizen
    {
        int salary;
        int score;
        vector<Skill> skills;
        
        public:
        

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

        virtual ostream& printShort(ostream& os) const override;
        virtual ostream& printLong(ostream& os) const override;

        virtual Citizen* clone() override;
        
    };
    



















}
#endif