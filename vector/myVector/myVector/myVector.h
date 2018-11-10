//
//  myVector.h
//  myVector
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

template<typename T>
void reSize(T*& arr, int& cap, int newSize) {
    T* newArray = new T[newSize];
    if (arr != nullptr) {
        for (int i = 0; i < cap; ++i) {
            newArray[i] = arr[i];
        }
        delete[] arr;
    }
    arr = newArray;
    cap = newSize;
}

template <class T>
class MyVector {
    T *array = nullptr;
    int cap = 0;
    int index = -1;
public:
    ~MyVector() {
//        for (int i = 0; i < cap; ++i) {
//            delete array[i];
//        }
        if (array != nullptr) {
            delete[] array;
            array = nullptr;
        }
    }
    MyVector() { // basic constructor
        std::cout << "Basic constructor called" << std::endl;
    }
    explicit MyVector(int numSize, int value) {
        std::cout << "Constructor with numSize and value" << std::endl;
        reSize(array, cap, numSize);
        for (int i = 0; i < numSize; ++i) {
            array[i] = value;
        }
        index = numSize - 1;
    }
    explicit MyVector(std::initializer_list<T> il) { // constructor with initializer_list
        std::cout << "Constructor with initializer_list called" << std::endl;
        size_t listSize = il.size();
        reSize(array, cap, (int)listSize); // why does reSize(array, cap, cap*2) work?
        for (size_t i = 0; i < listSize; ++i) {
            array[i] = il.begin()[i];
        }
        index = (int)listSize - 1;
    }
    MyVector(const MyVector& vec) { // copy constructor
        std::cout << "Copy constructor called" << std::endl;
        cap = vec.cap;
        index = vec.index;
        reSize(array, this->cap, this->cap);
        for (int i = 0; i < this->cap; ++i) {
            array[i] = vec.array[i];
        }
    }
    MyVector& operator=(const MyVector& other) { // copy assignment operator
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            reSize(array, cap, other.cap);
            for (int i = 0; i < other.cap; ++i) {
                array[i] = other.array[i];
            }
            index = other.index;
        }
        return *this;
    }
    MyVector(MyVector&& other) { // move constructor
        std::cout << "Move constructor called" << std::endl;
        array = other.array;
        cap = other.cap;
        index = other.index;
        other.array = nullptr;
        other.cap = 0;
        other.index = -1;
    }
    MyVector& operator=(MyVector&& other) { // move assignment operator
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            delete[] array;
            array = other.array;
            cap = other.cap;
            index = other.index;
            other.array = nullptr;
            other.cap = 0;
            other.index = -1;
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
        return Iterator{array, index+1, 0};
    }
    Iterator end() {
        return Iterator{array, index+1, index+1};
    }
    
    
    void push_back(const T& elem) {
        ++index;
        if (cap == index) {
            reSize(array, cap, std::max(1, cap*2)); // if cap == 0, newSize needs to be 1
        }
        array[index] = elem;
    }
    bool empty() {
        return index == -1;
    }
    T& operator[] (const int& ind) {
        return array[ind];
    }
    T& at(int ind) {
        if (ind > index || ind < 0) {
            throw std::out_of_range("out of range");
        } else {
            return array[ind];
        }
    }
    T& front() {
        return array[0];
    }
    T& back() {
        return array[index];
    }
    size_t size() {
        return (size_t)index+1;
    }
    size_t capacity() {
        return (size_t)cap;
    }
    void clear() {
        delete[] array;
        array = nullptr;
        cap = 0;
        index = -1;
    }
    T* data() { // returns pointer to the first element
        return array;
    }
    void pop_back() {
        if (index == 0) {
            delete[] array;
            array = nullptr;
            index = -1;
            cap = 0;
        } else if (index > -1) {
            //delete array[index];
            --cap;
            --index;
        }
    }
    void erase(Iterator position) {
        for (auto it = position; it != end(); ++it) {
            *it = *(it+1); // overwrite the value of current position with the value of next
        }
        --cap;
        --index;
    }
    void erase(Iterator first, Iterator last) {
        int count = 0;
        for (auto& it = first; it != last+1; ++it) {
            ++count;
            *it = *(last+count);
        }
        cap -= count;
        index -= count;
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
        if (cap == index - 1) {
            reSize(array, cap, cap*2);
        }
        *it = prevVal;
        ++index;
        return position;
    }
    //Iterator insert(Iterator position, int numInsert, const T& value) {}
};


#endif /* myVector_h */
