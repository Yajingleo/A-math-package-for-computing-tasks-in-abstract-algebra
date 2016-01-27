//
//  Graded_Complex.h
//  Chain complex mod 2
//
//  Created by YAJING LIU on 1/26/16.
//  Copyright © 2016 YAJING LIU. All rights reserved.
//

#ifndef Graded_Complex_h
#define Graded_Complex_h
#include "Chain_Complex.h"

class Graded_Complex : public Chain_Complex
{
protected:
    std::unordered_map<int, int> Grading;
    std::unordered_map<int, int> Graded_Homology;

public:
    Graded_Complex(std::set<int> Dots,std::string Name): Chain_Complex(Dots,Name){};
    void Set_Grading(std::unordered_set<int> Gen, int Deg);
    int Betti_Number(int Deg);
    int Get_Grading(int Gen);
};


#endif /* Graded_Complex_h */
