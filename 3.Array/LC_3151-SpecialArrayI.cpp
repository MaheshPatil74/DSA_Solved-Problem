// Approach 3 : Check Adjacent Elements Parity by Modulo Operation (Optimized)
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size()-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==nums[i+1]%2){
                return false;
            }
        }
        return true;
    }
};

// Approach 2 : Check Adjacent Elements Parity by Modulo Operation
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        for( int i = 1 ; i<nums.size() ; i++ ){
            if( (nums[i]%2 == 0 && nums[i-1]%2 == 0) || (nums[i]%2 == 1 && nums[i-1]%2 == 1) )    
                return false ;
        }
        return true ;   
    }
};

// Approach 1 : (Own)Check Adjacent Elements Parity by Bitwise AND Operation
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        for( int i = 1 ; i<nums.size() ; i++ ){
            bool current = nums[i] & 1 ;
            bool prev = nums[i-1] & 1 ;
            if( current == prev )
                return false ;
        }
        return true ;
    }
};