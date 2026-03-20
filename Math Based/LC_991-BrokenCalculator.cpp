// Approach 1 : greedy
// TC : O( Log(target) ) , SC : O(1)
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0 ;
        if( startValue>=target)
            return startValue-target ;

        while( target > startValue ){
            if( target%2 == 0 )
                target /= 2 ;
            else
                target += 1 ;
            cnt++ ;
        }   
        if( startValue>target )
            cnt += (startValue-target) ;

        return cnt ;
    }
};