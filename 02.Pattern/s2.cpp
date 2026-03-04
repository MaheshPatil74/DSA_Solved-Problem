#include<iostream>
using namespace std ;

void Print( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
            cout<<i<<" ";
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
1 1 1 1 1 
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
*/