#include<iostream>
using namespace std ;

void print(int arr[] , int n ){
    cout<<"Size of Array : "<<n<<endl ;
    cout<<"Array : ";
    for(int i = 0 ; i<n ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl ; ;
}

// Linear Search ==>> 
bool LinearSearch( int *arr ,int size , int target ){
    if( size == 0 )
        return false ;
    if( arr[0] == target )
        return true ;
    else
        return LinearSearch(arr+1 , size-1 , target ); ;
}

// Binary Search ==>> 
int Binarysearch(int arr[] , int start , int end , int target ){

    if(start<=end ){
        int mid = start + (end-start)/2 ;
        if( arr[mid] == target )      // element at mid index
            return mid ;
        else if( arr[mid]<target )    // search in Right Part
            return Binarysearch(arr, mid+1 , end , target ) ;
        else                          // search in Left Part
            return Binarysearch(arr , start , mid-1 , target ) ;
    }
    
    return -1 ;
}


int main(){
    int arr[6] = { 2,4,6,7,8,9} ;
    int size = 6 ;
    int key = 2 ;

    //bool ans = LinearSearch(arr,size,key) ;
    int ans = Binarysearch(arr ,0 , size-1 ,key) ;
    if(ans != -1 )
        cout<<"Element " << key <<" is Found at Index : "<<ans <<endl ; 
    else
        cout<<"Element Not Found ."<<endl ;

    return 0 ;
}