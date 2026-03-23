// Approach 2 : Hashmap 
// TC : O(N) , SC : O(N)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;

        for( int i = 0 ; i<nums.size() ; i++ ){
            if( mp.find(nums[i]) != mp.end() )
                if( i - mp[nums[i]] <= k )
                    return true ;
            mp[nums[i]] = i ;
        }
        return false ;
    }
};


// Approach 1 : Brute force 
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size() ;
        for( int i = 0 ; i<n ; i++ )
            for( int j = i+1 ; j<n ; j++ )
                if( (nums[i] == nums[j]) && (abs( i-j ) <= k) )
                    return true ;
        return false ;
    }
};