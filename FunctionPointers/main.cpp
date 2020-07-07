/* 
 * File:   main.cpp
 * Author: 
 *
 * Created on January 9, 2020, 12:53 PM
 */

#include <cstdlib>
#include <istd::ostream>

using namespace std;

//fcnPtr_typedef is same as int(*fcnPtr_typedef)(int)(bool);
//int some_function(int(*fcnPtr_typedef)(int)(bool)){...}
//is now
//int some_function(fcnPtr_typedef a_function_variable)...}
//Using a type alias is also the same thing
//using fcnPtr_typedef = int(*)(int, bool);
typedef int (*fcnPtr_typedef)(int&, bool);

int return200(int &number, bool boolean){return (number = 200);}

int return100(int &number, bool boolean){return (number = 100);}

int return5(int &number, bool boolean){return (number = 5);}

//void setFunction(int number, int fcnPtr_(int& an_int, bool a_bool)){ //change of declaration works just for function pointers, just this particular scenario.
fcnPtr_typedef& setFunction(int number, fcnPtr_typedef& function_pointer){
    if(number == 1){
        function_pointer = return100;
    }else if(number == 2){
        function_pointer = return200;
    }else{
        std::cout << "\nNo matching function\n";
    }
    
    return function_pointer;
}

int main(int argc, char** argv) {
    int number = -1;
    
    int (*function_pointer)(int&, bool){return5};
    
    function_pointer = setFunction(1, function_pointer);
    function_pointer(number, 0);
    
    cout << "Number: " << number << endl;
    
    function_pointer = setFunction(2, function_pointer);
    function_pointer(number, 0);
    
    cout << "Number: " << number << endl;
    
    return 0;
}