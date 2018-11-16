//
//  myVector.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-10-31.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myVector_h
#define myVector_h

#include <initializer_list>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "common.h"

template <class T>
class MyVector {
    T *_array = nullptr;
    int _cap = 0;
    int _index = -1;
public:
    ~MyVector() {
//        for (int i = 0; i < _cap; ++i) {
//            delete _array[i];
//        }
        if (_array != nullptr) {
            delete[] _array;
            _array = nullptr;
        }
    }
    MyVector() { // basic constructor
        std::cout << "Basic constructor called" << std::endl;
    }
    explicit MyVector(int numSize, int value) {
        std::cout << "Constructor with numSize and value" << std::endl;
        reSize(_array, _cap, numSize);
        for (int i = 0; i < numSize; ++i) {
            _array[i] = value;
        }
        _index = numSize - 1;
    }
    explicit MyVector(std::initializer_list<T> il) { // constructor with initializer_list
        std::cout << "Constructor with initializer_list called" << std::endl;
        size_t listSize = il.size();
        reSize(_array, _cap, (int)listSize); // why does reSize(_array, _cap, _cap*2) work?
        for (size_t i = 0; i < listSize; ++i) {
            _array[i] = il.begin()[i];
        }
        _index = (int)listSize - 1;
    }
    MyVector(const MyVector& vec) { // copy constructor
        std::cout << "Copy constructor called" << std::endl;
        _cap = vec._cap;
        _index = vec._index;
        reSize(_array, this->_cap, this->_cap);
        for (int i = 0; i < this->_cap; ++i) {
            _array[i] = vec._array[i];
        }
    }
    MyVector& operator=(const MyVector& other) { // copy assignment operator
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            reSize(_array, _cap, other._cap);
            for (int i = 0; i < other._cap; ++i) {
                _array[i] = other._array[i];
            }
            _index = other._index;
        }
        return *this;
    }
    MyVector(MyVector&& other) { // move constructor
        std::cout << "Move constructor called" << std::endl;
        _array = other._array;
        _cap = other._cap;
        _index = other._index;
        other._array = nullptr;
        other._cap = 0;
        other._index = -1;
    }
    MyVector& operator=(MyVector&& other) { // move assignment operator
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            delete[] _array;
            _array = other._array;
            _cap = other._cap;
            _index = other._index;
            other._array = nullptr;
            other._cap = 0;
            other._index = -1;
        }
        return *this;
    }
    class Iterator {
        T* t;
        int endPos;
        int curPos;
    public:
        explicit Iterator(T* t, int endPos, int curPos): t{t}, endPos{endPos}, curPos{curPos} {}
        T& operator*() const {
            return t[curPos];
        }
        Iterator& operator++() {
            if (curPos < endPos) {
                ++curPos;
            }
            return *this;
        }
        Iterator& operator++(int) {
            return ++(*this);
        }
        bool operator==(const Iterator& other) {
            return curPos == other.curPos;
        }
        bool operator!=(const Iterator& other) {
            return !(*this==other); // invoke operator==
        }
        Iterator operator+(int num) {
            if (curPos + num > -1 && curPos + num < endPos) {
                return Iterator{t, endPos, curPos + num};
            } else {
                return Iterator{t, endPos, endPos}; // same as Iterator end(). which means out_of_range
            }
        }
        Iterator operator-(int num) {
            num *= -1;
            return (*this)+num; // invoke operator+
        }
    };
    Iterator begin() {
        return Iterator{_array, _index+1, 0};
    }
    Iterator end() {
        return Iterator{_array, _index+1, _index+1};
    }
    
    
    void push_back(const T& elem) {
        ++_index;
        if (_cap == _index) {
            reSize(_array, _cap, std::max(1, _cap*2)); // if _cap == 0, newSize needs to be 1
        }
        _array[_index] = elem;
    }
    bool empty() {
        return _index == -1;
    }
    T& operator[] (const int& ind) {
        return _array[ind];
    }
    T& at(int ind) {
        if (ind > _index || ind < 0) {
            throw std::out_of_range("out of range");
        } else {
            return _array[ind];
        }
    }
    T& front() {
        return _array[0];
    }
    T& back() {
        return _array[_index];
    }
    size_t size() {
        return (size_t)_index+1;
    }
    size_t capacity() {
        return (size_t)_cap;
    }
    void clear() {
        delete[] _array;
        _array = nullptr;
        _cap = 0;
        _index = -1;
    }
    T* data() { // returns pointer to the first element
        return _array;
    }
    void pop_back() {
        if (_index == 0) {
            delete[] _array;
            _array = nullptr;
            _index = -1;
            _cap = 0;
        } else if (_index > -1) {
            //delete _array[_index];
            //--_cap;
            --_index;
        }
    }
    void erase(Iterator position) {
        for (auto it = position; it != end()-1; ++it) {
            *it = *(it+1); // overwrite the value of current position with the value of next
        }
        //--_cap;
        --_index;
    }
    void erase(Iterator first, Iterator last) {
        int count = 0;
        for (auto& it = first; it != last+1; ++it) {
            ++count;
            *it = *(last+count);
        }
        //_cap -= count;
        _index -= count;
    }
    Iterator insert(Iterator position, const T& value) { // returns an iterator that points to the newly inserted value
        if (position == end()) { // when the new value needs to be attached at the end
            push_back(value);
            return position;
        }

        T prevVal = *position;
        *position = value;
        auto it = position+1;
        T temp;
        for (;it != end(); ++it) {
            temp = *it;
            *it = prevVal;
            prevVal = temp;
        }
        if (_cap == _index + 1) {
            reSize(_array, _cap, _cap*2); // this mix up the address of the position
        }
        it = end(); // reassign the value since we might have changed the address of the _array when calling reSize
        *it = prevVal;
        ++_index;
        return position;
    }
    //Iterator insert(Iterator position, int numInsert, const T& value) {}
};


#endif /* myVector_h */
