// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size() ;
        int even = 0 , odd = 0 ;
        
        if( nums[n-1] % 2 == 0 )
            even++ ;
        else
            odd++ ;
        nums[n-1] = 0 ;

        for( int i = nums.size()-2 ; i>=0 ; i-- ){
            if( nums[i] % 2 ){  //odd
                odd++ ;
                nums[i] = even ;
            }
            else{               //even
                even++ ;
                nums[i] = odd ;
            }
        }
        return nums ;
    }
};