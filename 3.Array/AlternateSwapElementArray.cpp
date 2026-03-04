#include <iostream>
using namespace std ;

void PrintArray(int arr[] , int size ){
    for(int i = 0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//Swap Alternate Element Of Array
/*
//Approach 1-->My Approach
void AlternateSwap( int arr[] , int size ){
    int start = 0 ;
    int next = 1 ;
    while(next<=size-1){
        swap( arr[start] , arr[next]) ;
        start += 2 ;
        next += 2 ;
    }
}
*/
//Approach 2 --> Love Babbar Sir
void AlternateSwap( int arr[] , int size ){
    for(int i = 0 ; i<size ; i+=2){
        if(i+1<size){
            swap( arr[i] , arr[i+1] ) ;
        }
    }
}

int main() {
    int array[6] = { 1 , 2 , 3 , 4 , 5 , 6  };
    cout<<"Original Array : ";
    PrintArray( array , 6 );
    
    AlternateSwap(array , 6 ) ;

    cout<<"\nArray After Alternate Swapping : ";
    PrintArray( array , 6 );
    return 0;
}