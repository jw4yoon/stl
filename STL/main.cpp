//
//  main.cpp
//  STL
//
//  Created by James Jae Won Yoon on 2018-10-31.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#include <iostream>
#include "myVector.h"
#include "runTests.h"
#include "runVectorTests.h"
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<std::shared_ptr<RunTests>> testList;
    std::shared_ptr<RunTests> vectorTest = std::make_shared<RunVectorTests>();
    testList.push_back(vectorTest);
    for (const auto& test : testList) {
        std::cout << "Starting " << test->getName() << " test" << std::endl;
        test->run();
        std::cout << test->getName() << " test end" << std::endl;
    }
    return 0;
}
