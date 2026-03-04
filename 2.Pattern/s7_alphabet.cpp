#include<iostream>
using namespace std ;

void PrintUsingExtraVariable( int n ){
    
    for( int i = 1 ; i<=n ; i++ ){
        char start = 'A' ;
        for( int j = 1 ; j<=n ; j++ ){
            cout<<start<<" "; 
            start++ ;
        }
        
        cout<<endl ;
    }
}

void PrintWithoutExtraVariable( int n ){
    for( int i = 1 ; i<=n ; i++ ){
        for( int j = 1 ; j<=n ; j++ ){
            char ch = 'A'+j-1 ; ////Only For TypeCasting
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
A B C D E 
A B C D E
A B C D E
A B C D E
A B C D E
*/