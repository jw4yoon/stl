//
//  myMap.h
//  STL
//
//  Created by James Jae Won Yoon on 2018-11-15.
//  Copyright © 2018 James Jae Won Yoon. All rights reserved.
//

#ifndef myMap_h
#define myMap_h

#include "common.h"

template<class Key, class Value>
class MyMap {
    
    // need to make the key value as a pair. Implement MyPair class first
    Key *_keys = nullptr;
    int _keyCapacity = 0;
    int _keyIndex = -1;
    
    Value *_values = nullptr;
    int _valueCapacity = 0;
    int _valueIndex = -1;
    
};

#endif /* myMap_h */
