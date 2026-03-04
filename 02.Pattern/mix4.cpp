#include<iostream>
using namespace std ;

void PrintMixSquare( int n ){

    for( int row = 1 ; row<=n ; row++ ){

        for( int space = 0 ; space <row-1 ; space++){
            cout<<" ";
        }
        for( int data = 1 ; data <=n-row+1 ; data++){
            cout<<row;
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

Enter The N : 5
11111
 2222
  333
   44
    5
   
*/