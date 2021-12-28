#include "skill.h"
#include "citizen.h"
#include "employee.h"

using namespace mtm;

bool test_skill();

int main()
{
    if(test_skill() == true)
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