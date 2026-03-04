// Approach 1 : 
// Time Complexity: O(m + n*k)
// SC : O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0 ;

        vector<bool> present(26,false) ;
        for( char temp : allowed )
            present[ temp - 'a' ] = true ;

        for( string word : words ){
            int j = 0 ;
            while( j<word.length() ){
                if( present[ word[j] - 'a' ] == false )
                    break ;
                j++ ;
            }
            
            if( j == word.length() )
                ans++ ;
        }
        return ans ;
    }
};