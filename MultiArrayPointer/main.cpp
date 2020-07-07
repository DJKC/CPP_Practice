//Author: stella coulter
//Description: hello world
//date: 11-20-2019

#include <iostream>
#include <iomanip>

using namespace std;
 
int main(){
    int rows = 10, columns = 2, **array, count = 0;
    
    array = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        array[i] = new int[columns];
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            array[i][j] = count++;
        }
    }
    
    for(int i = 0, j = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << setw(3) << array[i][j];
        }
        
        cout << endl;
        
    }

    for(int i = 0; i < rows; i++){
        delete [] array[i];
    }
    
    delete [] array;
    
    return 0;
}