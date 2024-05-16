#include "realvector.h"
#include <stdexcept>
#include <algorithm>

//constructor
template<class T>
RealVector<T>::RealVector() : logical_sz(0), array_sz(kInitialSize){
    elems = new T[kInitialSize];
}

template<class T>
RealVector<T>::RealVector(size_t sz) : logical_sz(sz), array_sz(sz * 2){
    elems = new T[array_sz];
}

template<class T>
RealVector<T>::RealVector(size_t sz, const T &val) : logical_sz(sz), array_sz(sz * 2){
    elems = new T[array_sz];
    std::fill(begin(), end(), val);
}

//destructor
template<class T>
RealVector<T>::~RealVector(){
    delete [] elems;
}

//elem acess
template<class T>
T& RealVector<T>::at(size_t idx){
    if(idx >= logical_sz) {
        throw std::out_of_range("Out of range.");
    }
    return operator[](idx);
}

template<class T>
T& RealVector<T>::operator[](size_t idx){
    return *(begin() + idx);
}

template<class T>
T& RealVector<T>::front(){
    return *begin();
}

template<class T>
T& RealVector<T>::back(){
    return *(end() - 1);
}

//capacity
template<class T>
bool RealVector<T>::empty() const{
    return logical_sz == 0;
}
template<class T>
size_t RealVector<T>::size() const{
    return logical_sz;
}

template<class T>
size_t RealVector<T>::capacity() const{
    return array_sz;
}

//modifiers
template<class T>
void RealVector<T>::clear(){
    logical_sz = 0;
}

template<class T>
void RealVector<T>::insert(size_t idx, const T &val){
    if(idx < 0 || idx >= logical_sz) {
        throw std::out_of_range("Out of range");
    }
    if(logical_sz == array_sz) {
        grow();
    }
    for(int i = logical_sz; i > idx; i--) {
        elems[i] = elems[i - 1];
    }
    elems[idx] = val;
    logical_sz++;
}

template<class T>
void RealVector<T>::emplace_back(const T &val){
    if(logical_sz == array_sz) {
        grow();
    }
    elems[logical_sz++] = val;
}

template<class T>
void RealVector<T>::push_back(const T &val){
    emplace_back(val);
}

template<class T>
void RealVector<T>::pop_back(){
    logical_sz--;
}

//iterators
template<class T>
typename RealVector<T>::iterator RealVector<T>::begin() {
    return elems;
 }

template<class T>
typename RealVector<T>::const_iterator RealVector<T>::begin() const {
    return static_cast<const_iterator>(const_cast<RealVector<T>*>(this)->begin());
 }

template<class T>
typename RealVector<T>::iterator RealVector<T>::end() {
    return elems + logical_sz;
 }

template<class T>
typename RealVector<T>::const_iterator RealVector<T>::end() const {
    return static_cast<const_iterator>(const_cast<RealVector*>(this)->end());
 }

template<class T>
void RealVector<T>::grow() {
    T *newElems = new T[array_sz * 2];
    std::copy(begin(), end(), newElems);
    delete [] elems;
    array_sz *= 2;
    elems = newElems;
 }
