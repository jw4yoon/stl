//
//  runPairTests.cpp
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include "runTests.h"
#include "runPairTests.h"
#include "myPair.h"

#include <assert.h>

RunPairTests::RunPairTests() : _name{"MyPair"} {}

void RunPairTests::run() {
    testBasic();
    testCopyConstructor();
    testCopyAssignmentOperator();
    testMakePair();
    return;
}

std::string RunPairTests::getName() {
    return _name;
}

void RunPairTests::testBasic() {
    MyPair<int, std::string> firstPair;
    MyPair<int, std::string> secondPair{2, "123"};
    assert(secondPair.first == 2);
    assert(secondPair.second == std::string("123"));
}

void RunPairTests::testCopyConstructor() {
    MyPair<int, std::string> origPair{1, "Hello!"};
    MyPair<int, std::string> copy = origPair;
    assert(copy.first == origPair.first);
    assert(copy.second == origPair.second);
}

void RunPairTests::testCopyAssignmentOperator() {
    MyPair<int, std::string> origPair{1, "Hello!"};
    MyPair<int, std::string> copy;
    copy = origPair;
    assert(copy.first == origPair.first);
    assert(copy.second == origPair.second);
}

void RunPairTests::testMakePair() {
    MyPair<int, std::string> pair;
    //pair = MyPair<int, std::string>::make_pair(1, "Hello world!");
    pair = Pair::make_pair(1, std::string("Hello world!"));
    assert(pair.first == 1);
    assert(pair.second == std::string("Hello world!"));
    
    std::cout << "testMakePair passed" << std::endl;
}
