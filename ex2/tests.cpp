#include "skill.h"
#include "citizen.h"
#include "employee.h"
#include "exceptions.h"
#include <iostream>
#include "manager.h"

using std::cout;
using std::endl;

using namespace mtm;

bool test_skill();
bool test_employee();
bool test_manager();

int main()
{
    if(test_skill() && test_employee() && test_manager())
    {
        cout<<"All good"<<endl;
    }
    else
    {
        cout<<"Shit!!"<<endl;
    }
    return 0;

}

bool test_skill()
{
    string s = "C++";
    Skill skill1(4, s, 12);

    if(skill1.getId() != 4)
    {
        return false;
    }
    if(skill1.getName() != s)
    {
        return false;
    }
    if(skill1.getRequiredPoints() != 12)
    {
        return false;
    }

    Skill skill2(10, "Python", 2);
    
    if(skill1 > skill2 || skill1 >= skill2 || skill1 == skill2 
       || skill2 < skill1 || skill2 <= skill1 || !(skill2 != skill1))
        {
            return false;
        } 

    Skill skill3 = skill2++;
    if(skill3.getRequiredPoints() == skill2.getRequiredPoints())
    {
        return false;
    }

    if(skill2.getRequiredPoints() != 3)
    {
        return false;
    }

    try{
        skill1 += 2;
        if(skill1.getRequiredPoints() != 14)
        {
            return false;
        }
    }
        catch(NegativePoints& e)
        {   
            cout<<"Negative points in +="<<endl;
            return false;
        }
        catch(Exceptions& e)
        {
            cout<<"skill exception in +="<<endl;
            return false;
        }
        catch(std::exception& e)
        {
            cout<<e.what()<<endl;
            return false;
        }

    try{
        2+skill1;
        if(skill1.getRequiredPoints() != 16)
        {
            return false;
        }

        skill1+3;
        if(skill1.getRequiredPoints() != 19)
        {
            return false;
        }

    }
        catch(NegativePoints& e)
        {   
            cout<<"Negative points in +"<<endl;
            return false;
        }
        catch(Exceptions& e)
        {
            cout<<"skill exception in +"<<endl;
            return false;
        }
        catch(std::exception& e)
        {
            cout<<e.what()<<endl;
            return false;
        }

         cout<<skill1<<endl;


    return true;
    

}

bool test_employee()
{
    Employee maor(1,"maor","ben eli",1991);
    Skill cpp(1,"C++",2);
    maor.setScore(100);
    maor.setSalary(8000);
    maor.learnSkill(cpp);

    Skill python(2,"Python",12);
    maor.learnSkill(python);
    Skill too_hard(3,"too_hard",1000);
    if(maor.hasSkill(1) == false || maor.hasSkill(2) == false)
    {
        return false;
    } 
    
    try{
        maor.learnSkill(too_hard);
    }
    catch(CanNotLearnSkill e1)
    {
        ///cout<<"CanNotLearnSkill"<<endl;
    }

    try{
        maor.learnSkill(cpp);
    }
    catch(SkillAlreadyLearned e2)
    {
       // cout<< "SkillAlreadyLearned"<<endl;
    }

    try{
        maor.forgetSkill(3);
    }
    catch(DidNotLearnSkill e3)
    {
        //cout<<"DidNotLearnSkill"<<endl;
    }


    Citizen* maor2_ptr = maor.clone();
    maor.forgetSkill(2);
    //(*maor2_ptr).printLong(cout);
    //(*maor2_ptr).printShort(cout);
    //maor.printLong(cout);
    delete maor2_ptr;

    return true;                
            
}

bool test_manager()
{
    Employee maor(1,"maor","ben eli",1991);
    Skill cpp(1,"C++",2);
    maor.setScore(100);
    maor.setSalary(8000);
    maor.learnSkill(cpp);
    Skill python(2,"Python",12);
    maor.learnSkill(python);

    Employee yonez(3,"ma?", "yonez!",1876);
    yonez.setScore(1000);
    yonez.setSalary(1);
    Skill football(3,"football",10);
    yonez.learnSkill(football);
    yonez.learnSkill(cpp);
    yonez.learnSkill(python);

    Manager steve(42, "Steve","Jobs", 1955, 100000);
    steve.addEmployee(&yonez);
    steve.addEmployee(&maor);
    steve.removeEmployee(3);
    try
    {
        steve.removeEmployee(-2);
    }
    catch(const EmployeeNotHired& e)
    {
        cout<<"good catch!"<<"\n"<<endl;
    }
    steve.addEmployee(&yonez);

    try
    {
        steve.addEmployee(&yonez);
    }
    catch(EmployeeAlreadyHired e)
    {
        cout<<"another good catch!"<<"\n"<<endl;
    }

    Employee ari(4,"ari", "ben eli", 2021);
    ari.setScore(1700);
    ari.setSalary(2000);
    ari.learnSkill(football);
    ari.learnSkill(python);

    Manager bill(95, "bill", "gates", 1955);
    bill.setSalary(220000);
    bill.addEmployee(&ari);
    bill.addEmployee(&maor);
    bill.removeEmployee(1);

    Citizen* steve2_ptr =  steve.clone();
    steve2_ptr->printLong(cout);
    cout<<endl;

    maor.printShort(cout);
    cout<<endl;
    ari.printShort(cout);
    cout<<endl;

    bill.printShort(cout);
    cout<<endl;
    steve.removeEmployee(1);
    steve.printLong(cout);
    cout<<endl;

    delete steve2_ptr;
    return true;



    
}   
    