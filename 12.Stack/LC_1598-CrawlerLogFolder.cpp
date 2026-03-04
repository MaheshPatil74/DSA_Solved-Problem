// Approach 2 : Optimal
// TC : O(N) , SC : O(1)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0 ;
        for( string log : logs ){
            if( log == "../" ){
                if( depth>0 )
                    depth-- ;
            }
            else if( log != "./" )
                depth++ ;
        }
        return depth ;
    }
};


// Approach 1 : Using Stack
// TC : O(N) , SC : O(N)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s ;

        for( string log : logs ){
            if( log == "./" )
                continue ;
            else if( log == "../" ){
                if( !s.empty() )
                    s.pop() ;
            }
            else
                s.push(log) ;
        }
        return s.size() ;
    }
};