#include "workplace.h"
#include "exceptions.h"

namespace mtm
{
    Workplace::Workplace(const int id, const string& name,
     const int workers_salary, const int managers_salary):
     id(id), name(name), workers_salary(workers_salary),
     managers_salasry(managers_salary), managers(){}
    
    int Workplace::getId()
    {
        return id;
    }
    string Workplace::getName()
    {
        return name;
    }
    
    int Workplace::getWorkersSalary()
    {
        return workers_salary;
    }
    int Workplace::getManagerSalary()
    {
        return managers_salary;
    }


    void Workplace::hireEmployee(Condition* hiring_condition, 
                                 Employee* employee_ptr, const int manager_id)
    {
        if((*hiring_condition)(employee_ptr) == false)
        {
            throw EmployeeNotSelected();
        }
        Manager* manager_ptr = giveManager(manager_id);
        manager_ptr->addEmployee(employee_ptr);
        
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
        managers.push_back(manager_ptr);
    }

    void Workplace::fireEmployee(const int employee_id ,const int manager_id)
    {
        Manager* manager_ptr = giveManager(manager_id);//throws exception if manager not exist
        manager_ptr->removeEmployee(employee_id);//throws exception if employee not exist
    }

    void Workplace::fireManager(const int manager_id)
    {
        for(unsigned int i = 0; i < managers.size(); i++)
        {
            if(managers[i]->getId == manager_id)
            {
                managers.erase(managers.begin()+i);
                return;
            }
        }
        throw ManagerIsNotHired();
    }

    ostream& operator<<(ostream& os, const Workplace& workplace)
    {
        os<<"Workplace name - "<<name<<flush;

        if((workplace.managers).empty() == false)
        {
            os<<" Groups:"<<endl;
            for(unsigned int i = 0; i < (workplace.managers).size(); i++)
            {
                ((workplace.managers)[i])->printLong(os);
            }
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
             if( (managers[i]).getId() == manager_id)
             {
                 return managers[i];
             }
         }
         throw ManagerIsNotHired();
    }















}