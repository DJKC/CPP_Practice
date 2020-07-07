/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: newjcc
 *https://www.learncpp.com/cpp-tutorial/712-handling-errors-assert-cerr-exit-and-exceptions/
 * Created on December 20, 2019, 3:14 PM
 */

#include <iostream>
#include <string>
 
void printString(const char *cstring);

int main()
{
    std::string hello{ "Hello, world!" };
    int index;
 
    do
    {
        std::cout << "Enter an index: ";
        std::cin >> index;
 
        //handle case where user entered a non-integer
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
            index = -1; // ensure index has an invalid value so the loop doesn't terminate
            continue; // this continue may seem extraneous, but it explicitly signals an intent to terminate this loop iteration...
        }
 
        // ...just in case we added more stuff here later
 
    } while (index < 0 || index >= static_cast<int>(hello.size())); // handle case where user entered an out of range integer
 
    std::cout << "Letter #" << index << " is " << hello [index] << '\n';
 
    char char_array[3];

    printString(char_array);
    printString(hello.c_str());
    
    return 0;
}

void printString(const char *cstring)
{
    // Only print if cstring is non-null
    if (cstring)
        std::cout << cstring << '!';
    else
        std::cerr << "function printString() received a null parameter";
}