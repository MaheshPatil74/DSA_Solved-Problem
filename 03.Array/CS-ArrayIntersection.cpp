#include <iostream>
using namespace std ;

//Approach 2 --> Efficient
void ArrayIntersection2(int arr1[] , int arr2[] , int num1 , int num2 ){
    int i = 0 , j = 0 ;
    while( i<num1 && j < num2 ){
        if( arr1[i]<arr2[j] ){
            i++ ;
        }else if( arr1[i] == arr2[j] ){
            cout<<arr1[i]<<" ";
            i++ ;
            j++ ;
        }else{
            j++ ;
        }
    }
}

//Approach 1 --> In-Efficient
void ArrayIntersection1(int arr1[] , int arr2[] , int m , int n ){
    
    for(int i = 0 ; i<m ; i++ ){
        for(int j = 0 ; j<n ; j++ ){
            if( arr1[i] == arr2[j] ){
                cout<<arr1[i]<<endl ;
                arr2[j] = -1 ;
                break ;
            }
        }
    }
}

int main() {
    int a[6] = { 1 , 2 , 2 , 2 , 3 , 4 } ;
    int b[4] = { 2 , 2 , 3 , 3 } ;
    //ArrayIntersection1(a , b , 6 , 4 );
    ArrayIntersection2(a , b , 6 , 4 );
    
    return 0;
}