#include<iostream>
using namespace std ;

//Function For Printing row wise sum
void RowWiseSum(int arr[][4] , int m , int n ){
    for(int row = 0 ; row<m ; row++ ){
        int sum = 0 ;
        for(int col = 0 ; col<n ; col++ ){

            sum = sum + arr[row][col] ;

        }
        cout<<"Sum Of Row "<<row<<" : "<<sum<<endl ;
    }
}

//Function For Printing column wise sum
void ColWiseSum(int arr[][4] , int m , int n ){
    for(int col = 0 ; col<n ; col++ ){
        int sum = 0 ;
        for(int row = 0 ; row<m ; row++ ){

            sum = sum + arr[row][col] ;

        }
        cout<<"Sum Of Column "<<col<<" : "<<sum<<endl ;
    }
}

int largestRowSum(int arr[][4] , int m , int n ){
    int maxi = 0 ; 
    int rowIndex = -1 ;

    for(int row = 0 ; row<m ; row++ ){
        int sum = 0 ;
        for(int col = 0 ; col<n ; col++ ){
            sum = sum + arr[row][col] ;
        }
        
        if(sum>maxi){
            maxi = sum ;
            rowIndex = row ;
        }
    }
    cout<<"Maximum Row Sum : "<<maxi<<endl ;
    cout<<"Index : ";
    return rowIndex ;
}

int main(){
    int arr[3][4] ;

    //taking input --> Row Wise
    cout<<"Enter The Element : "<<endl ;
    for(int row = 0 ; row<3 ; row++ ){
        for(int col = 0 ; col<4 ; col++ ){
            cin>>arr[row][col] ;
        }
    }

    // Printing Array Element 
    cout<<"Array Element : "<<endl ;
    for(int row = 0 ; row<3 ; row++ ){
        for(int col = 0 ; col<4 ; col++ ){
            cout<<arr[row][col]<<" " ;
        }
        cout<<endl ;
    } 

    //Row Wise Sum : 
    RowWiseSum(arr,3,4) ;

    cout<<endl ;

    //column Wise Sum : 
    ColWiseSum(arr,3,4) ;
    cout<<endl ;

    // largest Row Sum :
    cout<<largestRowSum(arr,3,4) ;
    cout<<endl ;

    return 0 ;
}