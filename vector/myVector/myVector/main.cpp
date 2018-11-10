//
//  main.cpp
//  myVector
//
//  Created by James Jae Won Yoon on 2018-10-31.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include <iostream>
#include "myVector.h"
#include "runTests.hpp"
#include <vector>

int main(int argc, const char * argv[]) {
    RunTests runThem;
    runThem.run();
    /*
    MyVector<int> basicVec;
    basicVec.push_back(1);
    
    MyVector<int> initSizeVec(10, 0);
    for (const auto& elem : initSizeVec) {
        std::cout << elem << std::endl;
    }

    MyVector<int> initWithIL{10, 20, 30, 40, 50};

    MyVector<int> vecCopy = initWithIL;
    
    MyVector<int> copyAssign;
    copyAssign = vecCopy;

    MyVector<int> moveConst(std::move(basicVec));
    
    if (basicVec.empty() == true) {
        std::cout << "basicVec moved" << std::endl;
    }
    
    MyVector<int> moveAssign;
    moveAssign = std::move(moveConst);

    std::cout << moveAssign.at(0) << std::endl;
    //std::cout << moveAssign.at(1) << std::endl; //throws SIGABRT
    
    if (initWithIL.back() == initWithIL[4] && initWithIL.back() == 50) {
        std::cout << "MyVector::back() works" << std::endl;
    }
    
    std::cout << (int)initWithIL.capacity() << std::endl;
    initWithIL.push_back(60);
    initWithIL[5] = 6;

    auto ptr = initWithIL.data();
    ++ptr;
    initWithIL.pop_back();
    
    std::cout << "loop start" << std::endl;
    for (MyVector<int>::Iterator it = initWithIL.begin(); it != initWithIL.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    MyVector<int> one{1};
    std::cout << "here " << one[0] << std::endl;
    one.pop_back();
    
    MyVector<int> testEraseInsert{1,2,3};
    testEraseInsert.erase(testEraseInsert.begin()+1);
    for (const auto& elem : testEraseInsert) {
        std::cout << elem << std::endl;
    }
    
    initWithIL.erase(initWithIL.begin()+1, initWithIL.begin()+3);
    for (MyVector<int>::Iterator it = initWithIL.begin(); it != initWithIL.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    testEraseInsert.insert(testEraseInsert.begin(), 4);
    for (const auto& elem : testEraseInsert) {
        std::cout << elem << std::endl;
    }
    
    
    std::vector<int> testing{1,2,3};
    testing.insert(testing.begin()+10, 4);
    for (const auto& elem : testing) {
        std::cout << elem << std::endl;
    }
     */

    /*
    MyVector<int*> pointerVec;
    int myNum = 0;
    int* intPtr = &myNum;
    pointerVec.push_back(intPtr);
    std::cout << "this is pointerVec[0] == " << *pointerVec[0] << std::endl;
    MyVector<int*> ptrVec{intPtr};
    std::cout << "ptrVec[0] == " << *ptrVec[0] << std::endl;
     */
    
    return 0;
}
