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
    
    MyPair() {}
    MyPair(First first, Second second) : first{first}, second{second} {
        std::cout << "Basic constructor called" << std::endl;
    }
    MyPair(const MyPair& other) : first{other.first}, second{other.second} {
        std::cout << "Copy constructor called" << std::endl;
    }
    static MyPair make_pair(First first, Second second) {
        return MyPair(first, second);
    }
    MyPair& operator=(const MyPair& other) { // copy assignment operator
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) { // avoid self-assignment
            this->first = other.first;
            this->second = other.second;
        }
        return *this;
    }
};

#endif /* myPair_h */
