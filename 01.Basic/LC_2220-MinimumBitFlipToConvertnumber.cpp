// TC : O(32) , SC : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0 ;

        while( start != 0 || goal != 0 ){
            int bitStart = start&1 ;
            int bitGoal = goal&1 ;

            if( bitStart != bitGoal )
                count++ ;

            start >>= 1 ;
            goal >>= 1 ;
        }

        return count ;
    }
};