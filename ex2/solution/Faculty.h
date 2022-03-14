#ifndef __FACULTY_H__
#define __FACULTY_H__

#include "Employee.h"
#include "Citizen.h"
#include "Manager.h"
#include "Skill.h"
#include "Workplace.h"

namespace mtm
{

    template <class T>
    class Faculty
    {
        const int id;
        T* condition_ptr;
        const Skill& skill;
        int added_points;

        
    public:
        
        Faculty(const int id, const Skill& skill, int added_points, T* condition_ptr);
        
        ~Faculty() = default;
        Faculty(const Faculty& faculty) = default;

        const Skill& getSkill() const;
        const int getId() const;
        int getAddedPoints() const;

        void teach(Employee* employee_ptr) const;
    };

    template <class T>
    Faculty<T>::Faculty(const int id, const Skill& skill, int added_points, T* condition_ptr):
                    id(id), condition_ptr(condition_ptr),
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
       if((*condition_ptr)(employee_ptr) == false)
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