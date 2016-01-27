//
//  main.cpp
//  Chain complex mod 2
//
//  Created by YAJING LIU on 10/1/15.
//  Copyright © 2015 YAJING LIU. All rights reserved.
//

#include "node_diff.h"
#include "Chain_Complex.h"
#include "Graded_Complex.h"
#include <set>
#include <unordered_set>
#include <iostream>


int main(int argc, const char * argv[]) {
    std::set<int> dots ({1,2,3,4,5,6});
    Graded_Complex C (dots, "C");
//setting up the differentials
    C.D(1,std::unordered_set<int> ({2,3}));
    C.D(2,std::unordered_set<int> ({4}));
    C.D(3, std::unordered_set<int> ({4}));
//  setting up gradings
    C.Set_Grading(std::unordered_set<int> ({1}),2);
    C.Set_Grading(std::unordered_set<int> ({2,3}),1);
    C.Set_Grading(std::unordered_set<int> ({4,5,6}),0);
    C.PrintName();
    C.PrintOut();
    C.Get_Homology();
    
    std::cout << "The betti number b(0)= " << C.Betti_Number(0) <<std::endl;
    return 0;
}
