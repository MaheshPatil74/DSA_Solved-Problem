// Approach 1 : 
// TC : O(N) , SC : O(26 + 10) = O(1)
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> alphaFreq(26,0) ;
        vector<int> digitFreq(10,0) ;

        for( char ch : s ){
            if( ch >= '0' && ch <= '9' )
                digitFreq[ ch - '0' ]++  ;
            else
                alphaFreq[ ch - 'a' ]++ ;
        }

        int sum = 0 ;
        for( char ch : s ){
            if( ch >= '0' && ch <= '9' ){
                if( digitFreq[ch-'0'] == -1 )
                    continue ;
                int freqCh = digitFreq[ch-'0'] ;
                digitFreq[ch-'0'] = -1 ;
                char mirror = '9' - ( ch - '0' ) ;
                int mirrorFreq = digitFreq[mirror-'0'] ;
                digitFreq[mirror-'0'] = -1 ;
            }
            else{
                if( alphaFreq[ch-'a'] == -1 )
                    continue ;
                int freqCh = alphaFreq[ch-'a'] ;
                alphaFreq[ch-'a'] = -1 ;
                char mirror = 'z' - ( ch - 'a' ) ;
                int mirrorFreq = alphaFreq[mirror-'a'] ;
                alphaFreq[mirror-'a'] = -1 ;
            }
            sum += abs( freqCh - mirrorFreq ) ;
        }
        return sum ;
    }
};