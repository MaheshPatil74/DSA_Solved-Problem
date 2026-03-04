#include <iostream>
using namespace std ;

void PrintArray(int arr[] , int n ){
    cout<<"Array : ";
    for(int i = 0 ; i<n ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// Both Code are Same
// Time Complexity : O(n^2) <<== in worst Case
// Time Complexity : O(n) <<== in best Case
// Space Complexity : O(1)
// stable Sorting Algorithm
// Inplace Sorting Algorithm
// Shift are used in this Algorithm



//Code 1 : Sir Code
void InsertionSort1( int arr[] , int n ){
    for( int i = 1 ; i<n ; i++ ){
        int temp = arr[i] ;
        int j = i-1 ;
        for(  ; j>=0 ; j-- ){
            if( arr[j] > temp ){
                //shift
                arr[j+1] = arr[j] ;
            }
            else{
                //ruk jao
                break ;
            }
        }
        arr[j+1] = temp ;
    }
}

//Code 2 : My code
void insertionSort(int n, vector<int> &arr){
    for( int i = 1 ; i<n ; i++ ){
        int temp = arr[i] ;
        int j = i-1 ;
        while( j>=0 && arr[j]>temp ){
            arr[j+1] = arr[j] ;
            j--;
        }
        arr[j+1] = temp ;
    }
}

int main() {
    int array[5] = { 5 , 4 , 3 , 2 , 1 } ;
    cout<<"Given Array : ";
    PrintArray(array,5);
    InsertionSort2(array,5);
    cout<<"Sorted Array : ";
    PrintArray(array,5);
    return 0;
}