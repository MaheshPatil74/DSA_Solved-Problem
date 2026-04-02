// TC : O(M*N) , SC : O(1)
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int minIndex = INT_MAX ;
        int maxCount = INT_MIN ;

        for( int i = 0 ; i<mat.size() ; i++ ){
            int count = 0 ;
            for( int j = 0 ; j<mat[0].size() ; j++ ){
                if( mat[i][j] == 1 )
                    count++ ;
            }

            if( count > maxCount ){
                maxCount = count ;
                minIndex = i ;
            }
        }
        return { minIndex , maxCount };
    }
};