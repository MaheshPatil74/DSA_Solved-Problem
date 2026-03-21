// Approach 2 — Sorting
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort( nums.begin() , nums.end() ) ;
        for( int i = 0 ; i <nums.size() ; i+=3 ){
            if( (i+2>=nums.size() ) || (nums[i] != nums[i+2]) )
                return nums[i] ;
        }
        return -1 ;
    }
};

// Approach 1 — Brute Force (HashMap)
// Count frequency and return element with frequency 1.
// TC : O(N) , SC : O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq ;
        for( int num : nums )
            freq[num]++ ;

        for( auto it : freq )
            if( it.second == 1 )
                return it.first ;
        return -1 ;
    }
};