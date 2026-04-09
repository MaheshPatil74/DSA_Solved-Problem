// Approach 1 : 
// TC : O( LogN ) , SC : O(1)
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10,0) ;
        while( n > 0 ){
            freq[ n%10 ]++ ;
            n /= 10 ;
        }

        int minFreq = INT_MAX ;
        int minFreqDigit = INT_MAX ;
        for( int i = 0 ; i<10 ; i++ )
            if( freq[i] > 0 )
                if( freq[i] < minFreq ){
                    minFreq = freq[i] ;
                    minFreqDigit = i ; 
                }

        return minFreqDigit ;
    }
};