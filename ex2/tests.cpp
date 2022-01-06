// #include "Skill.h"
// #include "Citizen.h"
// #include "Employee.h"
// #include "exceptions.h"
// #include <iostream>
// #include "Manager.h"
// #include "Workplace.h"
// #include "Faculty.h"
// #include <typeinfo>

// using std::cout;
// using std::endl;
// using std::type_info;
// using std::string;

// using namespace mtm;

// class HiringCondition
// {
//     public:
//         bool operator()(Employee* emp)
//         { 
//             return (emp->getScore() > 10);
//         }
// };

// class FacultyCondition3{
//     public:
//         bool operator()(Employee* employee){
//             return employee->getId() > 0;
//     }
// };

// class FacultyCondition4{
//     public:
//         bool operator()(Employee* employee){
//             return employee->getId() > 3;
//     }
// };


// bool test_skill();
// bool test_employee();
// bool test_manager();
// bool test_workplace();
// bool test_faculty();



// int main()
// {
//     if(test_skill() && test_employee() && test_manager() &&
//         test_workplace()  && test_faculty())
//     {
//         cout<<"All good"<<endl;
//     }
//     else
//     {
//         cout<<"Shit!!"<<endl;
//     }
//     return 0;

// }

// bool test_skill()
// {
//     string s = "C++";
//     Skill skill1(4, s, 12);

//     if(skill1.getId() != 4)
//     {
//         return false;
//     }
//     if(skill1.getName() != s)
//     {
//         return false;
//     }
//     if(skill1.getRequiredPoints() != 12)
//     {
//         return false;
//     }

//     Skill skill2(10, "Python", 2);
    
//     if(skill1 > skill2 || skill1 >= skill2 || skill1 == skill2 
//        || skill2 < skill1 || skill2 <= skill1 || !(skill2 != skill1))
//         {
//             return false;
//         } 

//     Skill skill3 = skill2++;
//     if(skill3.getRequiredPoints() == skill2.getRequiredPoints())
//     {
//         return false;
//     }

//     if(skill2.getRequiredPoints() != 3)
//     {
//         return false;
//     }

//     try{
//         skill1 += 2;
//         if(skill1.getRequiredPoints() != 14)
//         {
//             return false;
//         }
//     }
//         catch(NegativePoints& e)
//         {   
//             cout<<"Negative points in +="<<endl;
//             return false;
//         }
//         catch(Exceptions& e)
//         {
//             cout<<"skill exception in +="<<endl;
//             return false;
//         }
//         catch(std::exception& e)
//         {
//             cout<<e.what()<<endl;
//             return false;
//         }

//     try{
//         2+skill1;
//         if(skill1.getRequiredPoints() != 16)
//         {
//             return false;
//         }

//         skill1+3;
//         if(skill1.getRequiredPoints() != 19)
//         {
//             return false;
//         }

//     }
//         catch(NegativePoints& e)
//         {   
//             cout<<"Negative points in +"<<endl;
//             return false;
//         }
//         catch(Exceptions& e)
//         {
//             cout<<"skill exception in +"<<endl;
//             return false;
//         }
//         catch(std::exception& e)
//         {
//             cout<<e.what()<<endl;
//             return false;
//         }

//          cout<<skill1<<endl;


//     return true;
    

// }

// bool test_employee()
// {
//     Employee maor(1,"maor","ben eli",1991);
//     Skill cpp(1,"C++",2);
//     maor.setScore(100);
//     maor.setSalary(8000);
//     maor.learnSkill(cpp);

//     Skill python(2,"Python",12);
//     maor.learnSkill(python);
//     Skill too_hard(3,"too_hard",1000);
//     if(maor.hasSkill(1) == false || maor.hasSkill(2) == false)
//     {
//         return false;
//     } 
    
//     try{
//         maor.learnSkill(too_hard);
//     }
//     catch(CanNotLearnSkill e1)
//     {
//         ///cout<<"CanNotLearnSkill"<<endl;
//     }

//     try{
//         maor.learnSkill(cpp);
//     }
//     catch(SkillAlreadyLearned e2)
//     {
//        // cout<< "SkillAlreadyLearned"<<endl;
//     }

//     try{
//         maor.forgetSkill(3);
//     }
//     catch(DidNotLearnSkill e3)
//     {
//         //cout<<"DidNotLearnSkill"<<endl;
//     }


//     Citizen* maor2_ptr = maor.clone();
//     maor.forgetSkill(2);
//     //(*maor2_ptr).printLong(cout);
//     //(*maor2_ptr).printShort(cout);
//     //maor.printLong(cout);
//     delete maor2_ptr;

//     return true;                
            
// }

// bool test_manager()
// {
//     Employee maor(1,"maor","ben eli",1991);
//     Skill cpp(1,"C++",2);
//     maor.setScore(100);
//     maor.setSalary(8000);
//     maor.learnSkill(cpp);
//     Skill python(2,"Python",12);
//     maor.learnSkill(python);

//     Employee yonez(3,"ma?", "yonez!",1876);
//     yonez.setScore(1000);
//     yonez.setSalary(1);
//     Skill football(3,"football",10);
//     yonez.learnSkill(football);
//     yonez.learnSkill(cpp);
//     yonez.learnSkill(python);

