// Approach 2 : using XOR ==>> more Optimal
// TC : O(32) == O(1) , SC : O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y ;
        int count = 0 ;
        while( num ){
            count += ( num&1 ) ;
            num = num >> 1 ;
        }
        return count ;
    }
};


// Approach 1 :
// TC : O(32) == O(1) , SC : O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0 ;

        while( x!=0 || y!=0 ){
            int bitX = x&1 ;
            int bitY = y&1 ;

            if( bitX != bitY )
                count++ ;

            x = x >> 1 ;
            y = y >> 1 ;
        }
        return count ;
    }
};