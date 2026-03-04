// approach 1 : Find Maximum and Compare
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0 ;
        for( int num : candies )
            maxi = max( maxi , num );
        
        vector<bool> ans ;
        for( int num : candies ){
            if( num + extraCandies >= maxi )
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans ;
    }
};