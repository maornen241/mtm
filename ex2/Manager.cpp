#include "Manager.h"
#include "exceptions.h"


namespace mtm{
    Manager::Manager(const int id, const string first_name, 
                const string last_name, const int birth_year, int salary):
                Citizen(id, first_name, last_name, birth_year), salary(salary), employees(){}
    
    int Manager::getSalary() const
    {
        return salary;
    }

    bool Manager::hasEmployee(const Employee* employee_ptr) const
    {
        for(unsigned int i=0; i <employees.size() ; i++ )
        {
            if(  (employees[i])->getId() == employee_ptr->getId() )
            {
                return true;
            }
        }
        return false;
    }
    
    void Manager::addEmployee(const Employee*  employee_ptr)
    {
        if(hasEmployee(employee_ptr) == true)
        {
            throw EmployeeAlreadyHired();
        }

        employees.push_back(employee_ptr);
        
    }

    void Manager::removeEmployee(const int employee_id)
    {
        bool employee_exits = false;
        for(unsigned int i=0; i <employees.size() ; i++ )
        {
            if( (employees[i])->getId() == employee_id)
            {
                employee_exits = true;
                employees.erase(employees.begin()+i);
            }
        }
        if(employee_exits == false)
        {
            throw EmployeeNotHired();
        }
    }
    void Manager::setSalary(const int raise)
    {
        salary += raise;
        if(salary < 0 )
        {
            salary = 0;
        }
    }
    
    ostream& Manager::printShort(ostream& os) const
    {
        os<<getFirstName()<<" "<<getLastName()<<endl;
        os<<"Salary: "<<salary<<endl;
        return os;
    }

    ostream& Manager::printLong(ostream& os) const
    {
       os<<getFirstName()<<" "<<getLastName()<<endl;
       os<<"id - "<<getId()<<" birth_year - "<<getBirthYear()<<endl;
       os<<"Salary: "<<salary<<endl;
       os<<"Employees:"<<endl;

       for(unsigned int i=0; i <employees.size() ; i++ )
       {
           (employees[i])->printShort(os);
       }
       return os;
    }

    Citizen* Manager::clone()
    {
        return new Manager(*this);
    }
    
    










}

 
        
        

        