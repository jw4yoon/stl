//
//  runMapTests.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef runMapTests_h
#define runMapTests_h

#include "runTests.h"
#include <string>

class RunMapTests : public RunTests {
public:
    void run() override;
    std::string getName() override;
    RunMapTests();
    void testBasic();
    void testCopyConstructor();
    void testCopyAssignmentOperator();
    void testMoveConstructor();
    void testMoveAssignmentOperator();
    void checkElements();
    void checkMoreElements();
    void overwriteValue();
    void testEmptyAndSize();
    void testFind();
    void testInsert();
    void testEraseWithIterator();
    void testEraseWithKey();
    void testEraseWithRange();
    void testAt();
    void testAtOutOfRange();
    void testClear();
    // add tests for copy, move map
    // add {testname} passed after passing each test?
private:    
    std::string _name;
};

#endif /* runMapTests_h */
