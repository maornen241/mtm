#include "City.h"
using std::sort;




namespace mtm
{
        bool compareCitizensFunc(Citizen* citizen1, Citizen* citizen2) 
        {
            return (citizen1->getId() < citizen2->getId());
        }

        City::City(const string name):
                name(name), employees(), managers(), faculties(), workplaces(){}

        City::~City()
        {
                for(Employee* employee_ptr : employees)
                {
                        delete employee_ptr;
                } 
                
                for(Manager* manager_ptr : managers)
                {
                        delete manager_ptr;
                }


                for(Faculty<Condition>* faculty_ptr : faculties)
                {
                        delete faculty_ptr;
                }


                
                for(Workplace* workplace_ptr : workplaces)
                {
                        delete workplace_ptr;
                }      
        }



        void  City::addEmployee(const int id, const string& first_name,
                                const string& last_name, const int birth_year)
        {

                if(isIdInVector<Employee>(employees, id) == true)
                {
                        throw CitizenAlreadyExists();
                }
                Employee* employee_ptr = new Employee(id, first_name, last_name, birth_year);
                employees.push_back(employee_ptr);
        }


        void  City::addManager(const int id, const string& first_name,
                                const string& last_name, const int birth_year)
        {

                if(isIdInVector<Manager>(managers, id) == true)
                {
                        throw CitizenAlreadyExists();
                }

                Manager* manager_ptr = new Manager(id, first_name, last_name, birth_year);
                managers.push_back(manager_ptr);

        }




        void City::addFaculty(const int id ,const Skill& skill,
                              int added_points, Condition* condition_ptr)
        {
                if(isIdInVector<Faculty<Condition> >(faculties, id) == true)
                {
                        throw FacultyAlreadyExists();
                }

                Faculty<Condition>* faculty_ptr = 
                                new Faculty<Condition>(id, skill, added_points, condition_ptr);
                faculties.push_back(faculty_ptr);

        }


        void  City::createWorkplace(const int id, const string& name,
                                const int workers_salary, const int managers_salary)
        {

               if(isIdInVector<Workplace>(workplaces, id) == true)
                {
                        throw WorkplaceAlreadyExists();
                }

                Workplace* workplace_ptr = new Workplace(id, name, workers_salary, managers_salary);
                workplaces.push_back(workplace_ptr);
                
        }




        void  City::teachAtFaculty(const int worker_id, const int faculty_id)
        {
   
           Employee* employee_ptr = giveById<Employee, EmployeeDoesNotExist>(
                                                employees, worker_id);
           Faculty<Condition>* faculty_ptr = giveById< Faculty<Condition>, FacultyDoesNotExist >(
                                              faculties, faculty_id);
        
           faculty_ptr->teach(employee_ptr);
        }





        void  City::hireManagerAtWorkplace(const int manager_id, const int workplace_id)
        {
                Manager* manager_ptr = giveById<Manager, ManagerDoesNotExist>(managers, manager_id);
                Workplace* workplace_ptr = giveById<Workplace, WorkplaceDoesNotExist>(
                                                workplaces, workplace_id);

                workplace_ptr->hireManager(manager_ptr);
                 
        }




        void  City::fireEmployeeAtWorkplace(const int worker_id, const int manager_id,
                                        const int workplace_id)
        {
                giveById<Employee, EmployeeDoesNotExist>(employees, worker_id);
                giveById<Manager, ManagerDoesNotExist>(managers, manager_id);

                Workplace* workplace_ptr = giveById<Workplace, WorkplaceDoesNotExist>(
                                               workplaces, workplace_id);

                workplace_ptr->fireEmployee(worker_id, manager_id);
                
        }  
           
        
        
        void  City::fireManagerAtWorkplace(const int manager_id, const int workplace_id)
        {
                Manager* manager_ptr = giveById<Manager, ManagerDoesNotExist>(managers, manager_id); 
                Workplace* workplace_ptr = giveById<Workplace, WorkplaceDoesNotExist>(
                                               workplaces, workplace_id);

                workplace_ptr->fireManager(manager_id);
                manager_ptr->removeAllEmployees();

        }

        
        
        
        
        
        int  City::getAllAboveSalary(ostream& os, const int salary) const
        {
                
            int counter=0;    
            vector<Citizen*> above_salary;

            for(Employee* employee_ptr : employees)
            {
                    if(employee_ptr->getSalary() >= salary)
                    {
                            above_salary.push_back(employee_ptr);
                            counter++;
                    }
            }

          for(Manager* manager_ptr : managers)
            {
                    if(manager_ptr->getSalary() >= salary)
                    {
                            above_salary.push_back(manager_ptr);
                            counter++;
                    }
            }
        
          
          sort(above_salary.begin(), above_salary.end(), compareCitizensFunc);

          for(Citizen* citizen : above_salary)
          {
              citizen->printShort(os);
          }
            return counter;
        }


        

        bool  City::isWorkingInTheSameWorkplace(const int id1, const int id2) const
        {

                Employee* employee1_ptr = giveById<Employee, EmployeeDoesNotExist>(employees, id1);
                Employee* employee2_ptr = giveById<Employee, EmployeeDoesNotExist>(employees, id2);

                for(Workplace* workplace_ptr : workplaces)
                {
                     if(workplace_ptr->hasEmployee(employee1_ptr) &&
                        workplace_ptr->hasEmployee(employee2_ptr))
                     {
                        return true;
                     }   
                }
                return false;
        }

        void  City::printAllEmployeesWithSkill(ostream& os, const int skill_id) const 
        {

             vector<Employee*> new_employees = employees;
             sort(new_employees.begin(), new_employees.end(), compareCitizensFunc);


             for(Employee* employee_ptr : new_employees)
             {
                     if(employee_ptr->hasSkill(skill_id) == true)
                     {
                        employee_ptr->printShort(os);
                     }
             }   
        }








































    
}