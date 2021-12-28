#include "citizen.h"

namespace mtm 
{

    Citizen::Citizen(const  int id,
            const string first_name,
            const string last_name,
            const  int birth_year):
            id(id), first_name(first_name),
            last_name(last_name), birth_year(birth_year){};

    
    

    const int Citizen::getId() const
    {
        return (this->id);
    }
    const string& Citizen::getFirstName() const
    {
        return (this->first_name);
    }
    const string& Citizen::getLastName() const
    {
        return (this->last_name);
    }
    const  int Citizen::getBirthYear() const
    {
        return (this->birth_year);        
    }


    bool Citizen::operator<(const Citizen& citizen_to_check)
    {
        return ((this->id) < citizen_to_check.id);
    }
    bool Citizen::operator>(const Citizen& citizen_to_check)
    {
        return ((this->id) > citizen_to_check.id);
    }
    bool Citizen::operator<=(const Citizen& citizen_to_check)
    {
        return ((this->id) <= citizen_to_check.id);
    }
    bool Citizen::operator>=(const Citizen& citizen_to_check)
    {
       return ((this->id) >= citizen_to_check.id); 
    }
    bool Citizen::operator==(const Citizen& citizen_to_check)
    {
        return ((this->id) == citizen_to_check.id);
    }
    bool Citizen::operator!=(const Citizen& citizen_to_check)
    {
        return ((this->id) != citizen_to_check.id);
    }


}

