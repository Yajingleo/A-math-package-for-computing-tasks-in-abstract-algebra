//
//  Header.h
//  Chain complex mod 2
//
//  Created by YAJING LIU on 10/1/15.
//  Copyright © 2015 YAJING LIU. All rights reserved.
//



#ifndef Node_Diff_h
#define Node_Diff_h
#include <unordered_set>

struct Node_Diff
{
    int Node;
    std::unordered_set<int> Diff;
    std::unordered_set<int> Prediff;
    
    Node_Diff(int k): Node(k){};
    Node_Diff(){};
};

#endif /* Node_Diff_h */
