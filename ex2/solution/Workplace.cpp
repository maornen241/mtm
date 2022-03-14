#include "Workplace.h"
#include "exceptions.h"
using std::flush;

namespace mtm
{
    Workplace::Workplace(const int id, const string& name,
     const int workers_salary, const int managers_salary):
     id(id), name(name), workers_salary(workers_salary),
     managers_salary(managers_salary), managers(){}
    
    int Workplace::getId() const
    {
        return id;
    }
    string Workplace::getName() const
    {
        return name;
    }
    
    int Workplace::getWorkersSalary() const
    {
        return workers_salary;
    }
    int Workplace::getManagerSalary() const
    {
        return managers_salary;
    }


    void Workplace::hireManager(Manager* manager_ptr)
    {
        if(hasManager(manager_ptr->getId()) == true)
        {
            throw ManagerAlreadyHired();
        }
        if(manager_ptr->getSalary() > 0)
        {
            throw CanNotHireManager();
        }
        manager_ptr->setSalary(managers_salary);
        manager_ptr->changeAllEmployeesSalary(workers_salary);
        managers.push_back(manager_ptr);
    }

    void Workplace::fireEmployee(const int employee_id ,const int manager_id)
    {
        Manager* manager_ptr = giveManager(manager_id);//throws exception if manager not exist
        Employee* employee_ptr = manager_ptr->giveEmployeeFromManager(employee_id);
        employee_ptr->setSalary(-workers_salary);
        manager_ptr->removeEmployee(employee_id);//throws exception if employee not exist
    }

    void Workplace::fireManager(const int manager_id)
    {
        for(unsigned int i = 0; i < managers.size(); i++)
        {
            if(managers[i]->getId() == manager_id)
            {
                (managers[i])->setSalary(-managers_salary);
                (managers[i])->changeAllEmployeesSalary(-workers_salary);
                managers.erase(managers.begin()+i);
                return;
            }
        }
        throw ManagerIsNotHired();
    }

    ostream& operator<<(ostream& os, const Workplace& workplace)
    {
        os<<"Workplace name - "<<workplace.getName()<<flush;

        if((workplace.managers).empty() == false)
        {
            vector<Manager*> sorted_managers = workplace.managers;
            sort(sorted_managers.begin(), sorted_managers.end(), CompareManagers);

            os<<" Groups:"<<endl;
            for(Manager* manager_ptr : sorted_managers)
            {
                os<<"Manager "<<flush;
                manager_ptr->printLong(os);
            }
        }
        else
        {
            os<<endl;
        }
        return os;
    }


    bool Workplace::hasManager(const int manager_id) const
    {
        for(unsigned int i = 0; i < managers.size(); i++)
        {
            if( (managers[i])->getId() == manager_id)
            {
                return true;
            }
        }
        return false;
    }


    Manager* Workplace::giveManager(const int manager_id) const
    {

        for(unsigned int i = 0; i < managers.size(); i++)
         {
             if( (managers[i])->getId() == manager_id)
             {
                 return managers[i];
             }
         }
         throw ManagerIsNotHired();
    }

    bool Workplace::hasEmployee(Employee* employee) const
    {
        for(Manager* manager_ptr : managers)
        {
            if(manager_ptr->hasEmployee(employee))
            {
                return true;
            }
        }
        return false;
    }


    bool CompareManagers(Manager* manager_ptr1, Manager* manager_ptr2)
    {
        return (manager_ptr1->getId() < manager_ptr2->getId());
    }














}