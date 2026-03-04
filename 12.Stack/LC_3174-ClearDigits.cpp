// Approach 2 : Modify Original String act as Stack pointer
// TC : O(N) , SC : O(1)
class Solution {
public:
    string clearDigits(string s) {
        int top = 0 ;
        for( int i = 0 ; i<s.size() ; i++ ){
            if( s[i] >= '0' && s[i]<='9' ){
                if( top>0 )
                    top-- ;
            }
            else{
                s[top++] = s[i] ;
            }
        }   
        return s.substr(0,top) ;
    }
};



// Approach 1 : Using Extra string and behave it as Stack
// TC : O(N) , SC : O(N)
class Solution {
public:
    string clearDigits(string s) {
        string ans ;
        for( char ch : s ){
            if( ch >= '0' && ch<='9' ){
                if( !ans.empty() )
                    ans.pop_back() ;
            }
            else
                ans.push_back(ch) ;
        }
        return ans ;
    }
};