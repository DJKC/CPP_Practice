/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on January 6, 2020, 4:02 PM
 */

#include <array>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>

//using namespace std;

bool isEven(int number){
    return ((number % 2) == 0);
}

int main(int argc, char** argv){
    std::array<int, 10> arrNum{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> arrNum2{0, 10, 2, 34, 4, 52, 6, 724, 8, 90};
    std::string evenOrOdd;
    
    std::function<bool(int)> fcnPtr{[=](int number){return ((number % 2) == 0);}};
    
    bool answer = std::all_of(arrNum2.begin(), arrNum2.end(), fcnPtr);
    
    evenOrOdd = (answer == true ? "are" : "are not");
            
    std::cout << "Are all the numbers " << evenOrOdd << " even";  
    
    int i = 0;
    bool *b;
    
    if(typeid(answer).name() == typeid(i).name()){
        std::cout << "\nSame type\n";
    }else{
        std::cout << "\nNot same type\n";
    }
    
    if(typeid(answer).name() == typeid(*b).name()){
        std::cout << "\nSame type\n";
    }else{
        std::cout << "\nNot same type\n";
    }
    
    return 0;
}