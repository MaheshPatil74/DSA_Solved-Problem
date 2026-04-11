// TC : O(d) , SC : O(1)
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0 ;
        for( int num : nums ){
            while( num > 0 ){
                int d = num % 10 ;
                if( d == digit )
                    count++ ;
                num /= 10 ;
            }
        }
        return count ;
    }
};