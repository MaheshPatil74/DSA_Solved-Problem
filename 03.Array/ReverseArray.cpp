#include <iostream>
using namespace std ;

void ReverseArray(int arr[] , int size ){
    for(int i = 0 ; i<size/2 ; i++){
        swap(arr[i] , arr[size-i-1] ) ;
    }   
}

void PrintArray(int arr[] , int size){
    for(int i = 0 ; i<size ; i++ ){
        cout<<arr[i]<<" "; 
    }
    cout<<endl ;
}

int main() {
    int array[5] = { 5,4,3,2,1 } ;
    
    PrintArray(array , 5);
    ReverseArray(array , 5 ) ;
    PrintArray(array , 5);
    
    return 0;
}