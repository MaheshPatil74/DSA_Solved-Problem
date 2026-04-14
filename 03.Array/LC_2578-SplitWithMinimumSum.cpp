// Approach 1 : Optimal using frequency vector
// TC : O(d) where d =Log(num)  , SC : O(1)
class Solution {
public:
    int splitNum(int num) {
        vector<int> freq( 10 , 0 ) ;
        int temp = num ;
        while( temp > 0 ){
            int d = temp % 10 ;
            freq[d]++ ;
            temp /= 10 ;
        }

        bool first = true ;
        long long num1 = 0 , num2 = 0 ;
        for( int i = 0 ; i<10 ; i++ ){
            int temp = freq[i] ;
            while( temp > 0 ){
                if( first )
                    num1 = (num1*10) + i ;
                else
                    num2 = ( num2*10 ) + i ;
                first = !first ;
                temp-- ;
            }
        }
        return ( num1 + num2 ) ;
    }
};