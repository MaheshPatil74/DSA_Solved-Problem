// TC : O(N) , SC : O(1)
class Solution {
public:
    int maxScore(string s) {
        int n = s.length() ;
        int oneCount = 0 ;
        int maxScore = INT_MIN ;

        for( int i = 0 ; i<n ; i++ )
            if( s[i] == '1' )
                oneCount++ ;
            
        int leftScore = 0 ;
        int rightScore = oneCount ;
        for( int i = 0 ; i<n-1 ; i++ ){
            if( s[i] == '0' )
                leftScore += 1 ;
            else
                rightScore -= 1 ;
            maxScore = max( maxScore , leftScore + rightScore ) ;
        }
        return maxScore ;
    }
};