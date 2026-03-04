// Time: O(N + M) 
// Space: O(1) ==> constant size array
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26,0) ;

        for( char temp : s )
            alpha[ temp - 'a' ]++ ;

        for( char temp : t )
                alpha[ temp - 'a' ]-- ;

        for( int i = 0 ; i<26 ; i++ )
            if( alpha[i] != 0 )
                return false ;
        
        return true ;
    }
};
