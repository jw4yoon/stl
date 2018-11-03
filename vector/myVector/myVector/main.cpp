//
//  main.cpp
//  myVector
//
//  Created by James Jae Won Yoon on 2018-10-31.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include <iostream>
#include "myVector.h"
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    MyVector<int> basicVec;
    basicVec.push_back(1);
    std::cout << "This is my output: " << basicVec[0] << std::endl;
    MyVector<int> initWithIL{10, 20, 30, 40, 50};
    std::cout << initWithIL[0] << " " << initWithIL[1] << std::endl;
    MyVector<int> vecCopy = initWithIL;
    std::cout << vecCopy[0] << " " << vecCopy[1] << std::endl;
    
    MyVector<int> copyAssign;
    copyAssign = vecCopy;
    std::cout << copyAssign[0] << " " << copyAssign[1] << std::endl;
    ;
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
