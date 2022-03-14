// #include <iostream>
// #include <vector>

// using std::vector;
// using std::cout;
// using std::endl;
// using std::flush;

// class Exceptions : public std::exception{};
// class BadInput : public Exceptions{};


// template <class T>
// std::vector<T> slice(std::vector<T> vec,int start,int step,int stop)
// {
//     if(start < 0 || start >= vec.size() ||
//          stop < 0 || stop > vec.size() ||
//          step <= 0)
//     {
//         throw BadInput();
//     }

//     vector<T> new_vec;

//     for(typename vector<T>::iterator it = (vec.begin()+start);
//          it < vec.begin()+stop ; it += step)
//     {
//         new_vec.push_back(*it);
//     }
//     return new_vec;
// }

// int main()
// {
//     vector<int> int_vec {1,2,3,4,5};
//     vector<char> char_vec {'a', 'b', 'c', 'd', 'e'};

//     vector<char> result1 = slice(char_vec, 0, 2, 4);
//     for(char elm : result1)
//     {
//         cout<< elm <<", "<<flush;
//     }
//     cout<<endl;
//     cout<<"finish 1"<<endl;

//     vector<char> result2 =  slice(char_vec, 1, 1, 5);
//     for(char elm : result2)
//     {
//         cout<< elm <<", "<<flush;
//     }
//     cout<<endl;
//     cout<<"finish 2"<<endl;

//     vector<char> result3 =  slice(char_vec, 4, 1, 1);
//     for(char elm : result3)
//     {
//         cout<< elm << ", "<<flush;
//     }
//     cout<<endl;
//     cout<<"finish 3"<<endl;

//     vector<int> result4 =  slice(int_vec, 1, 1, 4);
//     for(int elm : result4)
//     {
//         cout<< elm<< ", " << flush;
//     }
//     cout<<endl;
//     cout<<"finish 4"<<endl;

//     return 0;


// }