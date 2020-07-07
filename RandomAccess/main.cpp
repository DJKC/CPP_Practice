/* 
 * File:   main.cpp
 * Author: DJKC
 *
 * Created on January 20, 2020, 10:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    char file_name[]{"file.txt"};
    fstream file(file_name, ios::out | ios::in);
    int character = 9, alakazam = 100;
    
    if(!file){
        file.open(file_name, ios::out | ios::app);
        file.close();
        file.open(file_name, ios::out | ios::in);
    }
    
    std::cout << "Character: " << character << "\nAlakazam: " << alakazam << "\n";
    
    file << character << "\n" << alakazam;
    file.seekg(0L, ios::beg);
    file >> alakazam >> character;
    
    std::cout << "Character: " << character << "\nAlakazam: " << alakazam << "\n";
    
    file.close();
    
    return 0;
}