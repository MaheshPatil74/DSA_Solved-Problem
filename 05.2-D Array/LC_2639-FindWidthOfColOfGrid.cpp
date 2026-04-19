// Approach 2 : More Optimal using string
// TC : O(M*N) , SC : O(1)
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m, 0);
        
        for(int j = 0; j < m; j++) {
            int maxWidth = 0;
            
            for(int i = 0; i < n; i++) {
                int len = to_string(grid[i][j]).size();
                maxWidth = max(maxWidth, len);
            }
            
            ans[j] = maxWidth;
        }
        
        return ans;
    }
};

// Approach 1 :
// TC : O(M*N) , SC : O(1)
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        vector<int> res(n,-1) ;

        for( int i = 0 ; i<m ; i++ ){
            for( int j = 0 ; j<n ; j++ ){
                int num = grid[i][j] ;
                int len = 0 ;
                if( num < 0 ){
                    num = -num ;
                    len++ ;
                }

                if( num == 0 )
                    len = 1 ;

                while( num > 0 ){
                    len++ ;
                    num /= 10 ;
                }
                res[j] = max( res[j] , len ) ;
            }
        }
        return res ;
    }
};