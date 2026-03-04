#include<iostream>
using namespace std ;

void PrintMix( int n ){

    for( int row = 1 ; row<=n ; row++ ){

        for( int data1 = 1 ; data1 <=n-row+1 ; data1++){
            cout<<data1;
        }

        for( int star = 0 ; star< ((2*row)-2)  ; star++){
            cout<<"*";
        }

        for( int data2 = n-row+1 ; data2 > 0 ; data2--){
            cout<< data2 ;
        }

        cout<<endl ;
    }
}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    PrintMix( num );

    return 0 ;
}

/*
Output :

Enter The N : 5
1234554321
1234**4321
123****321
12******21
1********1


*/