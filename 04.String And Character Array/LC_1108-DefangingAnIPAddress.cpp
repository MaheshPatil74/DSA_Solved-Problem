
// Approach 1 : Using Extra String
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.length() ;
        string ans = "";
        int i = 0 ;
        while( i<n ){
            if( address[i] == '.' )
                ans += "[.]" ;
            else
                ans += address[i] ;
            i++ ;
        }
        return ans ;
    }
};