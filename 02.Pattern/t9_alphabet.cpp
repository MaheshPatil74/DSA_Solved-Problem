#include<iostream>
using namespace std ;

void PrintWithoutExtraVariable( int n ){

    for( int i = 1 ; i<=n ; i++ ){
        char start = 'A'+n-i ; 
        for( int j = 1 ; j<=i ; j++ ){
            cout<<start<<" "; 
            start++ ;
        }
        cout<<endl ;
    }
}

int main(){
    int num ;
    cout<<"Enter The N : ";
    cin>> num ;

    PrintWithoutExtraVariable( num ) ;
    return 0 ;
}

/*
Output :
Enter The N : 5
E 
D E
C D E
B C D E
A B C D E
*/