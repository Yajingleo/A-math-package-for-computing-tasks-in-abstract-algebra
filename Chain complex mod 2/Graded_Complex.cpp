//
//  Graded_Complex.cpp
//  Chain complex mod 2
//
//  Created by YAJING LIU on 1/26/16.
//  Copyright © 2016 YAJING LIU. All rights reserved.
//
#include "Chain_Complex.h"
#include "Graded_Complex.h"
#include <vector>

int Graded_Complex::Get_Grading(int Gen)
{
    return Grading.empty() ? INT32_MIN : Grading[Gen];
}

int Graded_Complex::Betti_Number(int k)
{
    if (Graded_Homology.find(k) != Graded_Homology.end())
    {
        return Graded_Homology[k];
    }
    
    std::vector<int> generators1;
    
    while(!Generators.empty())
    {
        int x=*Generators.begin();
        if (Differentials[x].Diff.empty() && Differentials[x].Prediff.empty())
        {
            if (!Grading.empty())
            {
                int a=Grading[x];
                Graded_Homology[a]++;
            }
            Generators.erase(x);
            generators1.push_back(x);
        }
        else if (!Differentials[x].Diff.empty())
        {
            int y = *Differentials[x].Diff.begin();
            Cancel(x, y);
        }
        else
        {
            int y = *Differentials[x].Prediff.begin();
            Cancel(y, x);
        }
    }
    
    for (int x: generators1)
    {
        Generators.insert(x);
    }
    
    return Graded_Homology[k];
    
}

void Graded_Complex::Set_Grading(std::unordered_set<int> Gen, int Deg){
    for (int x: Gen)
    {
        Grading[x] = Deg;
    }
}
