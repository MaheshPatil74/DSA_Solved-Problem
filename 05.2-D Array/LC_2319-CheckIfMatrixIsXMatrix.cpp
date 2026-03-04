// TC : O(N*N) , SC : O(1)
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int rows = grid.size() ;
        int cols = grid[0].size() ;

        for( int row = 0 ; row<rows ; row++ )
            for( int col = 0 ; col < cols ; col++ ){
                if( row == col || row+col == rows-1 )
                    if( grid[row][col] == 0 )
                        return false ;
                else
                    if( grid[row][col] != 0 )
                        return false ;
            }
        return true ;
    }
};