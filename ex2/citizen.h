#ifndef __CITIZEN_H__
#define __CITIZEN_H__

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

namespace mtm
{
    class Citizen
    {
        const int id;
        const string first_name;
        const string last_name;
        const  int birth_year;

        public:
        Citizen(const int id,
                const string first_name,
                const string last_name,
                const int birth_year);
        
        Citizen() = delete;
        //Citizen(const Citizen&) = delete;
        virtual ~Citizen(){};

        const int getId() const;
        const string& getFirstName() const;
        const string& getLastName() const;
        const int getBirthYear() const;

        bool operator<(const Citizen& citizen_to_check);
        bool operator>(const Citizen& citizen_to_check);
        bool operator<=(const Citizen& citizen_to_check);
        bool operator>=(const Citizen& citizen_to_check);
        bool operator==(const Citizen& citizen_to_check);
        bool operator!=(const Citizen& citizen_to_check);
        
        virtual ostream& printShort(ostream& os) const;
        virtual ostream& printLong(ostream& os) const;

        virtual Citizen* clone()=0;
        
    };



}

#endif