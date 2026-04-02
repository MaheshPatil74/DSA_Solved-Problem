// Approach 2 : Map two pass
// TC : O(N) , SC : O(N)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp ;
        for( int num : nums )
            mp[num]++ ;

        int count = 0 ;
        for( auto it : mp ){
            int k = it.second ;
            count += ( k * (k-1))/2 ;
        }
        return count ;
    }
};


// Approach 1 :
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 ;
        for( int i = 0 ; i<nums.size()-1 ; i++ )
            for( int j = i+1 ; j<nums.size() ; j++ )
                if( nums[i] == nums[j] )
                    count++ ;
        return count ;
    }
};