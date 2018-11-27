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
    MyMap<int, std::string> myMapTwo{{1, "123"}, {2, "456"}, {3, "789"}}; // in sorted order
    assert(myMapTwo.find(1)->second == "123");
    assert(myMapTwo.find(2)->second == "456");
    assert(myMapTwo.find(3)->second == "789");
}


void RunMapTests::checkElements() {
    MyMap<std::string, int> myMap{{"abc", 1}, {"ghi", 3}, {"def", 2}}; // mixed up
    assert(myMap.find("abc")->second == 1);
    assert(myMap.find("ghi")->second == 3);
    assert(myMap.find("def")->second == 2);
    int val = 1;
    for (auto elem : myMap) { // checking if they are in order
        assert(elem.second == val);
        std::cout << "val == " << val << std::endl;
        ++val;
    }
}
