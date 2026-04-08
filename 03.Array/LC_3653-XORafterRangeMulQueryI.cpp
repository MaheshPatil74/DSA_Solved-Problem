// Approach 2 : space optimised
// TC : O( q * n )  ,   SC : O(1)
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        const int MOD=1e9+7;
        for(auto& q : queries){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            for(int idx=l;idx<=r;idx+=k)
                nums[idx]=(1LL*nums[idx] * v)%MOD;
        }
        int result=0;
        for(int x : nums) result^=x;

        return result;
    }
};






// Approach 1 : 
// TC : O( q * n )  ,   SC : O(n)
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7 ;
        int n = nums.size() ;

        // multiplier array
        vector<long long > mul(n,1) ;
        
        // Build Array 
        for( auto &q : queries){
            int l = q[0] , r = q[1] , k = q[2] , v = q[3] ;
            for( int i = l ; i<=r ; i+=k )
                mul[i] = (mul[i]*v) % MOD ; 
        }

        int ans = 0 ;
        for( int i = 0 ; i<n ; i++ ){
            nums[i] = ( nums[i] * mul[i] ) % MOD ;
            ans ^= nums[i] ;
        }
        return ans ;
    }
};