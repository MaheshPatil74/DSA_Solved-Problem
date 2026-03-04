// Approach 2 : Modify Original String act as Stack Pointer 
// TC : O(N) , SC : O(1)
class Solution {
public:
    string removeStars(string s) {
        int top = 0 ;
        for( int i = 0 ; i<s.length() ; i++ ){
            if( s[i] == '*' )
                top-- ;
            else
                s[top++] = s[i] ;
        }   
        return s.substr(0,top);
    }
};




// Approach 1 : Using string and behaave it as stack 
// TC : O(N) , SC : O(N)
class Solution {
public:
    string removeStars(string s) {
        string ans ;
        for(char ch : s ){
            if( ch == '*' ){
                if( !ans.empty() )
                    ans.pop_back() ;
            }
            else
                ans.push_back(ch) ;
        }
        return ans ;
    }
};