#include<iostream>
using namespace std ;

void Print( int n ){
    int p = 1 ; 
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=i ; j++ ){
            cout<<p<<" ";
            p++ ;
        }
        cout<<endl ;
    }

}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    Print( num );

    return 0 ;
}

/*
Output :
Enter The N : 5
1 
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/