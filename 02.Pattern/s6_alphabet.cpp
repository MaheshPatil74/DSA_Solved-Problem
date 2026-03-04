#include<iostream>
using namespace std ;

void PrintUsingExtraVariable( int n ){
    char start = 'A' ;
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
            cout<<start<<" "; 
        }
        start++ ;
        cout<<endl ;
    }
}

void PrintWithoutExtraVariable( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
            char ch = 'A'+i-1 ; //Only For TypeCasting
            cout<<ch<<" "; 
        }
        cout<<endl ;
    }
}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    // PrintUsingExtraVariable( num );
    PrintWithoutExtraVariable( num ) ;
    return 0 ;
}

/*
Output :
Enter The N : 5
A A A A A 
B B B B B
C C C C C
D D D D D
E E E E E
*/