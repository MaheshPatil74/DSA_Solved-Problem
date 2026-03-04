// Approach 2 : same as 1 only some optimisations 
// TC : O( M*N )  ,  SC : O( M+N )
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows( mat.size() , 0) ;
        vector<int> cols(mat[0].size() , 0) ;

        for( int i = 0 ; i<mat.size() ; i++ )
            for( int j = 0 ; j<mat[i].size() ; j++ )
                if( mat[i][j] == 1 ){
                    rows[i]++ ;
                    cols[j]++ ;
                }

        int count = 0 ;
        for( int i = 0 ; i<mat.size() ; i++ ){
            if( rows[i] == 1 ){
                for( int j = 0 ; j<mat[i].size() ; j++ ){
                    if( mat[i][j] == 1  && cols[j]==1 ){
                        count++ ;
                        break ;     // row already processed
                    }
                }
            }
        }

        return count ;
    }
};


// Approach 1 : 
// TC : O( M*N )  ,  SC : O( M+N )
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // Array to store number of 1's is particular row and column
        vector<int> rows( mat.size()) ;
        vector<int> cols(mat[0].size()) ;

        // Fill the arrays 
        for( int i = 0 ; i<mat.size() ; i++ )
            for( int j = 0 ; j<mat[i].size() ; j++ )
                if( mat[i][j] == 1 ){
                    rows[i]++ ;
                    cols[j]++ ;
                }

        // check for special positions
        int count = 0 ;
        for( int i = 0 ; i<mat.size() ; i++ )
            for( int j = 0 ; j<mat[i].size() ; j++ )
                if( mat[i][j] == 1 && rows[i]==1 && cols[j]==1 )
                    count++ ;
        return count ;
    }
};