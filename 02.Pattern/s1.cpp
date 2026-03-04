#include<iostream>
using namespace std ;

void PrintSquare( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
            cout<<"* ";
        }
        cout<<endl ;
    }

}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    PrintSquare( num );

    return 0 ;
}

/*
Output : 
Enter The N : 5
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
*/