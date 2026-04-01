// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans ;
        int low = 0 ;
        int high = s.size() ;

        for( char ch : s ){
            if( ch == 'I' )
                ans.push_back( low++ ) ;
            else
                ans.push_back( high-- ) ;
        }
        ans.push_back( low++ ) ;
        return ans ;
    }
};