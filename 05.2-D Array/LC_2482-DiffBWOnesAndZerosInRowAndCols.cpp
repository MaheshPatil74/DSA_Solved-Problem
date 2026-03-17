// TC : O(M*N) , SC : O(M+N)
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<int> rowOnes(m,0) ;     //save number of one in each row
        vector<int> colOnes(n,0) ;     //save number of one in each column

        // Count ones in rows & columns (single traversal)
        for( int i = 0 ; i<m ; i++ )
            for( int j = 0 ; j<n ; j++ )
                if( grid[i][j] == 1 ){
                    rowOnes[i]++ ;
                    colOnes[j]++ ;
                }

        // Fill result
        for( int i = 0 ; i<m ; i++ )
            for( int j = 0 ; j<n ; j++ )
                grid[i][j] = (rowOnes[i]) + (colOnes[j]) - (m-rowOnes[i]) - (n-colOnes[j]) ;

        return grid ;
    }
};