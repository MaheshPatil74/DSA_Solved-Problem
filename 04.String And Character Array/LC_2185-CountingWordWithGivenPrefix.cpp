// TC : O( N*M ) , SC: O(1)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0 ;
        for( string word : words ){
            int i = 0 ;
            while( i<pref.length() && i<word.length() ){
                if( pref[i] != word[i] )
                    break ;
                i++ ;
            }
            if( i == pref.length() )
                count++ ;
        }
        return count ;
    }
};