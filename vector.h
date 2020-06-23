#include <cstdio>
template <typename T>
class Vector{
public:
    Vector();
    Vector(size_t size,T value);
    Vector(Vector& v);
    ~Vector();
    Vector& operator=(const Vector& v);
    size_t size() const;

private:
    T* m_vec;
    size_t m_size;
    size_t m_capacity;

};
template <typename T>
Vector::Vector():m_size(0),m_capacity(0),m_vec(NULL){
}
template <typename T>
Vector::Vector(size_t size, T value):m_vec(NULL) ,m_size(size),m_capacity(size) {
    m_vec=new T[m_size];
    for (int i = 0; i <size ; ++i) {
        m_vec[i] = value;
    }
}
template <typename T>
Vector::Vector(Vector &v):m_vec(NULL),m_size(v.size()),m_capacity(v.getCapacity()) {
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
}
template <typename T>
Vector::~Vector() {
    delete [] m_vec;
    m_vec=NULL;
}
template <typename T>
Vector& Vector::operator=(const Vector &v) {

}

