#include<iostream>
#include<stack>

using namespace std ;

int main(){
    string str = "Mahesh" ;
    cout<<"Initial : "<< str <<endl ;
    stack<char> s ;
    for( int i = 0 ; i<str.length() ; i++ )
        s.push( str[i] ) ;

    for( int i = 0 ; i<str.length() ; i++ ){
        str[i] = s.top() ;
        s.pop() ;
    }
    cout<<"Final : "<<str<<endl ;
    return 0 ;
}