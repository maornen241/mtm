#include "Manager.h"
#include "exceptions.h"
using std::flush;


namespace mtm{
    Manager::Manager(const int id, const string first_name, 
                const string last_name, const int birth_year, int salary):
                Citizen(id, first_name, last_name, birth_year), salary(salary), employees(){}
    
    int Manager::getSalary() const
    {
        return salary;
    }

    bool Manager::hasEmployee(Employee* employee_ptr) const
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
    
    void Manager::addEmployee(Employee*  employee_ptr)
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
            throw EmployeeIsNotHired();
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
      
       if(employees.size() > 0)
       {
        vector<Employee*> new_employees = employees;
        sort(new_employees.begin(), new_employees.end(), CompareEmployees);  
        os<<"Employees: "<<endl;

        for(unsigned int i=0; i <new_employees.size() ; i++ )
        {
               (new_employees[i])->printShort(os);
        }
       }
       return os;
    }

    Manager* Manager::clone()
    {
        return new Manager(*this);
    }


    Employee* Manager::giveEmployeeFromManager(const int employee_id) const
    {
        for(Employee* employee_ptr : employees)
        {
            if(employee_ptr->getId() == employee_id)
            {
                return employee_ptr;
            }
        }
        throw EmployeeIsNotHired();
    }

    void Manager::changeAllEmployeesSalary(const int amount_to_change)
    {
        for(Employee* employee_ptr : employees)
        {
            employee_ptr->setSalary(amount_to_change);
        }
    }

    void Manager::removeAllEmployees()
    {
        for(Employee* employee_ptr : employees)
        {
            int employee_id = employee_ptr->getId();
            removeEmployee(employee_id);
        } 
    }

    bool CompareEmployees(Employee* employee_ptr1, Employee* employee_ptr2)
    {
        return (employee_ptr1->getId() < employee_ptr2->getId());
    }

    
    










}

 
        
        

        