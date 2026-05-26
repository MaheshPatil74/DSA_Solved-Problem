// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
            unordered_map<int , int> count ;
            vector<int> ans ;

            for( int num : nums ){
                count[num]++ ;
                if( count[num] <= k )
                    ans.push_back( num ) ;
            }
            return ans ;
    }
};