#include "vector.h"

int main()
{
    Vector<int> vector(4, 5);
    for (int i = 0; i <vector.size() ; ++i) {
        std::cout<<vector[i]<<std::endl;
    }
    std::cout<<"start resize: \n";
    vector.resize(6, 7);
    for (int i = 0; i <vector.size() ; ++i) {
        std::cout<<vector[i]<<std::endl;
    }
    std::cout << (vector.back());
    int t = 1;
    vector.insert(3,t);
    std::cout<<"start insert: \n";
    for (int i = 0; i <vector.size() ; ++i) {
        std::cout<<vector[i]<<std::endl;
    }
    std::cout<<"start clear: \n";
    vector.clear();
    std::cout<<vector.empty()<<std::endl;
    std::cout<<"start insert: \n";
    vector.insert(0,t,10);
    for (int i = 0; i <vector.size() ; ++i) {
        std::cout<<vector[i]<<std::endl;
    }
    std::cout<<vector.capacity()<<std::endl;
    std::cout<<"start reserve: \n";
    vector.reserve(40);
    std::cout<<vector.capacity()<<std::endl;
    std::cout<<"start operator []: \n";
    vector[0]=30;
    std::cout<<vector.front()<<std::endl;
    return 1;
}