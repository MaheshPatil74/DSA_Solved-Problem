// Approach 1 : optimal Using frequency Array
// TC : O(n) , SC : O(1)
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0) ;
        for( char temp : s )
            freq[ temp - 'a' ]++ ;

        int oddMax = INT_MIN ;
        int evenMin = INT_MAX ;
        for( int i = 0 ; i<26 ; i++ ){
            if( freq[i] == 0 )
                continue ;
            if( freq[i] % 2 )
                oddMax = max( oddMax , freq[i] ) ;
            else
                evenMin = min( evenMin , freq[i] ) ;
        }
        return oddMax - evenMin ;
    }
};