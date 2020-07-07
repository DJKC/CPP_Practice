#include <iostream>
using namespace std;
int main(){
    for(int i=1;i<101;i++){
        if(i%3==0||i%5==0){
            if(i%3==0){cout<<"Fizz";}
            if(i%5==0){cout<<"Buzz";}
            cout<<"\n";
        }else{cout<<"i\n";}
    }
    return 0;
}