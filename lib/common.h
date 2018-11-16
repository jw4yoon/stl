//
//  common.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef common_h
#define common_h

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


#endif /* common_h */
