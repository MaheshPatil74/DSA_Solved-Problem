class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ;

        // Step 1 : transpose of matrix
        for( int i = 0 ; i<n ; i++ )
            for( int j = i ; j<n ; j++ )
                swap( matrix[i][j] , matrix[j][i] );

        // step 2 : reverse each row
        for( int i = 0 ; i<n ; i++ ){
            int l = 0 ;
            int r = n-1 ;
            while( l<r )
                swap( matrix[i][l++] , matrix[i][r--] );
        }
    }
};