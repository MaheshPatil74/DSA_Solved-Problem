// Approach 3 : Moore Voting Algo
// TC = N
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0 ;
        int ans = nums[0] ;

        for( int i = 0 ; i<nums.size() ; i++ ){
            if( freq == 0 )
                ans = nums[i] ;
            
            if( ans == nums[i] )
                freq++ ;
            else
                freq-- ;
        }
        return ans ;
    }
};


// Approach 2 : first Sort Then Count Freq
// TC = ( (N*LogN) + N ) == N*LogN
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort( nums.begin() , nums.end() );
        int ans = nums[0] ;
        int count = 1 ;
        for( int i = 1 ; i<nums.size() ; i++ ){
            if( nums[i] == nums[i-1] )
                count++ ;
            else{
                count = 1 ;
                ans = nums[i] ;
            }
                
            if( count > nums.size()/2 )
                return ans ;
        }
        return ans ;
    }
};


// Approach 1 : Brute Force
// TC = n^2 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        for( int i = 0 ; i<n ; i++ ){
            int element = nums[i] ;
            int count = 0 ;
            for( int j = 0 ; j<n ; j++ ){
                if( nums[j] == element )
                    count++ ;
            }
            if( count > n/2 )
                return element ;
        }
        return -1 ;
    }
};