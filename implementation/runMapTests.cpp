//
//  runMapTests.cpp
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include <assert.h>

#include "runTests.h"
#include "runMapTests.h"
#include "myMap.h"

RunMapTests::RunMapTests() : _name{"MyMap"} {}

void RunMapTests::run() {
    testBasic();
    checkElements();
    return;
}

std::string RunMapTests::getName() {
    return _name;
}

void RunMapTests::testBasic() {
    MyMap<int, std::string> myMap;
    MyMap<int, std::string> myMapTwo{{1, "123"}, {3, "789"}, {2, "567"}};
    assert(myMapTwo.find(1)->second == "123");
}


void RunMapTests::checkElements() {
    MyMap<std::string, int> myMap{{"abc", 1}, {"ghi", 3}, {"def", 2}};
    assert(myMap.find("abc")->second == 1);
    assert(myMap.find("ghi")->second == 2);
    assert(myMap.find("def")->second == 3);
    int val = 1;
    for (auto elem : myMap) { // checking if they are in order
        assert(elem.second == val);
        ++val;
    }
 
}
