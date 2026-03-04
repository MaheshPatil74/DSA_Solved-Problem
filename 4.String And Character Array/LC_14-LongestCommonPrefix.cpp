class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort( strs.begin() , strs.end() );
        int n = strs.size() ;
        string first = strs[0] ;
        string last = strs[n-1] ;

        string ans = "" ;
        int i = 0 ;
        int j = 0 ;
        while( i<first.length() && j<last.length() ){
            if( first[i] != last[j] ){
                return ans ;
            }
            ans += first[i] ;
            i++ ;
            j++;
        }
        return ans ;
    }
};