#ifndef RealVector_H
#define RealVector_H

#include <string>
#include <algorithm>
#include <stdexcept>

template<class T> class RealVector {
public:
    using iterator = T*;
    using const_iterator = const T*;

    const int kInitialSize = 2; 
    //constructors
    RealVector();
    RealVector(size_t);
    RealVector(size_t n, const T &val);
    //destructor
    ~RealVector();

    //elem acess
    T& at(size_t idx);
    T& operator[] (size_t idx);
    T& front();
    T& back();

    //capacity
    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    //modifiers
    void clear();
    void insert(size_t idx, const T &val);
    void emplace_back(const T &val);
    void push_back(const T &val);
    void pop_back();

    //iterators
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    
private:
    void grow();
    T *elems;//pointer of first elem
    size_t logical_sz;//elems of arrays
    size_t array_sz; //capacity of arrays
};

// Important: For template classes, include the .cpp at the bottom of the .h instead of including the .h in the top of the .cpp
#include "realvector.cpp"

#endif // RealVector_H
