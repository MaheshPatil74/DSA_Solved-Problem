#include <iostream>
using namespace std ;

int SumOfArrayElement(int arr[] , int size){
    int sum = 0 ;
    for(int i = 0 ; i<size ; i++){
        sum = sum + arr[i] ;
    }
    return sum ;
}

int main() {
    int array[100] ;
    int n ;
    cout<<"Enter The Number of Array Element : ";
    cin>>n ;
    cout<<"Enter The Array Element : ";
    for(int i = 0 ; i<n ; i++ ){
        cin>>array[i] ;
    }
    
    cout<<"Sum Of Element In Array : "<<SumOfArrayElement(array , n)<<endl ;
    
    return 0;
}