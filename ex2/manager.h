#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>
#include "citizen.h"
#include "employee.h"
#include "skill.h"
#include "exceptions.h"



namespace mtm
{
    class Manager: public Citizen
    {
    private:
        int salary;
        vector<const Employee*> employees;

    public:

        Manager(const int id, const string first_name, 
                const string last_name, const int birth_year,
                int salary=0);
        Manager() = delete;
        ~Manager() = default;
        Manager(const Manager& manager) = default;

        int getSalary() const;
        bool hasEmployee(const Employee* employee_ptr) const;
        void addEmployee(const Employee* employee_ptr);
        void removeEmployee(const int employee_id);
        void setSalary(const int raise);


        virtual ostream& printShort(ostream& os) const override;
        virtual ostream& printLong(ostream& os) const override;

        virtual Citizen* clone() override;
        
    };
    
   
}

















































#endif