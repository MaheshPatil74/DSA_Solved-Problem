#include<iostream>
using namespace std ;

void PrintUsingExtraVariable( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        int value = i ;
        for( int j = 1 ; j<=i ; j++ ){
            cout<<value<<" ";
            value++ ;
        }
        cout<<endl ;
    }
}
/*
Enter The N : 5
1 
2 3
3 4 5
4 5 6 7
5 6 7 8 9
*/

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    PrintUsingExtraVariable( num );

    return 0 ;
}

