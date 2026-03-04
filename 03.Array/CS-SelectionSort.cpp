#include <iostream>
using namespace std ;

void PrintArray(int arr[] , int n ){
    cout<<"Array : ";
    for(int i = 0 ; i<n ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//Code  : Sir Code --> More Efficient
// Time Complexity : O(n^2) <<== in both best and worst Case
// Space Complexity : O(1)
// Used when we have small size of array
// Unstable Sorting Algorithm
// Inplace Sorting Algorithm
// Swap are used in this Algorithm
void SelectionSort( int arr[] , int n ){
    for( int i = 0 ; i<n-1 ; i++ ){
        int minindex = i ;
        for( int j = i+1 ; j<n ; j++ ){
            if( arr[minindex] > arr[j] ){
                minindex = j ;
            }
        }
        swap( arr[minindex] , arr[i]  );
    }
}   

int main() {
    int array[5] = { 5 , 4 , 3 , 2 , 1 } ;
    PrintArray(array,5);
    SelectionSort(array,5);
    PrintArray(array,5);
    return 0;
}