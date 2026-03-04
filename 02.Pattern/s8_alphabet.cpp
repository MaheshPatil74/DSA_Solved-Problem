#include<iostream>
using namespace std ;

void PrintUsingExtraVariable( int n ){
    char start = 'A' ;
    for( int i = 1 ; i<=n ; i++ ){
        
        for( int j = 1 ; j<=n ; j++ ){
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

    PrintUsingExtraVariable( num );
    return 0 ;
}

/*
Output :
Enter The N : 5
A B C D E 
F G H I J
K L M N O
P Q R S T
U V W X Y
*/