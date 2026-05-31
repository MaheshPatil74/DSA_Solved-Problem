// TC : O(d) , SC : O(1)
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq( 10 , 0 ) ;

        int num = n ;
        while( num > 0 ){
            int lastDigit = num%10 ;
            freq[lastDigit]++ ;
            num /= 10 ;
        }

        long long score = 0 ;
        for( int i = 0 ; i<10 ; i++ )
            score += ( i*freq[i] ) ;
            
        return score ;
    }
};