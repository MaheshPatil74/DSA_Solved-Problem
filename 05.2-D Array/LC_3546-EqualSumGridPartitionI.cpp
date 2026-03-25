// TC : O(N*N) , SC : O(1)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0 ;
        for( int i = 0 ; i<grid.size() ; i++ )
            for( int j = 0 ; j<grid[0].size() ; j++ )
                totalSum += grid[i][j] ;
        if( totalSum %2 )
            return false ;

        long long rowSum = 0 ;
        for( int i = 0 ; i<grid.size() ; i++ )
            for( int j = 0 ; j<grid[0].size() ; j++ ){
                rowSum += grid[i][j] ;
                if( 2* rowSum == totalSum )
                    return true ;
            }

        long long colSum = 0 ;
        for( int j = 0 ; j<grid[0].size() ; j++ )
            for( int i = 0 ; i<grid.size() ; i++ ){
                colSum += grid[i][j] ;
                if( 2* colSum == totalSum )
                    return true ;
            }

        return false ;
    }
};