// TC : O(N) , SC : O(H) height of tree (recursive stack)
class Solution {
public:
    bool solve( TreeNode* root , int& sum , int targetSum ){
        if( root == NULL )
            return false ;

        if( root->left == NULL && root->right==NULL )
            return ( sum == targetSum ) ;

        sum += root->val ;
        bool left = solve( root->left , sum , targetSum );
        bool right = solve( root->right , sum , targetSum );
        return ( left || right ) ;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0 ;
        return solve( root , sum , targetSum ) ;
    }
};