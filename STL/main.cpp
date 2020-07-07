/* 
 * File:   main.cpp
 * Author: newjcc
 *
 * Created on January 6, 2020, 4:02 PM
 */

//All, Count, Count If, Find, Find If, For Each, Copy If

#include <cstdlib>
#include <array>
#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

bool containsNum(string_view str){
    return(str.find("1") != string_view::npos);
}

bool isMultiple(int number){
    return(((number % 1) == 0) && (number != 0));
}

bool greatest(int a, int b){
    return (a > b);
}

void doubleNumber(int &number){
    number *= 2;
}

bool isEven(int number){
    return (number % 2) == 0;
}

int main(int argc, char** argv){
    std::array<string_view, 5> arr{"1", "12", "3", "4" , "7"};
    array<int, 10> arrNum{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 4> arrNum3{0, 2, 4, 6};
    
    string find, replace;

    /*cout << "[";
    
    for(auto i : arr){
        cout << i << " ";}
    
    cout << "]";
    
    cout << "\n\n\t\t\tFind STL" << endl;
    
    cout << "Look for what number: ";
    cin >> find;
    
    cout << "Replace with what number: ";
    cin >> replace;
    
    //Third argument to find is a function that uses the type of arr as its parameters
    auto found{std::find(arr.begin(), arr.end(), find)};
    
    if(found != arr.end()){
        *found = replace;
        cout << "\"" << find << "\" found and replaced with  \"" << *found << "\"" <<endl;}
    else{
        cout << "Could not find " << find << "!\n";}
    
    for(auto i : arr){
        cout << i << " ";}
    
    found = nullptr;
    
    //
    
    cout << "\n\n\t\t\tFind_if STL" << endl;
    
    found = std::find_if(arr.begin(), arr.end(), containsNum);
    
    if(found == arr.end()){
        cout << "\nDoes not contain " << find << "." << endl;}
    else{
        cout << "\"" << find << "\" found and replaced with  \"" << *found << "\"" <<endl;}
    
    found = nullptr;
    
    //
    
    cout << "\n\t\t\tCount STL" << endl;
    
    cout << "\nCount the occurence of which number: ";
    cin >> find;
    
    int count = std::count(arr.begin(), arr.end(), find);
    
    cout << find << " occurs[ " << count << "] times.";
    
    count  = 0;
    
    //
    
    cout << "\n\t\t\tCount_if STL" << endl;
    
    count = std::count_if(arrNum.begin(), arrNum.end(), isMultiple);
    
    cout << "\n" << find << " is a multiple of [ " << count << "] numbers.";
    
    //
    cout << "\n\t\t\tSort STL" << endl;
    
    std::sort(arrNum.begin(), arrNum.end(), greatest);
    
    for(auto i : arrNum){
        cout << i << " ";}
    
    //
    cout << "\n\t\t\tFor_each STL" << endl;
    
    std::for_each(arrNum.begin(), arrNum.end(), doubleNumber);
    
    for(auto i : arrNum){
        cout << i << " ";}
    
    /*/
    
    cout << "\n\t\t\tCopy_if STL" << endl;
    
    std::vector<int> source = {0, 2, 3, 4, 6, 7, 9, 10, 12, 13};
    std::vector<int> destination(source.size());    
    
    cout << "\nDestination : ";
    for(auto i : destination){
        cout << i << " ";
    }
    cout << "\n";

    auto iterator = std::copy_if(source.begin(), source.end(), destination.begin(), [](int number){return (number % 2) == 0;});
    destination.resize(std::distance(destination.begin(), iterator));
    
    cout << "\nDestination : ";
    for(auto i : destination){
        cout << i << " ";
    }
    cout << "\n";
    
    //
    cout << "\n\t\tAll STL" << endl;
    
    //Returns 1 even if false for isEven, fix bug!
    auto answer = std::all_of(arrNum.begin(), arrNum.end(), [](int number){return ((number % 2) == 0);});
    cout << "Are all the numbers even: " << answer << endl;
    
    answer = std::all_of(arrNum.begin(), arrNum.end(), isEven);
    cout << "Are all the numbers even: " << answer << endl;
    
    return 0;
}