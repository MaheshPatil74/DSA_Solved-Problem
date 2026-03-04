// Approach 2 : using vector as Stack
// TC : O(N) , SC : O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st ;
        st.reserve(tokens.size()) ;

        for( string ch : tokens ){
            if( ch == "+" || ch == "-" || ch == "*" || ch == "/" ){
                int secondOp = st.back() ;   st.pop_back() ;
                int firstOp = st.back() ;    st.pop_back() ;
                
                if( ch == "+" )
                    st.push_back(firstOp + secondOp) ;
                else if( ch == "-" )
                    st.push_back(firstOp - secondOp) ;
                else if( ch == "*" )
                    st.push_back(firstOp * secondOp) ;
                else if( ch == "/" )
                    st.push_back(firstOp / secondOp) ;
            }
            else{
                st.push_back( stoi(ch) ) ;
            }
        }
        return st.back() ;
    }
};


// Approach 1 : using Stack
// TC : O(N) , SC : O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st ;
        for( string ch : tokens ){
            if( ch == "+" || ch == "-" || ch == "*" || ch == "/" ){
                int secondOp = st.top() ;   st.pop() ;
                int firstOp = st.top() ;    st.pop() ;
                
                if( ch == "+" )
                    st.push(firstOp + secondOp) ;
                else if( ch == "-" )
                    st.push(firstOp - secondOp) ;
                else if( ch == "*" )
                    st.push(firstOp * secondOp) ;
                else if( ch == "/" )
                    st.push(firstOp / secondOp) ;
            }
            else{
                st.push( stoi(ch) ) ;
            }
        }
        return st.top() ;
    }
};
