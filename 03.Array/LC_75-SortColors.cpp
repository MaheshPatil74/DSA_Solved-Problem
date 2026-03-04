// Approach 2 : one pass : 3 pointers : Dutch National Flag Algorithm
// TC : O(N) , SC : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 ;
        int mid = 0 ;
        int high = nums.size()-1 ;

        while( mid<=high ){
            if( nums[mid] == 0 ){
                swap( nums[low] , nums[mid] ) ;
                low++ ;
                mid++ ;
            }
            else if( nums[mid] == 1 ){
                mid++ ;
            }
            else{
                swap( nums[mid] , nums[high] );
                high-- ;
            }
        }
    }
};

// Approach 1 : two pass : using counting method and replace
// TC : O(N) , SC : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0 , ones = 0 , twos = 0 ;
        for( int num : nums ){
            if( num == 0 )
                zeros++ ;
            else if( num == 1 )
                ones++ ;
            else
                twos++ ;
        }

        int i = 0 ;
        while( zeros ){
            nums[i++] = 0 ;
            zeros-- ;
        }
        while( ones ){
            nums[i++] = 1 ;
            ones-- ;
        }
        while( twos ){
            nums[i++] = 2 ;
            twos-- ;
        }
    }
};