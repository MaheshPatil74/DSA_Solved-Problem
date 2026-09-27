// Approach 2 : Hashmap ==>> TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp ;
        int n = nums.size() ;

        for( int i=0 ; i<n ; i++ ){
            int complement = target - nums[i] ; 
            if( mp.count( complement ) )
                return { i , mp[complement] } ;

            mp[ nums[i] ] = i ;
        }
        return {} ;
    }
};

// Approach 1 : Brute force ==>> TC : O(N*N) , SC : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for( int i = 0 ; i<nums.size()-1 ; i++ )
            for( int j = i+1 ; j<nums.size() ; j++ )
                if( nums[i] + nums[j] == target )
                    return {i,j} ;
        return {} ;
    }
};