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

template<typename type>
void reSize(type*& arr, int& size, int newSize) {
    type* newArray = new type[newSize];
    if (arr != nullptr) {
        for (int i = 0; i < size; ++i) {
            newArray[i] = arr[i];
        }
        delete[] arr;
    }
    arr = newArray;
    size = newSize;
    
//    if (size == 0) {
//        arr = new type[newSize];
//    } else {
//        type* newArray = new type[newSize];
//        if (arr != nullptr) {
//            for (int i = 0; i < size; ++i) {
//                newArray[i] = arr[i];
//            }
//            delete[] arr;
//        }
//        arr = newArray;
//    }
//    size = newSize;
}

template <class T>
class MyVector {
    T *array = nullptr;
    int size = 0;
    int index = 0;
public:
    ~MyVector() {
//        for (int i = 0; i < size; ++i) {
//            delete array[i];
//        }
        delete[] array;
    }
    MyVector() {} // basic constructor
    MyVector(std::initializer_list<T> il) { // constructor with initializer_list
        size_t listSize = il.size();
        reSize(array, size, (int)listSize); // why does reSize(array, size, size*2) work?
        for (size_t i = 0; i < listSize; ++i) {
            array[i] = il.begin()[i];
        }
        index = (int)listSize - 1;
    }
    MyVector(const MyVector& vec) { // copy constructor
        std::cout << vec.size << " " << vec.index << std::endl;
        this->size = vec.size;
        this->index = vec.index;
        reSize(array, this->size, this->size);
        for (int i = 0; i < this->size; ++i) {
            array[i] = vec.array[i];
        }
    }
    MyVector& operator=(const MyVector& other) { // copy assignment operator
        if (this != &other) { // avoid self-assignment
            reSize(array, size, other.size);
            for (int i = 0; i < other.size; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    void push_back(const T& elem) {
        if (size == index) {
            reSize(array, size, std::max(1, size*2)); // if size == 0, newSize needs to be 1
        }
        array[index] = elem;
        ++index;
    }
    T operator[] (const int& ind) {
        return array[ind];
    }
};


#endif /* myVector_h */
