//
//  chain_complex.h
//  Chain complex mod 2
//
//  Created by YAJING LIU on 10/1/15.
//  Copyright © 2015 YAJING LIU. All rights reserved.
//




#ifndef chain_complex_h
#define chain_complex_h
#include <string>
#include <set>
#include <unordered_map>

#include "Node_Diff.h"

class Chain_Complex
{
protected:
    std::string Name;
    std::set<int> Generators;
    std::unordered_map<int, Node_Diff> Differentials;

    bool Cancel(int x, int y);
    
public:
    
    /*returns the rank of the homology of this complex*/
    Chain_Complex (std::set<int> Dots, std::string Name);
    Chain_Complex (){};
    virtual ~Chain_Complex(){};
    
    void PrintName();
    void Mod2Put(int k, std::unordered_set<int> &A);
    int Get_Homology();
    void D(int dot, std::unordered_set<int> diff);
    void PrintOut();
};

 

#endif /* chain_complex_h */
