#ifndef __WORKPLACE__
#define __WORKPLACE__

#include <iostream>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"

using std::flush;



namespace mtm
{


class Workplace
{
    const int id;
    const string name;
    int workers_salary;
    int managers_salary;
    vector<Manager*> managers;

    bool hasManager(const int manager_id) const;
    Manager* giveManager(const int manager_id) const;

    public:
    Workplace(const int id, const string& name, const int workers_salary,
              const int managers_salary);
    Workplace(const Workplace& workplace) = default;
    ~Workplace() = default;

    int getId() const;
    string getName() const;
    int getWorkersSalary() const;
    int getManagerSalary() const;
    template <class T>
    void hireEmployee(T condition, Employee* employee_ptr,
                       const int manager_id);
    void hireManager(Manager* manager_ptr);
    void fireEmployee(const int employee_id ,const int manager_id);
    void fireManager(const int manager_id);

    bool hasEmployee(Employee* employee) const;

    friend ostream& operator<<(ostream& os, const Workplace& workplace);
};

    ostream& operator<<(ostream& os, const Workplace& workplace);
    
    template <class T>
    void Workplace::hireEmployee(T condition, Employee* employee_ptr,
                                 const int manager_id)
    {
        if(condition(employee_ptr) == false)
        {
            throw EmployeeNotSelected();
        }
        Manager* manager_ptr = giveManager(manager_id);
        manager_ptr->addEmployee(employee_ptr);
        
    }




















}


































#endif