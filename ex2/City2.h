// #ifndef __CITY_H__
// #define __CITY_H__
// #include "Skill.h"
// #include "Employee.h"
// #include "Manager.h"
// #include "Faculty.h"
// #include <algorithm>
// #include <vector>
// #include "Citizen.h"
// #include "exceptions.h"



// namespace mtm
// {
//     using std::vector;

//     class Condition
//     {
//         public:
//             virtual bool operator()(Employee* employee) = 0;
//     }; 



//     class isEqualById
//     {
//         const int id_to_check;
//         public:
//             isEqualById(const int id_to_check):
//                             id_to_check(id_to_check){};

//         template <class T>
//         bool operator()(T* ptr)
//         {
//              return (ptr->getId()) == id_to_check;
//         }
//     };

//      class CompareCitizensById
//      {
//          public:
//             bool operator()(Citizen* citizen1, Citizen* citizen2)
//             {
//                 return (citizen1->getId() < citizen2->getId());
//             }
//      };
        







//     class City
//     {
//     const string name;
//     vector<Citizen*> citizens;
//     vector<Faculty<Condition>*> faculties;
//     vector<Workplace*> workplaces; 

    

//     public:
//         City(const string name);
//         ~City() = default;
//         City(const City& city) = default;

//         void addEmployee(const int id, const string& first_name,
//                          const string& last_name, const int birth_year);
        
//         void addManager(const int id, const string& first_name,
//                          const string& last_name, const int birth_year);
        
//         void addFaculty(const int id, Condition* condition_ptr,
//                         const Skill& skill, int added_points);

//         void createWorkplace(const int id, const string& name,
//                              const int workers_salary, const int managers_salary);

//         void teachAtFaculty(const int worker_id, const int faculty_id);

//         template <class T>
//         void hireEmployeeAtWorkplace(T hiring_condition, const int worker_id,
//                                     const int manager_id, const int workplace_id);
        
//         void hireManagerAtWorkplace(const int manager_id, const int workplace_id);

//         void fireEmployeeAtWorkplace(const int worker_id, const int manager_id,
//                                       const int workplace_id);

//         void fireManagerAtWorkplace(const int manager_id, const int workplace_id);

//         int getAllAboveSalary(ostream& os, const int salary) const;

//         bool isWorkingInTheSameWorkplace(const int id1, const int id2) const;

//         void printAllEmployeesWithSkill(ostream& os, const int skill_id) const;  
        
//     };

    
//     template <class T>
//     void City::hireEmployeeAtWorkplace(T hiring_condition, const int worker_id,
//                                        const int manager_id, const int workplace_id)
//     {
//         isEqualById is_equal_worker(worker_id);
//         std::vector<Citizen*>::iterator employee_it = citizens.begin();
//         employee_it = std::find_if(citizens.begin(), citizens.end(), is_equal_worker);
//         if(employee_it == citizens.end())
//         {
//             throw WorkplaceDoesNotExist();
//         }

//         isEqualById is_equal_manager(manager_id);
//         std::vector<Citizen*>::iterator manager_it = citizens.begin();
//         manager_it = std::find_if(citizens.begin(), citizens.end(), is_equal_manager);
//         if(manager_it == citizens.end())
//         {
//             throw ManagerDoesNotExist();
//         }

//         isEqualById is_equal_workplace(workplace_id);
//         std::vector<Workplace*>::iterator workplace_it = workplaces.begin();
//         workplace_it = std::find_if(workplaces.begin(), workplaces.end(),
//                                      is_equal_workplace);
//         if(workplace_it == workplaces.end())
//         {
//             throw WorkplaceDoesNotExist();
//         }

//         //do we need to add <T> ?
//         ( (*workplace_it)->hireEmployee)(hiring_condition, *employee_it, manager_id);


//     }

    


//     }
