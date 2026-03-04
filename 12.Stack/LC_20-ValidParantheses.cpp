// TC : O(N) , SC : O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;

        for( char ch : s ){
            if( ch=='(' || ch=='[' || ch=='{' )
                st.push(ch) ;
            else if( ch==')' || ch==']' || ch=='}' ){
                if( st.empty() )
                    return false ;
                else{
                    if( st.top() == '(' && ch==')' || 
                        st.top() == '{' && ch=='}' || 
                        st.top() == '[' && ch==']' )

                        st.pop() ;
                    else
                        return false ;
                }
            }
        }
        return st.empty() ;
    }
};
