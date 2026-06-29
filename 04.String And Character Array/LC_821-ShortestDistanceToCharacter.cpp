// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length() ;
        vector<int> ans(n,INT_MAX) ;

        int index = INT_MAX ;
        for( int i = 0 ; i<n ; i++ ){
            if( s[i] == c )
                index = i ;

            if( index != INT_MAX )
                ans[i] = abs(i-index) ;
        }

        index = INT_MAX ;
        for( int i = n-1 ; i>=0 ; i-- ){
            if( s[i] == c )
                index = i ;
            if( index != INT_MAX )
                ans[i] = min( ans[i] , abs(i-index) ) ;
        }
        return ans ;
    }
};