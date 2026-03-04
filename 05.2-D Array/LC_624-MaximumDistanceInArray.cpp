// Approach 1 :
// TC : O(N)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int maxi = arr[0].back() ;
        int mini = arr[0][0] ;

        int result = 0 ;
        
        for( int i = 1 ; i<arr.size() ; i++ ){
            int currentMinElement = arr[i][0] ;
            int currentMaxElement = arr[i].back() ;

            result = max({
                result,
                abs( currentMaxElement - mini ),
                abs( currentMinElement - maxi )
            });

            maxi = max( maxi , currentMaxElement );
            mini = min( mini , currentMinElement );
        }
        return result ;
    }
};
