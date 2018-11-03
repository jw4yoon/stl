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

//class initializer_list;

template<typename type>
void reSize(type*& arr, int& size, int newSize) {
    if (size == 0) {
        size = 1;
        arr = new type[size];
    } else {
        type* newArray = new type[newSize];
        for (int i = 0; i < size; ++i) {
            newArray[i] = arr[i];
        }
        size = newSize;
        if (arr != nullptr) {
            delete[] arr;
        }
        arr = newArray;
    }
}

template <class T>
class MyVector {
    T *array;
    int size = 0;
    int index = 0;
public:
    ~MyVector() {
//        for (int i = 0; i < size; ++i) {
//            delete array[i];
//        }
        delete[] array;
    }
    MyVector() {}
    MyVector(std::initializer_list<T> il) {
        size_t listSize = il.size();
        reSize(array, size, (int)listSize); // why does reSize(array, size, size*2) work?
        for (size_t i = 0; i < listSize; ++i) {
            array[i] = il.begin()[i];
        }
        index = (int)listSize - 1;
    }
    void push_back(const T& elem) {
        if (size == index) {
            reSize(array, size, size*2);
        }
        array[index] = elem;
        ++index;
    }
    T operator[] (const int& ind) {
        return array[ind];
    }
};


#endif /* myVector_h */
