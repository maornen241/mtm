#ifndef __FACULTY_H__
#define __FACULTY_H__

#include "employee.h"
#include "citizen.h"
#include "manager.h"
#include "skill.h"
#include "workplace.h"

namespace mtm
{

    class Condition
    {
        public:
            virtual bool operator()(Employee* employee) = 0;
    }; 


    template <class T>
    class Faculty
    {
        const int id;
        T& condition;
        const Skill& skill;
        int added_points;

        
    public:
        Faculty(const int id, T& condition,
                const Skill& skill, int added_points);
        ~Faculty() = default;
        Faculty(const Faculty& faculty) = default;

        const Skill& getSkill() const;
        const int getId() const;
        int getAddedPoints() const;

        void teach(Employee* employee_ptr) const;
    };

    template <class T>
    Faculty<T>::Faculty(const int id, T& condition,
                    const Skill& skill, int added_points):
                    id(id), condition(condition),
                     skill(skill), added_points(added_points){}

    template <class T>
    const Skill& Faculty<T>::getSkill() const
    {
        return skill;
    }

    template <class T>
    const int Faculty<T>::getId() const
    {
        return id;
    }

    template <class T>
    int Faculty<T>::getAddedPoints() const
    {
        return added_points;
    }

    template <class T>
    void Faculty<T>::teach(Employee* employee_ptr) const
    {
       if(condition(employee_ptr) == false)
       {
           throw EmployeeNotAccepted();
       } 

       if(employee_ptr->hasSkill(skill.getId()) == false)
       {
          employee_ptr->learnSkill(skill);
          employee_ptr->setScore(added_points);
       }
    }



    






















}























#endif