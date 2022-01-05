#include "City.h"
using std::sort;




namespace mtm
{

        City::City(const string name):
                name(name), citizens(), faculties(), workplaces(){}



        void  City::addEmployee(const int id, const string& first_name,
                                const string& last_name, const int birth_year)
        {
                isEqualById is_equal_employee(id);
                std::vector<Citizen*>::iterator employee_it = citizens.begin();
                employee_it = std::find_if(citizens.begin(), citizens.end(), is_equal_employee);
                if(employee_it != citizens.end())
                {
                        throw CitizenAlreadyExists();
                }
                
                Employee employee(id, first_name, last_name, birth_year);
                citizens.push_back(&employee);
        }




    void City::addFaculty(const int id, Condition* condition_ptr,
                    const Skill& skill, int added_points)
    {
        isEqualById is_equal_faculty(id);
        std::vector<Faculty<Condition>*>::iterator it = faculties.begin();
        it = std::find_if(faculties.begin(), faculties.end(), is_equal_faculty);

        if(it != faculties.end())
        {
            throw FacultyAlreadyExists();
        }

        Faculty<Condition> faculty(id, condition_ptr, skill, added_points);
        faculties.push_back(&faculty);
    }


        void  City::addManager(const int id, const string& first_name,
                                const string& last_name, const int birth_year)
        {
                isEqualById is_equal_manager(id);
                std::vector<Citizen*>::iterator manager_it = citizens.begin();
                manager_it = std::find_if(citizens.begin(), citizens.end(),
                                          is_equal_manager);
                if(manager_it != citizens.end())
                {
                        throw CitizenAlreadyExists();
                }
                
                Manager manager(id, first_name, last_name, birth_year);
                citizens.push_back(&manager);
        }


        void  City::createWorkplace(const int id, const string& name,
                                const int workers_salary, const int managers_salary)
        {
                isEqualById is_equal_workplace(id);
                std::vector<Workplace*>::iterator workplace_it = workplaces.begin();
                workplace_it = std::find_if(workplaces.begin(), workplaces.end(), 
                                            is_equal_workplace);
                if(workplace_it != workplaces.end())
                {
                        throw WorkplaceAlreadyExists();
                }
                
                Workplace workplace(id, name, workers_salary, managers_salary);
                workplaces.push_back(&workplace);
        }




        void  City::teachAtFaculty(const int worker_id, const int faculty_id)
        {
                isEqualById is_equal_employee(worker_id);
                std::vector<Citizen*>::iterator employee_it = citizens.begin();
                employee_it = std::find_if(citizens.begin(), citizens.end(), is_equal_employee);
                if(employee_it == citizens.end())
                {
                        throw EmployeeDoesNotExist();
                }

                isEqualById is_equal_faculty(faculty_id);
                std::vector<Faculty<Condition>*>::iterator faculty_it = faculties.begin();
                faculty_it = std::find_if(faculties.begin(), faculties.end(),
                                         is_equal_faculty);
                if(faculty_it == faculties.end())
                {
                        throw FacultyDoesNotExist();
                }

                (*faculty_it)->teach(*employee_it);

        }





        void  City::hireManagerAtWorkplace(const int manager_id, const int workplace_id)
        {
                isEqualById is_equal_manager(manager_id);
                std::vector<Citizen*>::iterator manager_it = citizens.begin();
                manager_it = std::find_if(citizens.begin(), citizens.end(), is_equal_manager);
                if(manager_it == citizens.end())
                {
                        throw ManagerDoesNotExist();
                }
                
                isEqualById is_equal_workplace(workplace_id);
                std::vector<Workplace*>::iterator workplace_it = workplaces.begin();
                workplace_it = std::find_if(workplaces.begin(), workplaces.end(),
                                            is_equal_workplace);
                if(workplace_it == workplaces.end())
                {
                        throw WorkplaceDoesNotExist();
                }

                (*workplace_it)->hireManager(*manager_it);
                
        }




        void  City::fireEmployeeAtWorkplace(const int worker_id, const int manager_id,
                                        const int workplace_id)
        {
                isEqualById is_equal_worker(worker_id);
                std::vector<Citizen*>::iterator employee_it = citizens.begin();
                employee_it = std::find_if(citizens.begin(), citizens.end(), is_equal_worker);
                if(employee_it == citizens.end())
                {
                        throw EmployeeDoesNotExist();
                }

                isEqualById is_equal_manager(manager_id);
                std::vector<Citizen*>::iterator manager_it = citizens.begin();
                manager_it = std::find_if(citizens.begin(), citizens.end(), is_equal_manager);
                if(manager_it == citizens.end())
                {
                        throw ManagerDoesNotExist();
                }

                isEqualById is_equal_workplace(workplace_id);
                std::vector<Workplace*>::iterator workplace_it = workplaces.begin();
                workplace_it = std::find_if(workplaces.begin(), workplaces.end(),
                                            is_equal_workplace);
                if(workplace_it == workplaces.end())
                {
                        throw WorkplaceDoesNotExist();
                }

                (*workplace_it)->fireEmployee(worker_id , manager_id);
                
        }  
           
        
        
        void  City::fireManagerAtWorkplace(const int manager_id, const int workplace_id)
        {
                isEqualById is_equal_manager(manager_id);
                std::vector<Citizen*>::iterator manager_it = citizens.begin();
                manager_it = std::find_if(citizens.begin(), citizens.end(), is_equal_manager);
                if(manager_it == citizens.end())
                {
                        throw ManagerDoesNotExist();
                }

                isEqualById is_equal_workplace(workplace_id);
                std::vector<Workplace*>::iterator workplace_it = workplaces.begin();
                workplace_it = std::find_if(workplaces.begin(), workplaces.end(),
                                        is_equal_workplace);
                if(workplace_it == workplaces.end())
                {
                        throw WorkplaceDoesNotExist();
                }

                (*workplace_it)->fireManager(manager_id);
        }

        
        
        
        
        
        int  City::getAllAboveSalary(ostream& os, const int salary) const
        {
            CompareCitizensById compare_by_id();    
            sort(citizens.begin(), citizens.end(), compare_by_id);

            for(Citizen* citizen_ptr : citizens)
            {
                if(citizen_ptr->getSalary() > salary)
                {
                        citizen_ptr->printShort(os);
                }
            }    
                
        }

        bool  City::isWorkingInTheSameWorkplace(const int id1, const int id2) const
        {
                isEqualById is_equal1(id1);
                std::vector<Citizen*>::iterator employee_it1 = citizens.begin();
                employee_it1 = std::find_if(citizens.begin(), citizens.end(), is_equal1);
                if(employee_it1 == citizens.end())
                {
                        throw EmployeeDoesNotExist();
                }
                
                isEqualById is_equal2(id2);
                std::vector<Citizen*>::iterator employee_it2 = citizens.begin();
                employee_it2 = std::find_if(citizens.begin(), citizens.end(), is_equal2);
                if(employee_it2 == citizens.end())
                {
                        throw EmployeeDoesNotExist();
                }

                for(Workplace* workplace_ptr : workplaces)
                {
                     if(workplace_ptr->hasEmployee(*employee_it1) &&
                        workplace_ptr->hasEmployee(*employee_it2))
                     {
                        return true;
                     }   
                }
                return false;
        }

        void  City::printAllEmployeesWithSkill(ostream& os, const int skill_id) const 
        {
             for(Citizen* citizen_ptr : citizens)
             {
                     if(citizen_ptr->hasSkill(skill_id) == true)
                     {
                        citizen_ptr->printShort(os);
                     }
             }   
        }








































    
}