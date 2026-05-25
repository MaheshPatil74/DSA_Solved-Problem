// TC : O(N) , SC : O(H)
class Solution {
    void reverse( TreeNode* leftNode , TreeNode* rightNode , int level ){
        if( !leftNode || !rightNode )
            return ;

        if( level % 2 == 1  )
            swap( leftNode->val , rightNode->val ) ;

        reverse( leftNode->left , rightNode->right , level+1 ) ;
        reverse( leftNode->right , rightNode->left , level+1 ) ;
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 1 ;
        reverse( root->left , root->right , level ) ;
        return root ;
    }
};