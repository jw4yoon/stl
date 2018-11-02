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

template<typename T>
void doubleSize(T* arr, int& size, int ind) {
    if (ind == size) {
        T* newArray = new T[size*2];
        for (int i = 0; i < size; ++i) {
            newArray[i] = arr[i];
        }
        size *= 2;
    }
    
}

template <class T>
class myVector {
    T *array;
    int size = 1;
    int index = 0;
public:
    ~myVector() {
        for (int i = 0; i < size; ++i) {
            delete array[i];
        }
        delete[] array;
    }
    myVector() {}
    //myVector(std::initializer_list<T> iL) {
        
    //}
    myVector(std::allocator<class T> )
    
};


#endif /* myVector_h */
