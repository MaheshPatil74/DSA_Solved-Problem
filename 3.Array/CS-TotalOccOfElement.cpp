#include <iostream>
using namespace std ;

int FirstOcc(int arr[] , int size , int key ){
    int left = 0 ;
    int right = size - 1 ;
    int ans = -1 ;
    while( left<=right ){
        int mid = left + (( right - left )/2) ;
        
        if( arr[mid] == key ){
            ans = mid ;
            right = mid - 1 ;
        }
        else if( arr[mid]<key ){
            left = mid + 1 ;
        }
        else{
            right = mid - 1 ;
        }
    }
    return ans ;
}

int LastOcc(int arr[] , int size , int key ){
    int left = 0 ;
    int right = size - 1 ;
    int ans = -1 ;
    while( left<=right ){
        int mid = left + (( right - left )/2) ;
        
        if( arr[mid] == key ){
            ans = mid ;
            left = mid + 1 ;
        }
        else if( arr[mid]<key ){
            left = mid + 1 ;
        }
        else{
            right = mid - 1 ;
        }
    }
    return ans ;
}

int main() {
    
    int array[8] = { 1,2,2,3,4,4,4,5 } ;
    int num ;
    cout<<"Enter The Number To be Search : ";
    cin>>num ;
    
    cout<<"First Occurence of "<<num<<" is Present at Index "<<FirstOcc(array , 8 , num )<<endl ;
    cout<<"last Occurence of "<<num<<" is Present at Index "<<LastOcc(array , 8 , num )<<endl ;
    int Total = LastOcc(array , 8 , num ) - FirstOcc(array , 8 , num ) + 1 ;
    cout<<"Total Number of Occurence of "<<num<<" is "<<Total<<endl ;
    
    return 0;
}