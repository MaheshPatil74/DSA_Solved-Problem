// TC : O(N*N) , SC : O(N*N)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n)) ;
        int startingRow = 0 ;
        int endingRow = n-1 ;
        int startingCol = 0 ;
        int endingCol = n-1 ;

        int count = 1 ;
        while( count <= n*n ){
            // Process first row
            for( int i = startingCol ; i<=endingCol ; i++ )
                res[startingRow][i] = count++ ;
            startingRow++ ;

            // process last column
            for( int i = startingRow ; i<=endingRow ; i++ )
                res[i][endingCol] = count++ ;
            endingCol-- ;

            // process Last row
            for( int i = endingCol ; i>=startingCol ; i-- )
                res[endingRow][i] = count++ ;
            endingRow-- ;

            // process first column
            for( int i = endingRow ; i>=startingRow ; i-- )
                res[i][startingCol] = count++ ;
            startingCol++ ;
        }
        return res;
    }
};