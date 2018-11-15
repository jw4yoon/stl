//
//  runTests.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-09.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef runTests_h
#define runTests_h

#include <string>

class RunTests {
public:
    virtual void run() = 0;
    virtual std::string getName() = 0;
};

#endif /* runTests_h */
