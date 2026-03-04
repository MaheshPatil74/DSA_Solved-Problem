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

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve( myStack , x ) ;
    return myStack ;
}

void reverseStack(stack<int> &stack) {
    // base case ;
    if( stack.empty() )
        return ;

    int temp = stack.top() ;
    stack.pop() ;

    // recursive call
    reverseStack( stack ) ;
    pushAtBottom( stack , temp );
}