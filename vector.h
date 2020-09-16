#include <iostream>
#include <limits>
#include <cassert>

template <typename T>
class Vector {

public:

    class iterator{

    public:
        iterator(T* ptr):m_ptr(ptr){}
        iterator operator++()
        {
            iterator i =*this;
            m_ptr++;
            return i;
        }
        iterator operator++(int of){m_ptr++;
            return *this;}
            T& operator*(){ return *m_ptr;}
            bool operator==(iterator& other){return *m_ptr==other.m_ptr;}
            bool operator!=(iterator& other){return *m_ptr!=other.m_ptr;}
    private:

        T* m_ptr;
    };

    explicit Vector();
    explicit Vector(size_t n,  const T &val=T());
    ~Vector();
    Vector(const Vector& x);

    Vector&     operator= (const Vector& x);
    size_t      size() const;
    size_t      capacity() const;
    size_t      max_size() const;
    bool        empty() const;
    void        resize(size_t n, T val = T());
    void        reserve(T n);
    T&          operator[] (size_t n);
    const T&    operator[] (size_t n) const;
    void        assign(size_t n, const T& val);
    T&          at(size_t n);
    const T&    at(size_t n) const;
    T&          front();
    const T&    front() const;
    T&          back();
    const T&    back() const;
    T*          data();
    const T*    data() const;
    void        push_back(T& val);
    void        pop_back();
    void        insert(size_t position,T& val,size_t n=1);
    void        erase(T* position);
    void        clear();
    void        swap (Vector & other);
    iterator    begin()
    {
        return iterator(ptr);
    }
    iterator    end()
    {
        return ptr+m_size;
    }

private:
    T*      ptr;
    size_t  m_size;
    size_t  m_capacity;
};

template <typename T>
Vector<T>::Vector() :ptr(NULL), m_size(0), m_capacity(0) {}

template <typename T>
Vector<T>::Vector(size_t n,const T &val) : ptr(NULL),m_size(n),m_capacity(n)
{
    size_t i;
    ptr = new T[n];
    for (i = 0; i < n; i++)
    {
        ptr[i] = val;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& x) :ptr(NULL),m_size(x.size()),m_capacity(x.capacity())
{
    int i;
    ptr = new T[x.m_size];
    for (i = 0; i < size(); i++)
    {
        ptr[i] = x.ptr[i];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] ptr;
    ptr = NULL;
}

template <typename T>
size_t Vector<T>::size() const
{
    return m_size;
}

template <typename T>
size_t Vector<T>::max_size() const
{
    return std::numeric_limits<size_t>::max();
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector& x)
{
    size_t i;
    T* tmp = new T[x.m_size];
    delete[] ptr;
    ptr = tmp;
    m_size = x.m_size;
    m_capacity = m_size;
    for (i = 0; i < m_size; i++)
    {
        ptr[i] = x.ptr[i];
    }
}

template <typename T>
void Vector<T>::resize(size_t n, T val)
{
    if (n == 0)
    {
        delete[] ptr;
        ptr = NULL;
        m_size = 0;
        m_capacity = 0;
    }
    size_t i;
    if (n < m_size)
    {
        for (i = n; i < m_size; i++)
            delete(ptr + i);
        m_size = n;
        m_capacity = n;
    }
    else
    {
        if (n < m_capacity)
        {
            for (i = m_size; i < n; i++)
            {
                ptr[i] = val;
                m_size += n;
            }
        }
        else  // realloc vector
        {
            T* tmp;
            if (n < m_capacity * 2) {
                tmp = new T[m_capacity * 2];
                m_capacity *= 2;
            }
            else {
                tmp = new T[n];
                m_capacity = n;
            }
            for (i = 0; i < m_size; i++)
            {
                tmp[i] = ptr[i];
            }
            ptr = tmp;
            for (i = m_size; i < n; i++)
                ptr[i] = val;
            for (i = n; i < m_capacity; i++)
                ptr[i] = 0;
            m_size = n;
        }
    }
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void Vector<T>::reserve(T n)
{
    size_t i;
    if (n < m_capacity)
        return;
    size_t size = n < m_capacity * 2 ? m_capacity * 2 : n;
    T* tmp = new T[size];
    for (i = 0; i < m_size; i++)
    {
        tmp[i] = ptr[i];
    }
    ptr = tmp;
    m_capacity = size;
}

template <typename T>
T& Vector<T>::operator[] (size_t n)
{
    return ptr[n];
}

template <typename T>
const T& Vector<T>::operator[] (size_t n) const
{
    return ptr[n];
}

template <typename T>
T& Vector<T>::at(size_t n)
{
    if (n > m_capacity)
        throw std::out_of_range("not able to access");
    return ptr[n];
}

template <typename T>
const T& Vector<T>::at(size_t n) const
{
    if (n > m_capacity)
        throw std::out_of_range("not able to access");
    return ptr[n];
}

template <typename T>
T& Vector<T>::front()
{
    return ptr[0];
}

template <typename T>
const T& Vector<T>::front() const
{
    return ptr[0];
}

template <typename T>
T& Vector<T>::back()
{
    return ptr[m_size - 1];
}

template <typename T>
const T& Vector<T>::back() const
{
    return ptr[m_size - 1];
}

template <typename T>
T* Vector<T>::data()
{
    return ptr;
}

template <typename T>
const T* Vector<T>::data() const
{
    return ptr;
}

template <typename T>
void Vector<T>::assign(size_t n, const T& val)
{
    int i;
    if(n<m_size){
        i=n;
    }
    else{
        int i = n-m_size;
        resize(n,val);
    }
    for (int j = 0; j < i; ++j) {
        ptr[j]=val;
    }
}
template <typename T>
void Vector<T>::push_back(T &val) {
    if(m_size+1>m_capacity){
        reserve(m_capacity+1);
    }
    ptr[m_size+1]=val;
    m_size=m_size+1;
}
template <typename T>
void Vector<T>::pop_back() {
    ptr[m_size].~T();
    m_size-=1;

}
template <typename T>
void Vector<T>::insert(size_t position, T &val, size_t n) {
    if(m_size+n>m_capacity){
        reserve(m_size+n);
    }
    for (int i = m_size; i > position; --i) {
        ptr[i+n]=ptr[i];
    }
    for (int j = position; j < position+n; ++j) {
        ptr[j]=val;
    }
    m_size+=n;
}
template <typename T>
void Vector<T>::clear() {
    for (int i = m_size; i >0; --i) {
        pop_back();
    }
    m_size=0;
}
template <typename T>
void Vector<T>::erase(T *position) {
    position.~T();
    for (int i = position+1; i < ptr+m_size ; ++i) {
        ptr[i]=ptr[i]-1;
    }
    m_size--;
}
template <typename T>
void Vector<T>::swap(Vector &other) {
  Vector tmp(*this);
  *this = other;
  other = tmp;
}
//template <typename T>
//Vector<T>::iterator Vector<T>::iterator::operator++() {
//    iterator i =*this;
//    m_ptr++;
//    return i;
//}
//Vector<T>::iterator::operator++() {
//    iterator i =*this;
//    m_ptr++;
//    return i;
//}