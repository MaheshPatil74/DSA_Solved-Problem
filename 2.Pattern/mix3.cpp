#include<iostream>
using namespace std ;

void PrintMixSquare( int n ){

    for( int row = 1 ; row<=n ; row++ ){

        for( int space = 0 ; space <row-1 ; space++){
            cout<<" ";
        }
        for( int star = 1 ; star <=n-row+1 ; star++){
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