//     Manager steve(42, "Steve","Jobs", 1955, 100000);
//     steve.addEmployee(&yonez);
//     steve.addEmployee(&maor);
//     steve.removeEmployee(3);
//     try
//     {
//         steve.removeEmployee(-2);
//     }
//     catch(const EmployeeNotHired& e)
//     {
//         cout<<"good catch!"<<"\n"<<endl;
//     }
//     steve.addEmployee(&yonez);

//     try
//     {
//         steve.addEmployee(&yonez);
//     }
//     catch(EmployeeAlreadyHired e)
//     {
//         cout<<"another good catch!"<<"\n"<<endl;
//     }

//     Employee ari(4,"ari", "ben eli", 2021);
//     ari.setScore(1700);
//     ari.setSalary(2000);
//     ari.learnSkill(football);
//     ari.learnSkill(python);

//     Manager bill(95, "bill", "gates", 1955);
//     bill.setSalary(220000);
//     bill.addEmployee(&ari);
//     bill.addEmployee(&maor);
//     bill.removeEmployee(1);

//     Citizen* steve2_ptr =  steve.clone();
//     steve2_ptr->printLong(cout);
//     cout<<endl;

//     maor.printShort(cout);
//     cout<<endl;
//     ari.printShort(cout);
//     cout<<endl;

//     bill.printShort(cout);
//     cout<<endl;
//     steve.removeEmployee(1);
//     steve.printLong(cout);
//     cout<<endl;

//     delete steve2_ptr;
//     return true;
    
// }   
    
// bool test_workplace()
// {
//     Skill python(2,"Python",12);
//     Skill cpp(1,"C++",2);
//     Skill football(3,"football",10);

//     Employee maor(1,"maor","ben eli",1991);
//     maor.setScore(100);
//     maor.setSalary(8000);
//     maor.learnSkill(cpp);
//     maor.learnSkill(python);

//     Employee yonez(3,"ma?", "yonez!",1876);
//     yonez.setScore(1000);
//     yonez.setSalary(1);
//     yonez.learnSkill(football);
//     yonez.learnSkill(cpp);
//     yonez.learnSkill(python);

    
//     Employee ari(4,"ari", "ben eli", 2021);
//     ari.setScore(1700);
//     ari.setSalary(2000);
//     ari.learnSkill(football);
//     ari.learnSkill(python);

//     Manager steve(42, "Steve","Jobs", 1955);
//     steve.addEmployee(&yonez);


//     Manager bill(95, "bill", "gates", 1955);
//     bill.addEmployee(&ari);

//     Workplace Meta(1, "Meta", 1000, 20000);
//     Meta.hireManager(&steve);
//     Meta.hireManager(&bill);

//     HiringCondition hiring_condition;

//     try
//     {
//         Meta.hireEmployee(hiring_condition, &maor, 95);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }

//     Employee bad_employee(12, "Bad", "Employee", 1999);
//     bad_employee.setScore(3);

//     try
//     {
//         Meta.hireEmployee(hiring_condition, &bad_employee, 95);
//     }
//     catch(EmployeeNotSelected e)
//     {
//         cout<<"catch 1"<<endl;
//     }

//     bad_employee.setScore(10000);
//     try
//     {
//         Meta.hireEmployee(hiring_condition, &bad_employee, -12);
//     }
//     catch(ManagerIsNotHired e)
//     {
//         cout<<"catch 2"<<endl;
//     }

//     try
//     {
//         Meta.hireEmployee(hiring_condition, &maor, 42);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }

//     try
//     {
//         Meta.hireEmployee(hiring_condition, &maor, 42);
//     }
//     catch(EmployeeAlreadyHired e)
//     {
//         cout<<"catch 3"<<endl;
//     }

//     try
//     {
//         Meta.fireEmployee(1, -1);
//     }
//     catch(ManagerIsNotHired e)
//     {
//         cout<<"catch 4"<<endl;
//     }

//     try
//     {
//         Meta.fireEmployee(-3, 42);
//     }
//     catch(EmployeeNotHired e)
//     {
//         cout<<"catch 5"<<endl;
//     }

//     try
//     {
//         Meta.fireEmployee(3, 42);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }

//     try
//     {
//         Meta.fireManager(-12);
//     }
//     catch(ManagerIsNotHired e)
//     {
//         cout<<"catch 6"<<endl;
//     }

//     cout<<Meta<<endl;

//     try
//     {
//         Meta.fireManager(95);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }

//     cout<<Meta<<endl;

//     try
//     {
//         Meta.fireManager(42);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }
//     cout<<Meta<<endl;

//     return true;
    

// }

// bool test_faculty()
// {
//     Skill python(2,"Python",12);
//     Skill cpp(1,"C++",2);

//     FacultyCondition3 fc1;
//     FacultyCondition4 fc2;

//     Faculty<FacultyCondition3> py_faculty(1, &fc1, python, 10);
//     Faculty<FacultyCondition4> cpp_faculty(2, &fc2, cpp, 10000);

//     Employee maor(1,"maor","ben eli",1991);
//     maor.setScore(100);
//     maor.setSalary(8000);

//     try
//     {
//         py_faculty.teach(&maor);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }
    
//     try
//     {
//         py_faculty.teach(&maor);
//     }
//     catch(std::exception e)
//     {
//         return false;
//     }

//     try
//     {
//         cpp_faculty.teach(&maor);
//     }
//     catch(EmployeeNotAccepted e)
//     {
//         cout<<"catch 7"<<endl;
//     }
//     catch(std::exception e)
//     {
//         cout<<"oh no!"<<endl;
//     }

//     maor.printLong(cout);
//     return true;



// }