// TC : O(N) , SC : O(1)
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int earlyEnd = INT_MAX ;
        for( int i = 0 ; i<tasks.size() ; i++ ){
            int end = tasks[i][0] + tasks[i][1] ;
            earlyEnd = min( earlyEnd , end ) ;
        }
        return earlyEnd ;
    }
};