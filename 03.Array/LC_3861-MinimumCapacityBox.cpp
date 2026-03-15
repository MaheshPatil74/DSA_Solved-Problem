// TC : O(N) , SC : O(1)
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ansIndex = -1 ;
        int minDiff = INT_MAX ;
        for( int i = 0 ; i<capacity.size() ; i++ ){
            int currDiff = capacity[i] - itemSize ;
            if( currDiff>=0 && currDiff < minDiff ){
                ansIndex = i ;
                minDiff = currDiff ;
            }
        }

        return ansIndex ;
    }
};