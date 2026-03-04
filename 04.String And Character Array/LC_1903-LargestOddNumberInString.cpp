// TC : O(N) , SC : O(1)
class Solution {
public:
    string largestOddNumber(string nums) {        
        int i = nums.size()-1 ;
        while( i>=0 ){
            char ch = nums[i] ;
            if( (ch - '0')%2 )
                break ;
            i-- ;
        }
        return nums.substr(0,i+1);
    }
};