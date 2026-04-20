// Approach 1 :
// TC : O(N) , SC : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = 0 ;
        int n = colors.size() ;

        // Compare with left side
        for( int i = 0 ; i<n ; i++ )
            if( colors[i] != colors[n-1] ){
                maxi = max( maxi , n-1-i );
                break ;
            }

        // Compare with right side
        for( int i = n-1 ; i>=0 ; i-- )
            if( colors[i] != colors[0] ){
                maxi = max( maxi , i );
                break ;
            }

        return maxi ;
    }
};