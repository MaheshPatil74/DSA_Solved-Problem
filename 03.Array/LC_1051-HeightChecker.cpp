// TC : O(N*LogN) , SC : O(N)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ans(heights) ;

        sort( ans.begin() , ans.end() ) ;

        int count = 0 ;
        for( int i = 0 ; i<ans.size() ; i++ )
            if( ans[i] != heights[i] )
                count++ ;
        return count ;
    }
};