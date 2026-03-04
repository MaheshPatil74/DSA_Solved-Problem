// Time: O(N) → single traversal
// Space: O(1) → no extra array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size() ;
    if( n<=1 ) return 1 ;

    int k = 0 ;
    for(int i = 1 ; i<n ; i++ ){
        if( nums[i] != nums[k] ){
            k++ ;
            nums[k] = nums[i] ;
        }
    }   
    return k+1 ;
    }
};