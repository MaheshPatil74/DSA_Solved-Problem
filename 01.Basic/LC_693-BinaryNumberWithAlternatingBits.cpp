// TC : O(32) == O(1) , SC : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastbit = n&1 ;
        n = n>>1 ;

        while(n){
            int temp = n&1 ;
            if( temp == lastbit )
                return false ;
            lastbit = temp ;
            n = n>>1 ;
        }
        return true ;
    }
};