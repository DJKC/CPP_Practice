/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on January 5, 2020, 2:46 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int number = 5;
    void *voidPtr = &number;
    int *intPtr{static_cast<int*>(voidPtr)};
    
    cout << *(static_cast<int*>(voidPtr)) << endl;
    return 0;
}

