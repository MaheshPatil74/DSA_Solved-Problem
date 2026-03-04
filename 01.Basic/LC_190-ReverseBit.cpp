// Approach 2 : Optimal 
// TC : O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0 ;
        for( int i = 0 ; i<32 ; i++ ){
            ans = (ans<<1) + (n&1) ;
            n = n>>1 ;
        }
        return ans ;
    }
};



// Approach 1 : Iterative but lengthy
// TC : O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int count = 0 ;
        uint32_t ans = 0 ;

        while( n != 0 ){
            int lastBit = n&1 ;
            ans = (ans<<1) + lastBit ;
            count++ ;
            n = n>>1 ;
        }
        int rem = 32-count ;
        for( int i = 0 ; i<rem ; i++ )
            ans =  ans<<1 ;
        return ans ;
    }
};
