/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on January 6, 2020, 10:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <array>

using namespace std;

struct Action{

int main(int argc, char** argv) {
    std::array<int, 5> ary{1,2,3,4,5};
    auto begin = std::begin(ary);
    auto end = std::end(ary);
    
    /*auto begin{ &ary[0] };
    // note that this points to one spot beyond the last element
    auto end{begin + std::size(data)};*/
    
    for(auto b = begin; b != end; ++b){
        cout << *b << "~";}
    
    cout << endl;
    
    for(int b : ary){
       cout << b << "`";}

    return 0;
}