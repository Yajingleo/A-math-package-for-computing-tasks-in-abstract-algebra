//
//  Header.h
//  Chain complex mod 2
//
//  Created by YAJING LIU on 10/1/15.
//  Copyright © 2015 YAJING LIU. All rights reserved.
//



#ifndef node_diff_h
#define node_diff_h
#include <unordered_set>

struct node_diff {
    int node;
    std::unordered_set<int> diff;
    std::unordered_set<int> prediff;
    node_diff(int k): node(k){};
    node_diff(){};
};

#endif /* node_diff_h */
