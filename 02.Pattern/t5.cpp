#include<iostream>
using namespace std ;

void PrintUsingExtraVariable( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        int value = i ;
        for( int j = 1 ; j<=i ; j++ ){
            cout<<value<<" ";
            value-- ;
        }
        cout<<endl ;
    }
}

void PrintWithoutExtraVariable( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        
        for( int j = 1 ; j<=i ; j++ ){
            
            cout<<i-j+1<<" ";
            
        }
        cout<<endl ;
    }
}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    //PrintUsingExtraVariable( num );
    PrintWithoutExtraVariable( num );

    return 0 ;
}
/*
Enter The N : 5
1 
2 1
3 2 1
4 3 2 1
5 4 3 2 1
*/
