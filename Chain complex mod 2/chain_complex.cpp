//
//  chain_complex.cpp
//  Chain complex mod 2
//
//  Created by YAJING LIU on 10/1/15.
//  Copyright © 2015 YAJING LIU. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "Chain_Complex.h"


Chain_Complex::Chain_Complex (std::set<int> Dots, std::string Name): Name (Name), Generators (Dots)
{
    for (int x: Generators) Differentials[x]=Node_Diff(x);
};


void Chain_Complex::Mod2Put(int k, std::unordered_set<int> & A)
{
    if (A.find(k)!=A.end())
    {
        A.erase(k);
    }
    else
    {
        A.insert(k);
    }
}

bool Chain_Complex::Cancel(int x, int y)
{
    if (Generators.find(x)==Generators.end()
        || Generators.find(y)==Generators.end()
        || Differentials[x].Diff.find(y)==Differentials[x].Diff.end()
        )
    {
        return false;
    }
    
    
    for( int i: Differentials[y].Prediff )
    {
        if (i != x)
        {
            Differentials[i].Diff.erase(y);
            for (int k: Differentials[x].Diff)
            {
                if (k != y) Mod2Put(k, Differentials[i].Diff);
            }
        }
    }
    for (int j: Differentials[x].Diff)
    {
        if (j != y)
        {
            Differentials[j].Prediff.erase(x);
        }
    }
    
    Generators.erase(x);
    Generators.erase(y);
    
    return true;
}

int Chain_Complex::Get_Homology()
{
    int ans=0;
    std::vector<int> generators1;
    while(!Generators.empty())
    {
        int x = *Generators.begin();
        if (Differentials[x].Diff.empty() && Differentials[x].Prediff.empty())
        {
            ans++;
            Generators.erase(x);
            generators1.push_back(x);
        }
        else if (!Differentials[x].Diff.empty())
        {
            int y=*Differentials[x].Diff.begin();
            Cancel(x, y);
        }
        else
        {
            int y=*Differentials[x].Prediff.begin();
            Cancel(y, x);
        }
    }
    
    for (int x: generators1)
    {
        Generators.insert(x);
    }
    
    std::cout << "The homology of "<< Name <<  " is of rank "<< ans <<std::endl;
    
    return ans;
}

void Chain_Complex::PrintName()
{
    std:: cout << Name <<std::endl;
}

//chain_complex::chain_complex(){}


void Chain_Complex::D(int Dot,std::unordered_set<int> Diffs)
{
    Differentials[Dot].Diff=Diffs;
    for (int k: Diffs)
    {
        Differentials[k].Prediff.insert(Dot);
    }
}

void Chain_Complex::PrintOut()
{
    for (int k: Generators)
    {
        std::cout<< "D(" << k << ")=";
        
        if (Differentials[k].Diff.empty())
        {
            std::cout << "0;" << std::endl;
        }
        else
        {
            std::string s;
            for (int j: Differentials[k].Diff)
            {
                s.append(std::to_string(j));
                s+="+";
            }
            s.back()=';';
            std::cout << s <<std::endl;
        }
    }
/*  //The following is for testing.
    for (int k: generators){
        std::cout<< "prediff(" <<k <<")={";
        
        std::string s;
        for (int j: differentials[k].prediff){
            s.append(std::to_string(j));
            s+=",";
        }
        s.pop_back();
        std::cout << s << "}" <<std::endl;
        
    }
 */
}




