#include "employee.h"

namespace mtm
{
    Employee::Employee(const int id, const string first_name, 
            const string last_name, const int birth_year,
            int salary=0, int score=0):
            Citizen(id, first_name, last_name, birth_year), 
            salary(salary), score(score), skills()){};
            

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
        

        for(int i = 0; i < skills.size(); i++)
        {
            if((skills[i]).getId() == skill_id)
            {
                skills.erase(skils.begin()+i);
            }
        }

    }


    bool Employee::hasSkill(const int skill_id) const
    {
        for(int i = 0; i < skills.size(); i++)
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
    }

    void Employee::setScore(const int score_to_add)
    {
        score += score_to_add;
    }

    virtual ostream Employee::printShort(ostream os);
    virtual ostream Employee::printLong(ostream os);

    virtual Citizen* Employee::clone();
}