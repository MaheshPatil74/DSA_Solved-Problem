#include<iostream>
using namespace std ;

// Default argument  -->
// Always Give default Argument from Right to left
// if we can not pass a parameter in function calling , default value of that parameter is considered

void print(int arr[] , int n , int start = 0 ){

    for(int i = start ; i<n ; i++ ){
        cout<< arr[i] << endl ;
    }
    cout<<endl ;
}

int main(){
    int arr[5] = { 1,2,3,4,5 } ;
    int size = 5 ;

    print(arr,size,2) ;
    cout<<endl ;
    print(arr,size) ;

    return 0 ;
}