//
//  chain_complex.h
//  Chain complex mod 2
//
//  Created by YAJING LIU on 10/1/15.
//  Copyright © 2015 YAJING LIU. All rights reserved.
//




#ifndef chain_complex_h
#define chain_complex_h

#include "node_diff.h"
#include <set>
#include <unordered_map>
#include <string>

class chain_complex{
protected:
    std::string name;
    std::set<int> generators;
    std::unordered_map<int, node_diff> differentials;

    
    bool cancellation(int x, int y);
    
public:
    
    
    /*returns the rank of the homology of this complex*/
    chain_complex (std::set<int> dots, std::string name): name (name), generators (dots){
        for (int x: generators) differentials[x]=node_diff(x);
    };
    chain_complex (){};
    virtual ~chain_complex(){};
    
    void printname();
    void mod2put(int k, std::unordered_set<int> &A);
    int get_homology();
    void D(int dot, std::unordered_set<int> diff);
    void printout();
};

class graded_complex : public chain_complex{
protected:
    std::unordered_map<int, int> grading;
    std::unordered_map<int, int> graded_homology;


public:
    graded_complex(std::set<int> dots,std::string name): chain_complex(dots,name){};
    
    void set_grading(std::unordered_set<int> gen, int deg);
    int betti_number(int deg);
    int get_grading(int gen);
};

#endif /* chain_complex_h */
