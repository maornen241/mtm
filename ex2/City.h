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



    // class isEqualById
    // {
    //     const int id_to_check;
    //     public:
    //         isEqualById(const int id_to_check):
    //                         id_to_check(id_to_check){};

    //     template <class T>
    //     bool operator()(T* ptr)
    //     {
    //          return (ptr->getId()) == id_to_check;
    //     }
    // };



      
      
    //  class CompareManagerById
    //  {
    //      public:
    //         bool operator()(manager manager1, manager manager2)
    //         {
    //             return (manager1.getId() < manager2.getId());
    //         }
    //   };

    //  class CompareCitizensById
    //  {
    //      public:
    //         bool operator()(Citizen* citizen1, Citizen* citizen2) const
    //         {
    //             return (citizen1->getId() < citizen2->getId());
    //         }
    //   };

    // class CompareEmployeeById
    //  {
    //      public:
    //         bool operator()(Employee* employee1_ptr, Employee* employee2_ptr) const
    //         {
    //             return (employee1_ptr->getId() < employee2_ptr->getId());
    //         }
    //   };



        // bool compareEmployeesFunc(Employee*  emp1, Employee*  emp2) 
        // {
        //     return (emp1->getId() < emp2->getId());
        // }

    template <class Type, class Exception>
    Type* giveById(vector<Type*> my_vec, const int id) // לפצל לשתי פונקציות לא גנריות
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
        ~City() = default;
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