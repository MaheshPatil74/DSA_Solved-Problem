// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;

        for (int num : nums) {
            if (num == 0) return 0;
            if (num < 0) sign = -sign;
        }
        return sign;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
private : 
    int signFunc( int x ){
        if( x>0 )
            return 1 ;
        else if( x<0 )
            return -1 ;
        else
            return 0 ;
    }
public:
    int arraySign(vector<int>& nums) {
        int count = 0  ;

        for( int num : nums ){
            if( num < 0 )
                count++ ;
            else if( num == 0 )
                return signFunc(0) ;
        }

        if( count%2 )   return signFunc(-1);
        return signFunc(1) ;
    }
};