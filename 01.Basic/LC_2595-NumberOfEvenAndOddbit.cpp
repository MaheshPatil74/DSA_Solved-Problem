// TC : O(Log32) == O(1) , SC : O(1)
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0 , odd = 0 , idx = 0 ;
        while( n ){
            if( n&1 ){
                if( idx&1 )
                    odd++ ;
                else
                    even++ ;
            }
            n = n>>1 ;
            idx++ ;
        }

        return {even,odd} ;
    }
};