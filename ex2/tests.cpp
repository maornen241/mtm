#include "skill.h"
#include "citizen.h"
#include "employee.h"
#include <iostream>

using std::cout;
using std::endl;

using namespace mtm;

bool test_skill();
bool test_employee();

int main()
{
    if(test_skill() && test_employee())
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
        catch(Skill::NegativePoints& e)
        {   
            cout<<"Negative points in +="<<endl;
            return false;
        }
        catch(Skill::Exceptions& e)
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
        catch(Skill::NegativePoints& e)
        {   
            cout<<"Negative points in +"<<endl;
            return false;
        }
        catch(Skill::Exceptions& e)
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
    catch(Employee::CanNotLearnSkill e1)
    {
        cout<<"CanNotLearnSkill"<<endl;
    }

    try{
        maor.learnSkill(cpp);
    }
    catch(Employee::SkillAlreadyLearned e2)
    {
        cout<< "SkillAlreadyLearned"<<endl;
    }

    try{
        maor.forgetSkill(3);
    }
    catch(Employee::DidNotLearnSkill e3)
    {
        cout<<"DidNotLearnSkill"<<endl;
    }


    Citizen* maor2_ptr = maor.clone();
    maor.forgetSkill(2);
    (*maor2_ptr).printLong(cout);
    (*maor2_ptr).printShort(cout);
    maor.printLong(cout);

    return true;                
            
}