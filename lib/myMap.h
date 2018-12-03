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
        //std::cout << "Basic constructor called" << std::endl;
    }

    MyMap(const MyMap& other) : _myVector(other._myVector) {
        //std::cout << "Copy constructor called" << std::endl;
    }
    MyMap& operator=(const MyMap& other) {
        //std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {
            _myVector = other._myVector;
        }
        return *this;
    }
    MyMap(const MyMap&& other) : _myVector(std::move(other._myVector)) {
        //std::cout << "Move constructor called" << std::endl;
    }
    MyMap& operator=(const MyMap&& other) {
        //std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) {
            _myVector = std::move(other._myVector);
        }
        return *this;
    }

    class Iterator {
        MyVector<MyPair<Key, Value>>& vec;
        int curPos;
    public:
        explicit Iterator(MyVector<MyPair<Key, Value>>& myVec, int pos): vec{myVec}, curPos{pos} {}
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
        auto it = placeToInsert(key);
        if (it != end() && it->first != key) {
            return end();
        } else {
            return it;
        }
    }

    explicit MyMap(std::initializer_list<MyPair<Key, Value>> il) {
        //std::cout << "Constructor with initializer_list" << std::endl;
        for (auto elem : il) { // need to sort this in order to perform O(logn) search
            //std::cout << elem.first <<  " <- elem.first " << elem.second << " <- elem.second" << std::endl;
            if (_myVector.size() == 0) {
                _myVector.push_back(elem);
                continue;
            }

            Iterator isFound = placeToInsert(elem.first);
            if (isFound != end() && isFound->first == elem.first) {
                isFound->second = elem.second;
            } else {
                insertAtPosition(isFound, Pair::make_pair(elem.first, elem.second));
            }
        }
    }

    Value& operator[](Key key) {
        if (empty()) {
            _myVector.push_back({});
            begin()->first = key;
            return begin()->second;
        } else {
            auto placeFound = placeToInsert(key);
            if (placeFound->first == key) { // pair already exists
                return placeFound->second;
            } else { // pair doesn't exist
                insertAtPosition(placeFound, {});
                placeFound->first = key;
                return placeFound->second;
            }
        }
    }
    
    size_t size() {
        return _myVector.size();
    }
    
    bool empty() {
        return _myVector.empty();
    }

    void erase(Iterator position) {
        if (position != end()) {
            auto vecIterator = _myVector.begin()+position.getCurPos();
            _myVector.erase(vecIterator);
        }
    }
    
    void erase(Key key) {
        auto isFound = find(key);
        if (isFound != end()) {
            erase(isFound);
        }
    }
    
    void erase(Iterator first, Iterator last) {
        auto vecFirstIterator = _myVector.begin()+(first.getCurPos());
        auto vecLastIterator = _myVector.begin()+(last.getCurPos());
        _myVector.erase(vecFirstIterator, vecLastIterator);
    }
    
    void insert(MyPair<Key, Value> pair) {
        auto placeFound = placeToInsert(pair.first);
        insertAtPosition(placeFound, pair);
    }
    
    Value& at(Key key) { // throws out of range if key is not in the map already
        auto isFound = find(key);
        if (isFound == end()) {
            throw std::out_of_range("Key doesn't exist");
        } else {
            return isFound->second;
        }
    }
    
    void clear() {
        _myVector.clear();
    }
    
private:
    Iterator placeToInsert(Key key) {
        // perform binary search
        int high = (int)_myVector.size() - 1;
        int middle = 0;
        int low = 0;
        if (high == -1) { // the vector is empty
            return begin();
        }
        while (low <= high) {
            middle = (high + low) / 2;
            if (_myVector[middle].first == key) {
                return begin()+middle;
            } else if (_myVector[middle].first > key && (middle > 0 && _myVector[middle-1].first < key)) {
                return begin()+middle;
            } else if (_myVector[middle].first > key) {
                high = middle - 1;
            } else if (_myVector[middle].first < key) {
                low = middle + 1;
            }
        }
        if (middle == 0 && low == 0) {
            return begin();
        } else {
            return end();
        }
    }
    
    Iterator insertAtPosition(Iterator position, const MyPair<Key, Value>& pair) { // returns an iterator that points to the newly inserted value
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
    }

};

#endif /* myMap_h */
