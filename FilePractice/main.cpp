/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on August 31, 2019, 8:07 AM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

//Takes in a short array and simply displays the elements
void display_array(short[], short);

int main(int argc, char** argv) {
    ifstream infile;
    ofstream outfile;
    char infileName[15], outfileName[15] = "outfile.txt";
    float number;
    
    cout << "What is the name of the input file (up to 14 characters): ";
    cin >> infileName;
    
    infile.open(infileName);
    
    if(infile.fail()){
        cout << "Input file failed to open, now exiting" << endl;
        exit(0);
    }
    
    short count = 0;
    
    while(infile >> number){
        count++;
    }
    
    cout << "Numbers in file: " << count << endl;
    
    infile.close();
    infile.open("infile.txt");
    
    outfile.open(outfileName, ios::app);
//  outfile.open("outfile.txt", ios::app);
    
    if(outfile.fail()){
        cout << "Output file failed to open" << endl;
    }
    
    short number_array[count];
    
    cout << endl << "Contents of the array: " << endl;
    
    for(short i : number_array){
        infile >> number_array[i];
    }
    
    display_array(number_array, count);
    
    outfile.close();
    infile.close();
    
    cout << "Done : " << endl;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << setw(4) << number << setw(4) << "010" << endl
         << setw(4) << "1111" << setw(4) << "aaaa";
    
    return 0;
}

void display_array(short array[], short length){
    for(short i = 0; i < length; i++){
        cout << "\tCurrent number: " << array[i] << endl;
    }
    
}