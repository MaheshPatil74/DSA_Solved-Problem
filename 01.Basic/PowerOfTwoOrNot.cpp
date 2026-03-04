#include <iostream>
#include <math.h>
using namespace std ;
//checking Number is Power of Two Or Not

bool PowerOfTwo( int num ){
    int flag = 0 ;
    for(int i = 0 ; i <= 30 ; i++ ){
        if( num == pow(2,i) ){
            flag = 1 ;
        }
    }
    return flag ;
}

int main() {
    int number ;
    cout<<"Enter The Number : ";
    cin>>number ;
    
    if(PowerOfTwo(number)){
        cout<<"Yes , "<<number<<" is Power of 2 ." ;
    }else{
        cout<<"No , "<<number<<" is not Power of 2 ." ;
    }
    
    return 0;
}