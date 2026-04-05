// TC : O(N) , SC : O(26)==O(1)
class Solution {
public:
    int maxFreqSum(string s) {
        int maxVowelFreq = 0 ;
        int maxConsoFreq = 0 ;

        vector<int> freq(26,0);
        for( char ch : s ){
            freq[ch-'a']++ ;

            if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
                maxVowelFreq = max( maxVowelFreq , freq[ch-'a'] ) ;
            else
                maxConsoFreq = max( maxConsoFreq , freq[ch-'a'] ) ;
        }

        return ( maxVowelFreq + maxConsoFreq ) ;
    }
};