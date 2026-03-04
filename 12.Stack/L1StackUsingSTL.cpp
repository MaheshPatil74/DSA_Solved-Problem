#include<iostream>
#include<stack>
using namespace std ;

int main(){

    // Creating a stack ;
    stack<int> s ;

    // Checking intially stack size
    cout<< s.size() <<endl ;

    // check stack is empty or not
    cout<< s.empty() <<endl ;

    // Pushing element in stack 
    s.push( 2 ) ;
    s.push( 3 ) ;
    s.push( 4 ) ;
    s.push( 5 ) ;

    cout<< s.size() <<endl ;

    // get top element in stack
    cout<< s.top() <<endl ;

    // Poppping out element 
    s.pop() ;

    cout<< s.size() <<endl ;
    cout<< s.top() <<endl ;
    cout<< s.empty() <<endl ;
}