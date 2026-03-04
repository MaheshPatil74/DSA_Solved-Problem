#include<iostream>
using namespace std ;

void PrintArray(int arr[] , int size  ){
    for( int i = 0 ; i<size ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl ;
}
/*
//Approach 1 --> My Approach 
void SortZeroOne(int arr[] , int size  ){
    int start = 0 ;
    int end = size - 1 ;
    
    while( start<end ){
        if( arr[start] == 0 ){
            start++ ;
        }else if( arr[end] == 1 ){
            end-- ;
        }else if( arr[start] == 1 && arr[end] == 0 ){
            swap( arr[start] , arr[end]  ) ;
        }
    }
}
*/

// Approach 2 --> Sir approach
void SortZeroOne(int arr[] , int size  ){
    int left = 0 ;
    int right = size - 1 ;
    
    while( left<right ){
        while( arr[left] == 0 && left<right ){
            left++ ;
        }
        while( arr[right] == 1 && left<right ){
            right-- ;
        }
        
        if( left<right ){
            swap( arr[left] , arr[right]  ) ;
            left++ ;
            right-- ;
        }
    }
}

int main(){
    
    int arr[8] = { 1 , 1 , 0 , 0 , 0 , 0 , 1 , 0 } ; 
    
    PrintArray( arr , 8) ;    
    SortZeroOne(arr , 8 ) ;
    PrintArray( arr , 8) ;
    
    return 0 ;
}