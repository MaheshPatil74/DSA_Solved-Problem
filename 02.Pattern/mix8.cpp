#include<iostream>
using namespace std ;

void PrintMixSquare( int n ){

    for( int row = 1 ; row<=n ; row++ ){

        for( int space = n-row ; space > 0 ; space--){
            cout<<" ";
        }

        for( int data1 = 1 ; data1 <=row ; data1++){
            cout<<data1;
        }
        int value = row-1 ;
        for( int data2 = 1 ; data2 <=row-1 ; data2++){
            cout<< value ;
            value-- ;
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
   1
  121
 12321
1234321

*/