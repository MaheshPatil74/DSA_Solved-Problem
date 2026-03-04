#include<iostream>
using namespace std ;

void Print( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
            cout<<n-j+1<<" ";
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
5 4 3 2 1 
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
*/