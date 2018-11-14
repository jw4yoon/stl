//
//  runTests.hpp
//  myVector
//
//  Created by James Jae Won Yoon on 2018-11-09.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef runTests_hpp
#define runTests_hpp

class RunTests {
public:
    void run(); // returns 0 if all tests pass, 1 otherwise
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
};

#endif /* runTests_hpp */
