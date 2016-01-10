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
#include "chain_complex.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>

void chain_complex::mod2put(int k, std::unordered_set<int> &A){
    if (A.find(k)!=A.end()) A.erase(k);
    else A.insert(k);
}

bool chain_complex::cancellation(int x, int y){
    if (generators.find(x)==generators.end() || generators.find(y)==generators.end() || differentials[x].diff.find(y)==differentials[x].diff.end()) return false;
    
    for (int i: differentials[y].prediff) {
        if (i!=x) {
            differentials[i].diff.erase(y);
            for (int k: differentials[x].diff) {
                if (k!=y) mod2put(k, differentials[i].diff);
            }
        }
    }
    for (int j: differentials[x].diff){
        if (j!=y) {
            differentials[j].prediff.erase(x);
        }
    }
    generators.erase(x);
    generators.erase(y);
    return true;
}

int chain_complex::get_homology(){
    int ans=0;
    std::vector<int> generators1;
    while(!generators.empty()){
        int x=*generators.begin();
        if (differentials[x].diff.empty() && differentials[x].prediff.empty()) {
            ans++;
            generators.erase(x);
            generators1.push_back(x);
        }
        else if (!differentials[x].diff.empty()) {
            int y=*differentials[x].diff.begin();
            cancellation(x, y);
        }
        else {
            int y=*differentials[x].prediff.begin();
            cancellation(y, x);
        }
    }
    for (int x: generators1) generators.insert(x);
    std::cout << "The homology of "<< name<<  " is of rank "<< ans <<std::endl;
    return ans;
}

void chain_complex::printname(){
    std:: cout << name <<std::endl;
}

//chain_complex::chain_complex(){}


void chain_complex::D(int dot,std::unordered_set<int> diffs){
    differentials[dot].diff=diffs;
    for (int k: diffs) {
        differentials[k].prediff.insert(dot);
    }
}

void chain_complex::printout(){
    for (int k: generators){
        std::cout<< "d(" <<k <<")=";
        
        if (differentials[k].diff.empty()){
            std::cout<< "0;" <<std::endl;
        }else {
            std::string s;
            for (int j: differentials[k].diff){
                s.append(std::to_string(j));
                s+="+";
            }
            s.back()=';';
            std::cout << s <<std::endl;
        }
    }
/*    for (int k: generators){
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

int graded_complex::get_grading(int gen) {
    if (!grading.empty()) return grading[gen];
    else return INT_MIN;
}

int graded_complex::betti_number(int k){
    if (graded_homology.find(k)!=graded_homology.end()) return graded_homology[k];
    else {
        std::vector<int> generators1;
        while(!generators.empty()){
            int x=*generators.begin();
            if (differentials[x].diff.empty() && differentials[x].prediff.empty()) {
                if (!grading.empty()) {int a=grading[x]; graded_homology[a]++;}
                generators.erase(x);
                generators1.push_back(x);
            }
            else if (!differentials[x].diff.empty()) {
                int y=*differentials[x].diff.begin();
                cancellation(x, y);
            }
            else {
                int y=*differentials[x].prediff.begin();
                cancellation(y, x);
            }
        }
        for (int x: generators1) generators.insert(x);
        return graded_homology[k];
    }
}

void graded_complex::set_grading(std::unordered_set<int> gen, int deg){
    for (int x: gen) grading[x]=deg;
}


