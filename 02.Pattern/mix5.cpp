#include<iostream>
using namespace std ;

void PrintMixSquare( int n ){

    for( int row = 1 ; row<=n ; row++ ){

        for( int space = n-row ; space > 0 ; space--){
            cout<<" ";
        }
        for( int data = 1 ; data <=row ; data++){
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
    1
   22
  333
 4444
55555

*/