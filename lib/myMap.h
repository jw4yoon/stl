//
//  myMap.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myMap_h
#define myMap_h

#include "common.h"
#include "myPair.h"
#include "myVector.h"

template<class Key, class Value>
class MyMap {
    MyVector<MyPair<Key, Value>> _myMap;
public:
    MyMap(){
        std::cout << "Basic constructor called" << std::endl;
    }
    MyMap(const MyMap& other) : _myMap(other._myMap) {
        std::cout << "Copy constructor called" << std::endl;
    }
    MyMap& operator=(const MyMap& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {
            _myMap = other._myMap;
        }
        return *this;
    }
    MyMap(const MyMap&& other) : _myMap(std::move(other._myMap)) {
        std::cout << "Move constructor called" << std::endl;
    }
    MyMap& operator=(const MyMap&& other) {
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) {
            _myMap = std::move(other._myMap);
        }
        return *this;
    }
    
    
    /*
    MyMap& operator[](Key key) {
    }
     */
    
    
    
};

#endif /* myMap_h */
