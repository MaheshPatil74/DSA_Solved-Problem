// Approach 2 : Optimal
// TC : O(N)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int sum = 0 ;
        for( int i = 0 ; i<n ; i++ )
            sum += mat[i][i] + mat[i][n-i-1] ;

        if( n%2 )
            sum -= mat[n/2][n/2] ;

        return sum ;
    }
};

// Approach 1 : Brute Force
// TC : O(N*N)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int sum = 0 ;
        for( int i = 0 ; i<n ; i++ )
            for( int j = 0 ; j<n ; j++ )
                if( ( i == j ) || ( i+j == n-1 ) )
                    sum += mat[i][j] ;
        return sum ;
    }
};