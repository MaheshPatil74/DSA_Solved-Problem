// TC : O(N*N*N) , SC : O()
class Solution {
private : 
    bool isPalindrome( string& s , int start , int end ){
        while( start<end ){
            if( s[start] != s[end] )
                return false ;
            start++ ;
            end-- ;
        }
        return true ;
    }
public:
    string longestPalindrome(string s) {
        string ans = "" ;
        for( int start = 0 ; start<s.length() ; start++ )
            for( int end = start ; end<s.length() ; end++ )
                if( isPalindrome( s , start , end ) )
                    if( end-start+1 > ans.size() )
                        ans = s.substr(start,end-start+1) ;
        return ans ;
    }
};