// TC : O(N+M) , SC : O(1)
class Solution {
public:
    bool isGood( string& word , vector<int> freq ){
        for( char ch : word ){
            if( freq[ch-'a'] == 0 )
                return false ;
            freq[ch-'a']-- ;
        }
        return true ;
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0) ;
        for( char ch : chars )
            freq[ ch - 'a' ]++ ;

        int ans = 0 ;
        for( string word : words )
            if( isGood(word , freq) )
                ans += word.length() ;

        return ans ;
    }
};