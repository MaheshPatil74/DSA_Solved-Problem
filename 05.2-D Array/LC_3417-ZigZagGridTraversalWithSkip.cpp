class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<int> ans ;

        bool leftToRight = true ;
        bool take = true ;

        for( int i = 0 ; i<m ; i++ ){
            for( int j = 0 ; j<n ; j++ ){
                int idx = leftToRight ? j : n-j-1 ;
                if( take )
                    ans.push_back( grid[i][idx] ) ;
                take = !take ;
            }
            leftToRight = !leftToRight ;
        }
        return ans ;
    }
};