#include <bits/stdc++.h> 

void solve( stack<int>& myStack, int x ){
    // Base Case
    if( myStack.empty() ){
        myStack.push(x) ;
        return ;
    }

    int temp = myStack.top() ;
    myStack.pop() ;

    // Recursive Call
    solve( myStack , x ) ;

    myStack.push( temp ) ;
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve( myStack , x ) ;
    return myStack ;
}
