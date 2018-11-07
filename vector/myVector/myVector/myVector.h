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

template<typename T>
void reSize(T*& arr, int& size, int newSize) {
    T* newArray = new T[newSize];
    if (arr != nullptr) {
        for (int i = 0; i < size; ++i) {
            newArray[i] = arr[i];
        }
        delete[] arr;
    }
    arr = newArray;
    size = newSize;
}

template <class T>
class MyVector {
    T *array = nullptr;
    int size = 0;
    int index = -1;
public:
    ~MyVector() {
//        for (int i = 0; i < size; ++i) {
//            delete array[i];
//        }
        delete[] array;
    }
    MyVector() { // basic constructor
        std::cout << "Basic constructor called" << std::endl;
    }
    MyVector(std::initializer_list<T> il) { // constructor with initializer_list
        std::cout << "Constructor with initializer_list called" << std::endl;
        size_t listSize = il.size();
        reSize(array, size, (int)listSize); // why does reSize(array, size, size*2) work?
        for (size_t i = 0; i < listSize; ++i) {
            array[i] = il.begin()[i];
        }
        index = (int)listSize - 1;
    }
    MyVector(const MyVector& vec) { // copy constructor
        std::cout << "Copy constructor called" << std::endl;
        size = vec.size;
        index = vec.index;
        reSize(array, this->size, this->size);
        for (int i = 0; i < this->size; ++i) {
            array[i] = vec.array[i];
        }
    }
    MyVector& operator=(const MyVector& other) { // copy assignment operator
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            reSize(array, size, other.size);
            for (int i = 0; i < other.size; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    MyVector(MyVector&& other) { // move constructor
        std::cout << "Move constructor called" << std::endl;
        array = other.array;
        size = other.size;
        index = other.index;
        other.array = nullptr;
        other.size = 0;
        other.index = -1;
    }
    MyVector& operator=(MyVector&& other) { // move assignment operator
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            delete[] array;
            array = other.array;
            size = other.size;
            index = other.index;
            other.array = nullptr;
            other.size = 0;
            other.index = -1;
        }
        return *this;
    }
    class Iterator {
        T* t;
        int i;
    public:
        explicit Iterator(T* t, int i): t{t}, i{i} {}
        T& operator*() const {
            return *t;
        }
        Iterator& operator++() {
            ++t;
            return *this;
        }
        Iterator& operator++(int) {
            return ++(*this); // or ++this?
        }
        bool operator==(const Iterator& other) {
            return t == other.t;
        }
        bool operator!=(const Iterator& other) {
            return !(*this==other);
        }
        Iterator operator+(int num) {
            if (num < i && num > -1) {
                return Iterator{t+num, num};
            } else {
                return Iterator{&(t[i]), i}; // same as Iterator end(). out_of_range
            }
            
        }
    };
    Iterator begin() {
        return Iterator{array, index+1};
    }
    Iterator end() {
        return Iterator{&(array[index+1]), index+1};
    }
    
    
    void push_back(const T& elem) {
        ++index;
        if (size == index) {
            reSize(array, size, std::max(1, size*2)); // if size == 0, newSize needs to be 1
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
    size_t capacity() {
        return (size_t)size;
    }
    void clear() {
        delete[] array;
        size = 0;
        index = -1;
    }
    T* data() { // returns pointer to the first element
        return array;
    }
    void pop_back() {
        if (index > -1) {
            //delete array[index];
            --index;
            --size;
        }
    }
};


#endif /* myVector_h */
