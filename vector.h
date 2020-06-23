#include <cstdio>
#include <cmath>
template <typename T>
class Vector{
public:
    Vector();
    Vector(size_t size,T value);
    Vector(Vector& v);
    ~Vector();
    Vector& operator=(const Vector& v);
    size_t size() const;
    size_t max_size() const;
    size_t capacity() const;

private:
    Vector& init(Vector & v,size_t size);
    T* m_vec;
    size_t m_size;
    size_t m_capacity;

};
template <typename T>
Vector<T>::Vector():m_size(0),m_capacity(0),m_vec(NULL){
}
template <typename T>
Vector<T>::Vector(size_t size, T value):m_vec(NULL) ,m_size(size),m_capacity(size) {
    m_vec=new T[m_size];
    for (int i = 0; i <size ; ++i) {
        m_vec[i] = value;
    }
}
template <typename T>
Vector<T>& Vector<T>::init(Vector<T> &v, size_t size) {
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
}
template <typename T>
Vector<T>::Vector(Vector<T> &v):m_vec(NULL),m_size(v.size()),m_capacity(v.capacity()) {
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
}
template <typename T>
Vector<T>::~Vector() {
    delete [] m_vec;
    m_vec=NULL;
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v) {
    m_capacity=v.capacity();
    m_size=v.size();
    T* orig = m_vec;
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
    delete orig;
    return *this;
}

template <typename T>
size_t Vector<T>::size() const {
    return m_size;
}
template <typename T>
size_t Vector<T>::max_size() const {
    return (pow(2, sizeof(T)))-1;
}
template <typename T>
size_t Vector<T>::capacity() const {
    return m_capacity;
}

