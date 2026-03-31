// Approach 2 : using frequency vector
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        for( int i = 0 ; i<n ; i++ ){
            vector<bool> row(n+1 , false );
            vector<bool> col(n+1 , false );
            for( int j = 0 ; j<n ; j++ ){
                int r = matrix[i][j] ;
                int c = matrix[j][i] ;
                if( row[r] || col[c] )
                    return false ;
                row[r] = true ;
                col[c] = true ; 
            }      
        } 
        return true ;
    }
};



// Approach 1 : using set
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size() ;

        for( int i = 0 ; i<n ; i++ ){
            unordered_set<int> set ;
            for( int j = 0 ; j<n ; j++ )
                set.insert(matrix[i][j]) ;
            if( set.size() != n )
                return false ;
        } 

        for( int j = 0 ; j<n ; j++ ){
            unordered_set<int> set ;
            for( int i = 0 ; i<n ; i++ )
                set.insert(matrix[i][j]) ;
            if( set.size() != n )
                return false ;
        } 

        return true ;
    }
};