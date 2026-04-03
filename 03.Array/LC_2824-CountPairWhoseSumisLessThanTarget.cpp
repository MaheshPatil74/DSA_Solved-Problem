// Approach 2 : Sorting and two pointer
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort( nums.begin() , nums.end() );
        int n = nums.size() ;

        int left = 0 , right = n-1 ;
        int count = 0 ;
        while( left<right ){
            if( nums[left] + nums[right] < target ){
                count+= ( right-left ) ;
                left++ ;
            } 
            else
                right-- ;
        }
        return count ;
    }
};



// Approach 1 : Brute force
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size() ;
        int count = 0 ;
        for( int i = 0 ; i<n ; i++ )
            for( int j = i+1 ; j<n ; j++ )
                if( nums[i] + nums[j] < target )
                    count++ ;
        return count ;
    }
};