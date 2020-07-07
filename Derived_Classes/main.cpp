/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on December 8, 2019, 12:22 AM
 */

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <array>
#include "RightTriangle.h"
#include "Square.h"

int main(int argc, char** argv){
    Square square(4.0);
    char y = 'Y';
    RightTriangle triangle(4, 4, y);
    
    std::cout.precision(3);
    std::cout << square << triangle;
    
    return 0;
}

