class Solution {
public:
    bool check( TreeNode* root , int d ){
        if( root == NULL )
            return true ;
        
        if( root->val != d )
            return false ;
        
        bool leftCheck = check( root->left , d ) ;
        bool rightCheck = check( root->right , d ) ;
        return ( leftCheck && rightCheck ) ;
    }

    bool isUnivalTree(TreeNode* root) {
        return check(root,root->val) ;
    }
};