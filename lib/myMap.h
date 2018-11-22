//
//  myMap.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myMap_h
#define myMap_h

#include <iterator>
#include <initializer_list>

#include "common.h"
#include "myPair.h"
#include "myVector.h"

template<class Key, class Value>
class MyMap {
    MyVector<MyPair<Key, Value>> _myVector;
public:
    MyMap(){
        std::cout << "Basic constructor called" << std::endl;
    }
    explicit MyMap(std::initializer_list<MyPair<Key, Value>> il) {
        std::cout << "Constructor with initializer_list" << std::endl;
        for (auto elem : il) { // but need to sort this in order to perform O(logn) search
            _myVector.push_back(elem);
        }
    }
    MyMap(const MyMap& other) : _myVector(other._myVector) {
        std::cout << "Copy constructor called" << std::endl;
    }
    MyMap& operator=(const MyMap& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {
            _myVector = other._myVector;
        }
        return *this;
    }
    MyMap(const MyMap&& other) : _myVector(std::move(other._myVector)) {
        std::cout << "Move constructor called" << std::endl;
    }
    MyMap& operator=(const MyMap&& other) {
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) {
            _myVector = std::move(other._myVector);
        }
        return *this;
    }
    class Iterator {
        MyVector<MyPair<Key, Value>>::Iterator _it;
    public:
        explicit Iterator(MyVector<MyPair<Key, Value>>::Iterator it): _it{it} {}
        T& operator*() const {
            return _it[curPos];
        }
        Iterator& operator++() {
            ++_it;
            return *this;
        }
        Iterator& operator++(int) {
            return ++(*this);
        }
        bool operator==(const Iterator& other) {
            return _it == other;
        }
        bool operator!=(const Iterator& other) {
            return !(*this==other); // invoke operator==
        }
        Iterator operator+(int num) {
            return _it+num;
        }
        Iterator operator-(int num) {
            return _it-num;
        }
    };
    Iterator begin() {
        return Iterator{_myVector.begin()};
    }
    Iterator end() {
        return Iterator{_myVector.end()};
    }
    
    /*
    MyMap& operator[](Key key) {
    }
     */
    
    
    
};

#endif /* myMap_h */
