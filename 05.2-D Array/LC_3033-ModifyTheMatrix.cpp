// TC : O(M*N) , SC : O(N)
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int> colMax(matrix[0].size(),0) ;

        for( int j = 0 ; j<matrix[0].size() ; j++ )
            for( int i = 0 ; i<matrix.size() ; i++ )
                colMax[j] = max( colMax[j] , matrix[i][j] ) ;

        for( int i = 0 ; i<matrix.size() ; i++ )
            for( int j = 0 ; j<matrix[0].size() ; j++ )
                if( matrix[i][j] == -1 )
                    matrix[i][j] = colMax[j] ;

        return matrix ;
    }
};