//
//  runVectorTests.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-13.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef runVectorTests_h
#define runVectorTests_h

#include "runTests.h"
#include <string>

class RunVectorTests : public RunTests {
public:
    void run() override;
    std::string getName() override;
    RunVectorTests();
private:
    void testBasic();
    void vectorInitWithSize();
    void vectorInitWithInitializerList();
    void testCopyConstructor();
    void testCopyAssignmentOperator();
    void testMoveConstructor();
    void testMoveAssignmentOperator();
    void testFrontAndBack();
    void testCapacity();
    void testData();
    void testIterator();
    void testPopBack();
    void testInsert();
    void testInsertReturnValue();
    void testErase();
    
    std::string _name;
};

#endif /* runVectorTests_h */

