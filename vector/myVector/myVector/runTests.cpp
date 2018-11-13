//
//  runTests.cpp
//  myVector
//
//  Created by James Jae Won Yoon on 2018-11-09.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include "runTests.hpp"
#include "myVector.h"
#include <assert.h>

void RunTests::testBasic() {
    MyVector<int> basicVec;
    basicVec.push_back(1);
    assert(basicVec.size() == 1);
    assert(basicVec[0] == 1);
}

void RunTests::vectorInitWithSize() {
    MyVector<int> initSizeVec(10, 0);
    assert(initSizeVec.size() == 10);
    for (const auto& elem : initSizeVec) {
        assert(elem == 0);
    }
}

void RunTests::vectorInitWithInitializerList() {
    MyVector<int> initWithIL{10, 20, 30, 40, 50};
    assert(initWithIL.size() == 5);
    assert(initWithIL[0] == 10);
    assert(initWithIL[1] == 20);
    assert(initWithIL[2] == 30);
    assert(initWithIL[3] == 40);
    assert(initWithIL[4] == 50);
}

void RunTests::testCopyConstructor() {
    MyVector<int> original{1,2};
    MyVector<int> copy = original;
    assert(original.size() == copy.size());
    assert(original[0] == copy[0]);
    assert(original[1] == copy[1]);
}

void RunTests::testCopyAssignmentOperator() {
    MyVector<int> original{1,2};
    MyVector<int> copy;
    copy = original;
    assert(original.size() == copy.size());
    assert(original[0] == copy[0]);
    assert(original[1] == copy[1]);
}

void RunTests::testMoveConstructor() {
    MyVector<int> original{1,2};
    MyVector<int> moveConst(std::move(original));
    assert(original.empty());
    assert(moveConst.size() == 2);
    assert(moveConst[0] == 1);
    assert(moveConst[1] == 2);
}

void RunTests::testMoveAssignmentOperator() {
    MyVector<int> original{1,2};
    MyVector<int> moveAssign;
    moveAssign = std::move(original);
    assert(original.empty());
    assert(moveAssign.size() == 2);
    assert(moveAssign[0] == 1);
    assert(moveAssign[1] == 2);
}

void RunTests::testFrontAndBack() {
    MyVector<int> vec{0};
    assert(vec.front() == 0);
    assert(vec.back() == 0);
    MyVector<int> longerVec{1,2,3};
    assert(longerVec.front() == 1);
    assert(longerVec.back() == 3);
    longerVec.front() = 3;
    longerVec.back() = 1;
    assert(longerVec.front() == 3);
    assert(longerVec.back() == 1);
}

void RunTests::testCapacity() {
    MyVector<int> cap{1};
    cap.push_back(2);
    cap.push_back(3);
    assert(cap.size() == 3);
    assert(cap.capacity() == 4);
}

void RunTests::testData() {
    MyVector<int> vecData{5,4};
    assert(*(vecData.data()) == 5);
}

void RunTests::testIterator() {
    MyVector<int> manyElements{1,2,3,4,5};
    int count = 0;
    for (const auto& elem : manyElements) {
        assert(elem == 1 + count);
        count++;
    }
    assert(count == 5);
    count = 0;
    for (auto& elem : manyElements) {
        ++elem;
    }
    for (MyVector<int>::Iterator it = manyElements.begin(); it != manyElements.end(); ++it) {
        assert(*it == 2 + count);
        ++count;
    }
    assert(count == 5);
    count = 0;
    for (auto it = manyElements.begin()+1; it != manyElements.end()-1; it++) {
        assert(*it == 3+count);
        ++count;
    }
    assert(count == 3);
}

void RunTests::testPopBack() {
    MyVector<int> vec{1,3};
    vec.pop_back();
    assert(vec.size() == 1);
    vec.pop_back();
    assert(vec.empty());
}

void RunTests::testInsert() {
    MyVector<int> vec{1,2,4};
    vec.insert(vec.begin(), 0);
    vec.insert(vec.begin()+3, 3);
    vec.insert(vec.end(), 5);
    int count = 0;
    for (const auto& elem : vec) {
        assert(elem == 0+count);
        ++count;
    }
    assert(count == 6);
}

void RunTests::testErase() {
    MyVector<int> vecToErase{1,2,3,4,5};
    vecToErase.erase(vecToErase.begin());
    assert(vecToErase.size() == 4);
    int count = 0;
    for (auto it = vecToErase.begin(); it != vecToErase.end(); ++it) {
        assert(*it == 2+count);
    }
    assert(count == 4);
    vecToErase.erase(vecToErase.begin()+1, vecToErase.end()-2);
    assert(vecToErase.size() == 2);
    assert(vecToErase[0] == 2);
    assert(vecToErase[1] == 5);
}

void RunTests::run() {
    testBasic();
    vectorInitWithSize();
    vectorInitWithInitializerList();
    testCopyConstructor();
    testCopyAssignmentOperator();
    testMoveConstructor();
    testMoveAssignmentOperator();
    testFrontAndBack();
    testCapacity();
    testData();
    testIterator();
    testPopBack();
    testInsert();
    testErase();
}
