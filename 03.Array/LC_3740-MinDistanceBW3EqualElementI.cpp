// Approach 2 : Optimal
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        // store indices
        for (int i = 0; i < nums.size(); i++) 
            mp[nums[i]].push_back(i);

        int ans = INT_MAX;
        for (auto &it : mp) {
            vector<int> &v = it.second;
            if (v.size() < 3) continue;
            for (int i = 0; i + 2 < v.size(); i++) 
                ans = min(ans, 2 * (v[i+2] - v[i]));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};



// Approach 1 : Brute force
// TC : O(N*N*N) , SC : O(1)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size() , mini = INT_MAX ;
        for( int i = 0 ; i<n-2 ; i++ )
            for( int j = i+1 ; j<n-1 ; j++ )
                for( int k = j+1 ; k<n ; k++ )
                    if( nums[i] == nums[j] && nums[i] == nums[k] ){
                        int dist = abs(i-j) + abs(j-k) + abs(k-i) ;
                        mini = min( mini , dist ) ;
                    }
        return ( mini == INT_MAX ) ? -1 : mini ;
    }
};
