#include<iostream>
using namespace std ;

void Print( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=i ; j++ ){
            cout<<"* ";
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
Enter The N : 5
* 
* *
* * *
* * * *
* * * * *
*/