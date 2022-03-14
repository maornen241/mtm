#ifndef __CITY_H__
#define __CITY_H__
#include "Skill.h"
#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"
#include <algorithm>
#include <vector>
#include "Citizen.h"
#include "exceptions.h"



namespace mtm
{
    using std::vector;

    class Condition
    {
        public:
            virtual bool operator()(Employee* employee) = 0;
    }; 


    /**
    * giveById: returns an object in a vector by it's id,
    *             and throws Exception if not found
    *
    * 
    *
    * @param my_vc - vector with Type* where Type has a method getId()
             (Citizen, Workplace, Facilty...)
    
    * @param id - the specific id of the object that we seek.      
     
    * @return
    *     the first object in my_vec with the given id
    *      if my_vec has no object witj id, throws Exception()
    */
    
    template <class Type, class Exception>
    Type* giveById(vector<Type*> my_vec, const int id) 
    {
        for(Type* current_ptr : my_vec)
        {
            if(current_ptr->getId() == id)
            {
                return current_ptr;
            }
        }
        throw Exception();
    }

      /**
    * isIdInVector: boolean function that return true if an object with a given id 
    * is found in a given vector my vec
    *     
    * @param my_vec - vector with Type* where Type has a method getId()
             (Citizen, Workplace, Facilty...)
    
    * @param id - the specific id of the object that we seek.      
     
    * @return
    *     true - if there is an object with the given id in the vector.
    *     false - otherwise.  
    *      
    */

    template <class Type>
    bool isIdInVector(vector<Type*> my_vec, const int id)
    {
        for(Type* current_ptr : my_vec)
        {
            if(current_ptr->getId() == id)
            {
                return true;
            }
        }
        return false;
    }




    class City
    {
    const string name;
    vector<Employee*> employees;
    vector<Manager*> managers;
    vector<Faculty<Condition>*> faculties;
    vector<Workplace*> workplaces; 

    

    public:
        City(const string name);
        ~City();
        City(const City& city) = default;

        void addEmployee(const int id, const string& first_name,
                         const string& last_name, const int birth_year);
        
        void addManager(const int id, const string& first_name,
                         const string& last_name, const int birth_year);
        
        void addFaculty(const int id, const Skill& skill,
                        int added_points, Condition* condition_ptr);

        void createWorkplace(const int id, const string& name,
                             const int workers_salary, const int managers_salary);

        void teachAtFaculty(const int worker_id, const int faculty_id);

        template <class T>
        void hireEmployeeAtWorkplace(T hiring_condition, const int worker_id,
                                    const int manager_id, const int workplace_id);
        
        void hireManagerAtWorkplace(const int manager_id, const int workplace_id);

        void fireEmployeeAtWorkplace(const int worker_id, const int manager_id,
                                      const int workplace_id);

        void fireManagerAtWorkplace(const int manager_id, const int workplace_id);

        int getAllAboveSalary(ostream& os, const int salary) const;

        bool isWorkingInTheSameWorkplace(const int id1, const int id2) const;

        void printAllEmployeesWithSkill(ostream& os, const int skill_id) const;  
        
    };

    
    template <class T>
    void City::hireEmployeeAtWorkplace(T hiring_condition, const int worker_id,
                                       const int manager_id, const int workplace_id)
    {
        Employee* employee_ptr = giveById<Employee, EmployeeDoesNotExist>(employees, worker_id);
        giveById<Manager, ManagerDoesNotExist>(managers, manager_id);
        Workplace* workplace_ptr = giveById<Workplace,
                                   WorkplaceDoesNotExist>(workplaces, workplace_id);

        workplace_ptr->hireEmployee<T>(hiring_condition, employee_ptr, manager_id);

    }

    


}





    










































    



































#endif