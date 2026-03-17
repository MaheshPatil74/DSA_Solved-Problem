// Approach 1 : two traversal
// TC : O(N) , SC : O(26)==O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0) ;

        for( char ch : s )
            freq[ ch - 'a' ]++ ;

        int ansIndex = -1 ;
        for( int i = s.length()-1 ; i>=0 ; i-- ){
            if( freq[ s[i] - 'a' ] == 1 )
                ansIndex = i ;
        }
        return ansIndex ;
    }
};