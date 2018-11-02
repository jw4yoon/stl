//
//  myVector.h
//  myVector
//
//  Created by James Jae Won Yoon on 2018-10-31.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myVector_h
#define myVector_h

//class initializer_list;

template<typename type>
void doubleSize(type*& arr, int& size) {
    if (size == 0) {
        size = 1;
        arr = new type[size];
        arr[0] = 1;
    } else {
        type* newArray = new type[size*2];
        for (int i = 0; i < size; ++i) {
            newArray[i] = arr[i];
        }
        size *= 2;
        if (arr != nullptr) {
            delete[] arr;
        }
        arr = newArray;
    }
}

template <class T>
class MyVector {
    T *array;
    int size;// = 0;
    int index; //= 0;
public:
    ~MyVector() {
//        for (int i = 0; i < size; ++i) {
//            delete array[i];
//        }
        delete[] array;
    }
    MyVector() {
        size = 0;
        index = 0;
    }
    void push_back(const T& elem) {
        if (size == index) {
            doubleSize(array, size);
        }
        array[index] = elem;
        ++index;
    }
    T operator[] (const int& ind) {
        return array[ind];
    }
    //myVector(std::initializer_list<T> iL) {
        
    //}
    //myVector(std::allocator<class T> )
    
};


#endif /* myVector_h */
