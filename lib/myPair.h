//
//  myPair.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myPair_h
#define myPair_h

#include <iostream>

template<class First, class Second>
class MyPair {
public:
    First first;
    Second second;
    
    MyPair() {
        //std::cout << "Basic constructor called" << std::endl;
    }
    MyPair(First first, Second second) : first(first), second(second) {
        //std::cout << "Constructor with MIL" << std::endl;
    }
    MyPair(const MyPair& other) : first(other.first), second(other.second) {
        //std::cout << "Copy constructor called" << std::endl;
    }
    MyPair& operator=(const MyPair& other) { // copy assignment operator
        //std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            this->first = other.first;
            this->second = other.second;
        }
        return *this;
    }
    MyPair(MyPair&& other) {
        //std::cout << "Move constructor called" << std::endl;
        first = std::move(other.first);
        second = std::move(other.second);
    }
    MyPair& operator=(const MyPair&& other) { // move assignment operator
        //std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) {
            this->first = std::move(other.first);
            this->second = std::move(other.second);
        }
        return *this;
    }
};

namespace Pair{
template<class First, class Second>
MyPair<First, Second> make_pair(First first, Second second) {
    return MyPair<First, Second>(first, second);
}
}

#endif /* myPair_h */
