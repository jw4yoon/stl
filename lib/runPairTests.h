//
//  runPairTests.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef runPairTests_h
#define runPairTests_h

#include "runTests.h"
#include <string>

class RunPairTests : public RunTests {
public:
    void run() override;
    std::string getName() override;
    RunPairTests();
private:
    std::string _name;
    
    void testBasic();
    void testCopyConstructor();
    void testCopyAssignmentOperator();
    void testMakePair();
};

#endif /* runPairTests_h */
