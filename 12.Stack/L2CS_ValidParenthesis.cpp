bool isValidParenthesis(string s){
    stack<char> Stack ;
    for( int i = 0 ; i<s.length() ; i++ ){
        char ch = s[i] ;
        // If Opening bracket , Push in stack
        // If Closing bracket , check top and pop from stack
        if( ch == '(' || ch == '{' || ch == '[' )
            Stack.push(ch) ;
        else{
            // closing bracket
            if( !Stack.empty() ){
                char top = Stack.top() ;
                if( ( ch==')' && top=='(' ) || ( ch==']' && top=='[' ) || ( ch=='}' && top=='{' ) )
                    Stack.pop() ;
                else
                    return false ;
            }
            else
                return false ;
        }
    }
    return Stack.empty() ;
}