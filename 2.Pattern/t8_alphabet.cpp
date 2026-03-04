#include<iostream>
using namespace std ;

void PrintWithoutExtraVariable( int n ){

    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=i ; j++ ){
            char ch = 'A'+i+j-2 ;   ////Only For TypeCasting
            cout<<ch<<" "; 
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
A 
B C
C D E
D E F G
E F G H I
*/