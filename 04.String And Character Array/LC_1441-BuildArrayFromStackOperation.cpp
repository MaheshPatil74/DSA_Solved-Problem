// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans ;
        int i = 1 ;
        for( int idx = 0 ; idx<target.size() ; idx++ ){
            while( i<=n && target[idx] != i ){
                ans.push_back( "Push" );
                ans.push_back( "Pop" );
                i++ ;
            }
            ans.push_back( "Push" );
            i++ ;
        }
        return ans ;
    }
};