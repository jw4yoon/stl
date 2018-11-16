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
private:    
    std::string _name;
};

#endif /* runMapTests_h */
