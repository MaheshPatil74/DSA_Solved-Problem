#include<iostream>
using namespace std ;

// Heapify function can put data or node to its correct position
// TC = O(logN)
// here we implement for maxHeap
void heapify(int arr[] , int n , int i ){
    int largest = i ;
    int left = 2*i ;
    int right = 2*i + 1 ;
    
    if( left<=n && arr[largest]<arr[left]){
        largest = left ;
    }
    if( right<=n && arr[largest]<arr[right]){
        largest = right ;
    }

    if( largest != i ){
        swap( arr[largest] , arr[i] ) ;
        heapify(arr,n,largest) ;
    }
}

void print(int arr[] , int n){
    cout<<"Printing Heap Array : ";
    for(int i = 1 ; i<=n ; i++)
        cout<< arr[i] << " ";
    cout<<endl ;
}

int main(){
    int arr[6] = {-1,54,53,55,52,50} ;
    int n = 5 ;

    // BuildHeap in O(n)
    for(int i = n/2 ; i>0 ; i-- ){
        heapify(arr,n,i) ;
    }
    print(arr,n) ;
    return 0 ;
}