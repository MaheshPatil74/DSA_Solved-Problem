#include <iostream>
using namespace std ;

int PeakIndexInMountain(int arr[] , int size ){
    int left = 0 ;
    int right = size - 1 ;
    
    while( left<right ){
        int mid = left + (( right - left )/2) ;
        
        if( arr[mid] < arr[mid+1] ){
            left =  mid + 1 ;
        }
        else{
            right = mid ;
        }
    }
    return left ;
}

int main() {
    
    int array[4] = { 3,4,5,1 } ;
    cout<<PeakIndexInMountain(array,4);
    
    return 0;
}