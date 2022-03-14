#include <iostream>
#include <vector>
#include <memory>

using std::vector;
using std::cout;
using std::endl;
using std::flush;

class Exceptions : public std::exception{};
class BadInput : public Exceptions{};


template <class T>
std::vector<T> slice(std::vector<T> vec,int start,int step,int stop)
{
    if(start < 0 || start >= vec.size() ||
         stop < 0 || stop > vec.size() ||
         step <= 0)
    {
        throw BadInput();
    }

    vector<T> new_vec;

    for(typename vector<T>::iterator it = (vec.begin()+start);
         it < vec.begin()+stop ; it += step)
    {
        new_vec.push_back(*it);
    }
    return new_vec;
}

using  std::shared_ptr;

class A {
public:
    std::vector< shared_ptr<int> > values;
    void add(int x) {
         shared_ptr<int> ptr( new int(x) );
         values.push_back(ptr);
         }

    ~A() = default;
};


int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}


