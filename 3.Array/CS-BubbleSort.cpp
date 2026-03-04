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
// Time Complexity : O(n^2) <<== in worst Case
// Time Complexity : O(n) <<== in best Case
// Space Complexity : O(1)
// stable Sorting Algorithm
// Inplace Sorting Algorithm
// Swap are used in this Algorithm

void BubbleSort( int arr[] , int n ){
    for( int i = 0 ; i<n-1 ; i++ ){
        bool swapped = false ; 
        for( int j = 0 ; j<n-i-1 ; j++ ){
            if( arr[j] > arr[j+1] ){
                swap( arr[j] , arr[j+1] );
                swapped = true ;
            }
        }
        if(swapped == false)
            break ;     //Already Sorted 
    }
}

int main() {
    int array[5] = { 5 , 4 , 3 , 2 , 1 } ;
    PrintArray(array,5);
    BubbleSort(array,5);
    PrintArray(array,5);
    return 0;
}