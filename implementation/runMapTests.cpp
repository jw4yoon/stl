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

//#include "gtest/gtest.h"

RunMapTests::RunMapTests() : _name{"MyMap"} {}

void RunMapTests::run() {
    testBasic();
    checkElements();
    checkMoreElements();
    testEmptyAndSize();
    testFind();
    testInsert();
    testEraseWithIterator();
    testEraseWithKey();
    testEraseWithRange();
    testAt();
    testAtOutOfRange();
    testClear();
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
    MyMap<std::string, int> myMap{{"abc", 1}, {"ghi", 3}, {"def", 2}}; // not in sorted order
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
    assert(myMap.find(2) == myMap.end());
    assert(myMap.find(1) != myMap.end());
}

void RunMapTests::testInsert() {
    MyMap<std::string, int> myMap;
    myMap.insert(Pair::make_pair(std::string("Hello"), 1));
    myMap.insert(Pair::make_pair(std::string("world!"), 2));
    int val = 1;
    for (const auto& elem : myMap) {
        assert(elem.second == val);
        ++val;
    }
}

void RunMapTests::testEraseWithIterator() {
    MyMap<int, std::string> myMap{{3, "789"}, {1, "123"}, {2, "456"}};
    myMap.erase(myMap.begin()+1); // erase 2
    assert(myMap.size() == 2);
    assert(myMap.find(1) != myMap.end());
    assert(myMap.find(1)->second == "123");
    assert(myMap.find(2) == myMap.end());
    assert(myMap.find(3) != myMap.end());
    assert(myMap.find(3)->second == "789");
}

void RunMapTests::testEraseWithKey() {
    MyMap<int, std::string> myMap{{3, "789"}, {1, "123"}, {2, "456"}};
    myMap.erase(1);
    assert(myMap.size() == 2);
    int val = 2;
    for (auto it = myMap.begin(); it != myMap.end(); it++) {
        assert(it->first == val);
        ++val;
    }
}

void RunMapTests::testEraseWithRange() {
    MyMap<int, std::string> myMap{{3, "789"}, {1, "123"}, {2, "456"}, {5, "0"}, {4, "10"}};
    myMap.erase(myMap.begin()+2, myMap.end()-1); // removing pairs with key 3 and 4. Range doens't include the right end
    assert(myMap.size() == 3);
    assert(myMap.find(1) != myMap.end());
    assert(myMap.find(2) != myMap.end());
    assert(myMap.find(3) == myMap.end());
    assert(myMap.find(4) == myMap.end());
    assert(myMap.find(5) != myMap.end());
}

void RunMapTests::testAt() {
    MyMap<int, std::string> myMap{{3, "789"}, {1, "123"}, {2, "456"}, {5, "0"}, {4, "10"}};
    assert(myMap.at(1) == "123");
    assert(myMap.at(3) == "789");
}
void RunMapTests::testAtOutOfRange() {
    MyMap<int, int> myMap;
    try {
        myMap.at(1);
    } catch (std::out_of_range){
        std::cout << "Exception caught, key doesn't exist" << std::endl;
    }
    
}
void RunMapTests::testClear() {
    MyMap<int, std::string> myMap{{3, "789"}, {1, "123"}, {2, "456"}, {5, "0"}, {4, "10"}};
    assert(myMap.size() == 5);
    myMap.clear();
    assert(myMap.size() == 0);
}
