#include<iostream>
using namespace std ;

void PrintMixSquare( int n ){

    for( int row = 1 ; row<=n ; row++ ){

        for( int space = n-row+1 ; space > 0 ; space--){
            cout<<"*";
        }
        cout<<endl ;
    }
}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    PrintMixSquare( num );

    return 0 ;
}

/*
Output : 
Enter The N : 4
****
***
**
*

*/