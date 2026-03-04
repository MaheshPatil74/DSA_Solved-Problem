#include <iostream>
using namespace std ;

//Without Recursion
int BinarySearch(int arr[] , int size , int key ){
    int left = 0 ;
    int right = size - 1 ;

    int mid = left + (( right - left )/2) ;

    while( left<=right ){
        
        if( arr[mid] == key ){      //Checking Mid Index
            return mid ;
        }
        else if( arr[mid]<key ){    //Goto Left Part
            left = mid + 1 ;
        }
        else{                       //Goto Right Part
            right = mid - 1 ;
        }
        mid = left + (( right - left )/2) ;
    }
    return -1 ;
}

int main() {
    
    int array[5] = { 1,2,3,4,5 } ;
    int num ;
    cout<<"Enter The Number To be Search : ";
    cin>>num ;
    int index = BinarySearch(array , 5 , num) ;
    if(index != -1){
        cout<<num<<" is Present at Index "<<index<<endl ;
    }
    else{
        cout<<num<<" is Absent in Array . "<<endl;
    }
    
    return 0;
}