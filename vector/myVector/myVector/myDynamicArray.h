//
//  myDynamicArray.h
//  myVector
//
//  Created by James Jae Won Yoon on 2018-10-31.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myDynamicArray_h
#define myDynamicArray_h

template <class T>
class myDynamicArray{
    T *arr;
    int size;
public:
    myDynamicArray () {
        arr = new T[1];
    }
    T& operator [](int index) {
        return arr[index];
    }
    T operator [](int index) {
        return arr[index];
    }
    operator T*() const {
        return arr;
    }
};


#endif /* myDynamicArray_h */
