#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>
#include "Citizen.h"
#include "Employee.h"
#include "Skill.h"
#include "exceptions.h"



namespace mtm
{
    //comparing two employees by their id
    bool CompareEmployees(Employee* employee_ptr1, Employee* employee_ptr2);

    class Manager: public Citizen
    {
    private:
        int salary;
        vector<Employee*> employees;

    public:

        Manager(const int id, const string first_name, 
                const string last_name, const int birth_year,
                int salary=0);
        Manager() = delete;
        ~Manager() = default;
        Manager(const Manager& manager) = default;

        int getSalary() const;
        bool hasEmployee(Employee* employee_ptr) const;
        void addEmployee(Employee* employee_ptr);
        void removeEmployee(const int employee_id);
        void setSalary(const int raise);

        //given an amoumt- changes all salarys of employees in a given manager
        void changeAllEmployeesSalary(const int amount_to_change);

        //removing all employees from a given manager
        void removeAllEmployees();


        virtual ostream& printShort(ostream& os) const override;
        virtual ostream& printLong(ostream& os) const override;

        virtual Manager* clone() override;

        //finding employee in a given manager by the employee's id and returns the employee ptr
        //if employee dosen't exist throws EmployeeIsNotHired
        Employee* giveEmployeeFromManager(const int employee_id) const;

        
    };
    
   
}

















































#endif