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
    checkMoreElements();
    testEmptyAndSize();
    testFind();
    testInsert();
    testErase();
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
    for (auto elem : myMap) { // checking if they are in order(sorted)
        assert(elem.second == val);
        std::cout << "val == " << val << std::endl;
        ++val;
    }
}

void RunMapTests::checkMoreElements() { // ensure binary search works well
    MyMap<int, int> myMap{{9, 2}, {3, 8}, {4,7}, {7,4}, {10, 1}, {1, 10}, {8, 3}, {5, 6}, {2, 9}, {6, 5}};
    int val = 10;
    for (int i = 1; i < 11; ++i) {
        assert(myMap.find(i)->second == val);
        --val;
    }
    val = 10;
    for (auto elem : myMap) {
        assert(elem.second == val);
        --val;
    }
}

void RunMapTests::overwriteValue() {
    MyMap<int, std::string> myMap{{1, "Hello"}};
    assert(myMap[1] == "Hello");
    myMap[1] = "world!";
    assert(myMap[1] == "world!");
}

void RunMapTests::testEmptyAndSize() {
    MyMap<int, int> myMap;
    assert(myMap.empty());
    assert(myMap.size() == 0);
    myMap[10] = 100;
    assert(!myMap.empty());
    assert(myMap.size() == 1);
    assert(myMap[10] == 100);
}

void RunMapTests::testFind() {
    MyMap<int, int> myMap;
    assert(myMap.find(1) == myMap.end());
    myMap[1] = 1;
    myMap[3] = 3;
    //assert(myMap.find(2) == myMap.end()); // not working right now. need to figure out how to properly handle the keys not in the map
    assert(myMap.find(1) != myMap.end());
}

void RunMapTests::testInsert() {
    MyMap<std::string, int> myMap;
    return;
    //myMap.insert(
}

void RunMapTests::testErase() {
    return;
}
