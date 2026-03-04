// TC : O(N)
class Solution {
public:
    bool isBalanced(string num) {
        
        int evenSum = 0 ;
        int oddSum = 0 ;

        for( int i = 0 ; i<num.length() ; i++ ){
            if( i%2 )  //odd
                oddSum += ( num[i] - '0' ) ;
            else
                evenSum += ( num[i] - '0' ) ;
        }
        return evenSum == oddSum ;
    }
};