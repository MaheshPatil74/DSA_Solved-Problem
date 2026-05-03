// TC : O(N) , SC : O( h ) == O( LogN )
class Solution {
public:
    TreeNode* inorderToBST(vector<int> nums , int start , int end ){
        if( start > end )
            return NULL ;

        int mid = ( start + end ) / 2 ;
        TreeNode* root = new TreeNode( nums[mid] ) ;
        root->left = inorderToBST(nums,start,mid-1) ;
        root->right = inorderToBST(nums,mid+1,end) ;
        return root ;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() ;
        return inorderToBST(nums,0,n-1) ;
    }
};