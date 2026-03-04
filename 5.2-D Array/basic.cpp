#include<iostream>
using namespace std ;


//Function For Search An Element in 2-D Array
int Search(int arr[][4] , int row , int col , int k ){

    for(int i = 0 ; i<row ; i++ ){
        for(int j = 0 ; j<col ; j++ ){

            if(arr[i][j]==k){
                return 1 ;
            }
        }
    }
    return 0 ;

}
    

int main(){

    //creating array
    //int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12} ;
    //int arr[3][4] = { { 1,11,111,1111 } , { 2,22,222,2222 } , { 3,33,333,3333 } } ;
    int arr[3][4] ;

    
    //taking input --> Row Wise
    for(int row = 0 ; row<3 ; row++ ){
        for(int col = 0 ; col<4 ; col++ ){
            cin>>arr[row][col] ;
        }
    }
    

    /*
    //taking input --> Column Wise
    for(int col = 0 ; col<4 ; col++ ){
        for(int row = 0 ; row<3 ; row++ ){
            cin>>arr[roe][col] ;
        }
    }
    */

    // Printing Array Element 
    for(int row = 0 ; row<3 ; row++ ){
        for(int col = 0 ; col<4 ; col++ ){
            cout<<arr[row][col]<<" " ;
        }
        cout<<endl ;
    }
    
    cout<<"Enter The Element To Be Search in 2-D Array : ";
    int target ;
    cin>>target ;

    
    if( Search(arr,3,4,target) ){
        cout<<"Element Is Found...."<<endl ;
    }
    else{
        cout<<"Element Not Found..."<<endl ;
    }
        

    return 0 ;
}