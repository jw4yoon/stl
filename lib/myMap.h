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
//    class Iterator {
//        typename MyVector<MyPair<Key, Value>>::Iterator _it;
//    public:
//        explicit Iterator(typename MyVector<MyPair<Key, Value>>::Iterator it): _it{it} {}
//        typename MyVector<MyPair<Key, Value>>::Iterator& operator*() {
//            return *_it;
//        }
//        Iterator& operator++() {
//            ++_it;
//            return *this;
//        }
//        Iterator& operator++(int) {
//            return ++(*this);
//        }
//        bool operator==(const Iterator& other) {
//            return _it == other._it;
//        }
//        bool operator!=(const Iterator& other) {
//            return !(*this==other); // invoke operator==
//        }
//        Iterator operator+(int num) {
//            return _it+num;
//        }
//        Iterator operator-(int num) {
//            return _it-num;
//        }
//    };
//    Iterator begin() {
//        return Iterator{_myVector.begin()};
//    }
//    Iterator end() {
//        return Iterator{_myVector.end()};
//    }
//
//    Iterator find(Key key) {
//        return placeToInsert(key);
//    }
    class Iterator {
        MyVector<MyPair<Key, Value>> vec;
        int curPos;
    public:
        explicit Iterator(MyVector<MyPair<Key, Value>> vec, int pos): vec{vec}, curPos{pos} {}
        MyPair<Key, Value>& operator*() {
            return vec[curPos];
        }
        MyPair<Key, Value>* operator->() {
            return &vec[curPos];
        }
        Iterator& operator++() {
            if (curPos < vec.size()) {
                ++curPos;
            }
            return *this;
        }
        Iterator& operator++(int) {
            return ++(*this);
        }
        bool operator==(const Iterator& other) {
            return &vec == &other.vec && curPos == other.curPos;
        }
        bool operator!=(const Iterator& other) {
            return !(*this == other);
        }
        Iterator operator+(int num) {
            if (curPos + num > -1 && curPos + num < vec.size()) {
                curPos += num;
                return *this;
            } else {
                curPos = (int)vec.size();
                return *this; // same as Iterator end(). which means out_of_range
            }
        }
        Iterator operator-(int num) {
            num *= -1;
            return (*this)+num;
        }
        int getCurPos () {
            return curPos;
        }
    };
    Iterator begin() {
        return Iterator{_myVector, 0};
    }
    Iterator end() {
        return Iterator{_myVector, (int)_myVector.size()};
    }
    Iterator find(Key key) {
        return placeToInsert(key);
    }
    
    Iterator insert(Iterator position, const MyPair<Key, Value>& pair) { // returns an iterator that points to the newly inserted value
        if (position == end()) { // when the new value needs to be attached at the end
            _myVector.push_back(pair);
            return position;
        }
        
        MyPair<Key, Value> prevPair = *position;
        *position = pair;
        auto it = position+1;
        MyPair<Key, Value> temp;
        for (;it != end(); ++it) {
            temp = *it;
            *it = prevPair;
            prevPair = temp;
        }
        _myVector.push_back(prevPair);
        return Iterator{_myVector, position.getCurPos()};
        return position;
    }
    
    explicit MyMap(std::initializer_list<MyPair<Key, Value>> il) {
        std::cout << "Constructor with initializer_list" << std::endl;
        for (auto elem : il) { // but need to sort this in order to perform O(logn) search
            //auto isFound = find(elem.first);
            Iterator isFound = find(elem.first);
            //if (isFound != _myVector.end()) {
            if (isFound != end()) {
                isFound->second = elem.second;
            } else {
                insert(isFound, Pair::make_pair(elem.first, elem.second));
                //_myVector.insert(isFound, Pair::make_pair(elem.first, elem.second));
            }
        }
    }

private:
    Iterator placeToInsert(Key key) { //
        // perform binary search
        int high = (int)_myVector.size() - 1;
        int middle = 0;
        int low = 0;
        if (high == -1) { // the vector is empty
            //return Iterator{_myVector, 0};
            return begin();
        }
        while (low <= high) {
            middle = (high + low) / 2;
            if (_myVector[middle].first == key) {
                //return Iterator{_myVector, middle};
                return begin()+middle;
            } else if (middle == 0) {
                //return Iterator{_myVector, 0};
                return begin();
            } else if (_myVector[middle].first > key && (middle > 0 && _myVector[middle-1].first < key)) {
                //return Iterator{_myVector.begin()+(middle-1)};
                return begin()+(middle-1);
            } else if (_myVector[middle].first > key) {
                high = middle - 1;
            } else if (_myVector[middle].first < key) {
                low = middle + 1;
            }
        }
        if (middle == 0) {
            return begin();
        } else {
            return end();
        }
    }
    
    /*
    MyMap& operator[](Key key) {
    }
     */
    
    
    
};

#endif /* myMap_h */
