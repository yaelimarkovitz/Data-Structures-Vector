#include "vector.h"

int main()
{
    Vector<int> vector(4, 5);
    vector.resize(6, 7);
    std::cout << (vector.back());
    return 1;
}