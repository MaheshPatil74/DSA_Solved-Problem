#include<iostream>
using namespace std ;

bool isSorted( int arr[] ,int size ){

    //Base case
    if( size == 0 || size == 1 ){
        return true ;
    }

    if( arr[0] > arr[1] ){
        return false ;
    }
    else{
        bool remainingPart = isSorted( arr+1 , size-1 ) ;
        return remainingPart ;
    }

}

int main(){
    int arr[5] = { 2,4,6,6,6} ;


    bool ans = isSorted(arr,5) ;
    if(ans){
        cout<<"Array IS Sorted . ";
    }
    else{
        cout<<"Array is unsorted . " ;
    }
    return 0 ;
}