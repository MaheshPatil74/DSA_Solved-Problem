// TC : O(N) , SC : O(N)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp ;
        for( int num : nums )
            mp[num]++ ;

        int count = 0 ;
        for( auto & it : mp ){
            if( it.second == 1 )
                return -1 ;
            else
                count += (it.second+2)/3 ;
        }
        return count ;   
    }
};