#include <iostream>
using namespace std ;

int getpivot(int arr[] , int size ){
    int start = 0 ;
    int end = size - 1 ;
    int mid = start + (end-start)/2 ;
    while( start < end ){
        if( arr[mid]>= arr[0] ){
            start = mid + 1 ;
        }else{
            end = mid ;
        }
        mid = start + (end-start)/2 ;
    }
    return start ; 

    //yaha hum kuch bhi return kr sakte hai following main se 
    //cout<<start ;
    //cout<<end
}

int main() {

    int array[5] = {3,4, 5, 1,2} ;
    cout<<"Pivot Element is Found At Index : "<<getpivot(array , 5)<<endl;
    return 0;
}