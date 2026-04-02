// TC : O(N) , SC : O(26)==O(1)
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> freq(26,false ) ;

        for( char ch : s ){
            if( freq[ ch - 'a' ] )
                return ch ;
            freq[ch-'a'] = true ;
        }   
        return ' ' ;
    }
};