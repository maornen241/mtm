#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include "Skill.h"
#include "Citizen.h"




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
        virtual bool hasSkill(const int skill_id) const override;
        void setSalary(const int raise);
        void setScore(const int score_to_add);

        virtual ostream& printShort(ostream& os) const override;
        virtual ostream& printLong(ostream& os) const override;

        virtual Employee* clone() override;
        
    };
    



















}
#endif