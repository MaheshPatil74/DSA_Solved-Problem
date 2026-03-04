#include<iostream>
using namespace std ;

int main(){

    int rows ,cols ;
    cout<<"Enter The Number OF Rows : ";
    cin>>rows ;
    cout<<"Enter The Number OF Columns : ";
    cin>>cols ;

    // Creating a 2D Array
    int ** arr = new int *[rows] ;

    for(int i = 0 ; i<rows ; i++ ){
        arr[i] = new int[cols] ;
    }

    // taking input
    cout<<"Enter The Element in 2-D Array : "<<endl ;
    for(int i = 0 ; i<rows ; i++ ){
        for(int j = 0 ; j<cols ; j++ ){
            cin>>arr[i][j] ;
        }
    }

    // taking Output
    cout<<"Element in 2-D Array : "<<endl ;
    for(int i = 0 ; i<rows ; i++ ){
        for(int j = 0 ; j<cols ; j++ ){
            cout<<arr[i][j]<<" " ;
        }
        cout<<endl ;
    }

    //Releasing A Memory 
    for(int i = 0 ; i<rows ; i++ ){
        delete [] arr[i] ;
    }

    delete []arr ;

    return 0 ;
}