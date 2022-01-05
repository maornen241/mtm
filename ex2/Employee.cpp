#include "Employee.h"
#include "Citizen.h"
using std::ostream;
using std::cout;
using std::endl;

namespace mtm
{
    Employee::Employee(const int id, const string first_name, 
            const string last_name, const int birth_year,
            int salary, int score):
            Citizen(id, first_name, last_name, birth_year), 
            salary(salary), score(score), skills(){}
            

    int Employee::getSalary() const
    {
        return (this->salary);
    }
    int Employee::getScore() const
    {
        return (this->score);
    }

    void Employee::learnSkill(const Skill skill)
    {
        if(hasSkill(skill.getId()) == true)
        {
            throw SkillAlreadyLearned(); 
        }

        if(getScore() < skill.getRequiredPoints())
        {
            throw CanNotLearnSkill();
        }

        skills.push_back(skill);

    }
    void Employee::forgetSkill(const int skill_id)
    {
        if(hasSkill(skill_id) == false)
        {
            throw DidNotLearnSkill(); 
        }
        

        for(unsigned int i = 0; i < skills.size(); i++)
        {
            if((skills[i]).getId() == skill_id)
            {
                skills.erase(skills.begin()+i);
            }
        }

    }


    bool Employee::hasSkill(const int skill_id) const
    {
        for(unsigned int i = 0; i < skills.size(); i++)
        {
            if((skills[i]).getId() == skill_id)
            {
                return true;
            }
        }
        return false;
    }

    void Employee::setSalary(const int raise)
    {
        salary += raise;
        if ( salary < 0 )
        {
            salary = 0;
        }
    }

    void Employee::setScore(const int score_to_add)
    {
        score += score_to_add;
        if(score < 0 )
        {
            score = 0;
        }
    }

    ostream& Employee::printShort(ostream& os) const
    {
        os<<getFirstName()<<" "<<getLastName()<<endl;
        os<<"Salary: "<<salary<<" "<<"Score: "<<score<<endl;
        return os;
    }
    ostream& Employee::printLong(ostream& os) const
    {
        os<<getFirstName()<<" "<<getLastName()<<endl;

        os<<"id - "<<getId()<<" "<<"birth_year - "<<getBirthYear()<<endl;
        os<<"Salary: "<<salary<<" "<<"Score: "<<score<<" "<<"Skills:"<<endl;
        
        for(unsigned int i = 0; i< skills.size(); i++)
        {
            os<<skills[i]<<endl;
        }

        return os;   
    }

    Citizen* Employee::clone()
    {
        return new Employee(*this);
    }
}