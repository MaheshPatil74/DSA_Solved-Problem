// Approach 2 : optimal ==> no matrix modify
// Directly check all 4 rotation conditions mathematically
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n  = mat.size() ;
        bool rot0 = true , rot90 = true , rot180 = true , rot270 = true ;
        
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j<n ; j++ ){
                if( rot0 && mat[i][j] != target[i][j] ) rot0 = false ;
                if( rot90 && mat[i][j] != target[j][n-i-1] ) rot90 = false ;
                if( rot180 && mat[i][j] != target[n-i-1][n-j-1] ) rot180 = false ;
                if( rot270 && mat[i][j] != target[n-j-1][i] ) rot270 = false ;
            }

        return rot0 || rot90 || rot180 || rot270 ;
    }
};



// Approach 1 : Brute force
// Idea ==>> rotate 4 time and each time compare with target
// TC : O(N*N) , SC : O(N*N)
class Solution {
public:
    void rotate( vector<vector<int>>& mat ){
        int n  = mat.size() ;
        vector<vector<int>> temp( n , vector<int>(n) );

        for( int i = 0 ; i<n ; i++ )
            for( int j = 0 ; j<n ; j++ )
                temp[j][n-i-1] = mat[i][j] ;

        mat = temp ;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for( int i = 0 ; i<4 ; i++ ){
            if( mat == target )
                return true ;
            rotate(mat) ;
        }
        return false ;
    }
};