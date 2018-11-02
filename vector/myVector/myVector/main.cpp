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
    MyVector<int> myVec;
    myVec.push_back(1);
    std::cout << "This is my output: " << myVec[0] << std::endl;
    //std::vector<int> hello{1,2,3};
    //hello.push_back("123");
    return 0;
}
