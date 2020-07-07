/* 
 * File:   main.cpp
 * Author: DJKC
 *
 * Created on February 11, 2020, 9:04 PM
 */

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char** argv){
    int number;
    std::string string;
    char character;
    float decimal;
    
    do{
        cout << "Mess me up: ";
        cin >> string;

        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max());
        }
    }while(1);
    
    return 0;
}

