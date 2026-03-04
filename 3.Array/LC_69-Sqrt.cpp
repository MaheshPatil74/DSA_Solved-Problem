class Solution {
public:
    int mySqrt(int x) {

        int left = 0 ;
        int right = x ;
        long long int ans = -1 ;

        while( left <= right ){
            long long int mid = left + (right-left)/2 ;

            long long int sqr = mid * mid ;

            if( sqr == x ){
                return mid ;
            }
            else if( sqr < x ){
                ans = mid ;
                left = mid + 1 ;
            }
            else{
                right = mid-1 ;
            }
        }
        return ans ;
    }
};