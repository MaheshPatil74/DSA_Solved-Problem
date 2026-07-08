// Approach 1 : TLE occured
// TC : O(N*q) , SC : O(1)
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7 ;
        vector<int> ans(queries.size());
        for(int k=0 ; k<queries.size() ; k++ ){
            int left = queries[k][0];
            int right = queries[k][1];
            
            long long sum = 0 ;
            long long num = 0 ;
            for( int i = left ; i <= right ; i++ ){
                if( s[i] != '0' ){
                    int d = s[i]-'0' ;  
                    num = (num*10 + d) % MOD ;
                    sum += d;
               }
            }
            ans[k] = ( (num%MOD)*(sum%MOD))%MOD ;   
        }
        return ans ;
    }
};