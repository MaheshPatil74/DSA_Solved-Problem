// Approach 2 : optimal 
// Core Insight (VERY IMPORTANT)
// Sequence tabhi start hogi jab: (num - 1) exist nahi karta
// Matlab start of sequence detect karo
// TC : O(N) , SC : O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st( nums.begin() , nums.end() );
        int longest = 0 ;

        for( int num : st ){
            if( st.find(num-1) == st.end() ){
                int curr = num ;
                int count = 1 ;
                while( st.find(curr+1) != st.end() ){
                    curr++ ;
                    count++ ;
                }
                longest = max( longest , count ) ;
            }
        }
        return longest ;
    }
};


// Approach 1 : Brute force 
// TC : O(N*LogN) , SC : O(1) ==>> but question want O(N) TC
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 )
            return 0 ;
        sort( nums.begin() , nums.end());

        int maxSeq = 0 ;
        int len = 1 ;
        
        for( int i = 1 ; i<nums.size() ; i++ ){
            if( nums[i] == nums[i-1]+1 )
                len++ ;
            else if( nums[i] == nums[i-1] ){
                continue ;
            }
            else{
                maxSeq = max( maxSeq , len );
                len = 1 ;
            }
        }
        maxSeq = max( maxSeq , len );
        return maxSeq ;
    }
};