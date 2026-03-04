#include<iostream>
using namespace std ;

void PrintArray(int arr[] , int n ){
    for(int i = 0 ; i<n ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl ;
}

void SortArray(int * arr , int n ){

    // base case--> Already Sorted
    if( n==0 || n==1 ){
        return ;
    }

    // 1 case solve karlia --> largest element ko end main rakh dega 
    for(int i = 0 ; i+1<n ; i++ )
        if( arr[i]> arr[i+1] )
            swap(  arr[i] , arr[i+1] ) ;

    SortArray(arr , n-1 ) ;
}

int main(){
    int arr[5] = {5,4,3,2,1} ;
    PrintArray(arr,5) ;
    SortArray(arr,5) ;
    PrintArray(arr,5) ;
    return 0 ;
}