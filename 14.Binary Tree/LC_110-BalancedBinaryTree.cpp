// Approach 2 : optimal
// TC : O(N) , SC : O(H)
class Solution {
public:
    int check( TreeNode* root ){
        if( root == NULL )
            return true ;
        int left = check(root->left);
        if( left == -1 )
            return -1 ;

        int right = check( root->right );
        if( right == -1 )
            return -1 ;

        if( abs( left-right) > 1 )
            return -1 ;

        return 1 + max( left , right ) ;
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1 ;
    }
};



// Approach 1 : Brute force using recursion
// TC : O(N*N) , SC : O(H)
class Solution {
public:
    int height(TreeNode* root ){
        if( root == NULL )
            return 0 ;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if( root == NULL )
            return true ;
        bool left = isBalanced( root->left );
        bool right = isBalanced( root->right );
        bool diff = abs( height(root->left) - height( root->right))<=1 ;
        return (left && right && diff ) ; 
    }
};