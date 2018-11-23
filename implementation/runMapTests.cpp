//
//  runMapTests.cpp
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include "runTests.h"
#include "runMapTests.h"
#include "myMap.h"

RunMapTests::RunMapTests() : _name{"MyMap"} {}

void RunMapTests::run() {
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
