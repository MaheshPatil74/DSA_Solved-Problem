// Approach 4 : optimised space in approach 3
// TC : O(m*n) , SC : O(m*n) 

// Approach 3 : prefixSuffix approach after flatten matrix into array
// TC : O(m*n) , SC : O(m*n) 
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        int mod = 12345 ;

        int size = m*n ;
        vector<long long> arr(size) ;

        // step 1 : flatten grid
        int idx = 0 ;
        for( int i = 0 ; i<m ; i++ )
            for( int j = 0 ; j<n ; j++ )
                arr[idx++] = grid[i][j] ;

        // step 2 : prefix array
        vector<long long> prefix(size,1) ;
        for( int i = 1 ; i<size ; i++ )
            prefix[i] = ( prefix[i-1] * arr[i-1] ) % mod ;

        // step 3 : suffix array
        vector<long long> suffix(size,1) ;
        for( int i = size-2 ; i>=0 ; i-- )
            suffix[i] = ( suffix[i+1] * arr[i+1] ) % mod ;

        // step 4 : result
        idx = 0 ;
        for( int i = 0 ; i<m ; i++ ){
            for( int j = 0 ; j<n ; j++ ){
                grid[i][j] = ( prefix[idx] * suffix[idx] ) % mod ;
                idx++ ;
            }
        }
        return grid ;
    }
};



// Approach 1 : Counting zero Approach
// Wrong solution as mod is not prime here
// TC : O(m*n) , SC : O(1) 
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        int mod = 12345 ;

        int countZero = 0 ;
        long long totalProduct = 1 ;
        for( int i = 0 ; i<grid.size() ; i++ )
            for( int j = 0 ; j<grid[0].size() ; j++ ){
                if( grid[i][j] == 0 )
                    countZero++ ;
                else
                    totalProduct = (totalProduct * grid[i][j]) % mod ;
            }

        if( countZero == 0 ){
            for( int i = 0 ; i<grid.size() ; i++ )
                for( int j = 0 ; j<grid[0].size() ; j++ )
                    grid[i][j] = (totalProduct/grid[i][j]) % mod ;
        }
        else if( countZero == 1 ){
            for( int i = 0 ; i<grid.size() ; i++ )
                for( int j = 0 ; j<grid[0].size() ; j++ ){
                    if( grid[i][j] == 0 )
                        grid[i][j] = totalProduct ;
                    else
                        grid[i][j] = 0 ;
                }
        }
        else if( countZero > 1 ){
            for( int i = 0 ; i<grid.size() ; i++ )
                for( int j = 0 ; j<grid[0].size() ; j++ )
                    grid[i][j] = 0 ;
        }
        return grid ;
    }
};