#ifndef __WORKPLACE__
#define __WORKPLACE__

#include <iostream>
#include "skill.h"
#include "citizen.h"
#include "employee.h"
#include "manager.h"

using std::flush;



namespace mtm
{

    class Condition
    {
        public:
            virtual bool operator()(Employee* employee) = 0;
    };


class Workplace
{
    const int id;
    const string name;
    int workers_salary;
    int manageres_salary;
    vector<Manager*> managers;

    bool hasManager(const int manager_id) const;
    Manager* giveManager(const int manager_id) const;

    public:
    Workplace(const int id, const string& name, const int workers_salary,
              const int managers_salary);
    Workplace(const Workplace& workplace) = default;
    ~Workplace() = default;

    int getId();
    string getName();
    int getWorkersSalary();
    int getManagerSalary();
    void hireEmployee(Condition* hiring_condition,
                      Employee* employee_ptr, const int manager_id);
    void hireManager(Manager* manager_ptr);
    void fireEmployee(const int employee_id ,const int manager_id);
    void fireManager(const int manager_id);

    friend ostream& operator<<(ostream& os, const Workplace& workplace);
};

    ostream& operator<<(ostream& os, const Workplace& workplace);




















}


































#endif