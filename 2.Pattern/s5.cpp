#include<iostream>
using namespace std ;

void Print( int n ){
    int p = 1 ; 
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
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
Enter The N : 3
1 2 3 
4 5 6
7 8 9
*/