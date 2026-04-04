// Approach 2 : optimal
// TC : O(N) , SC : O(N)
class Solution {
public:
    pair<int,int> diameterFast(TreeNode* root ){
        if( root == NULL )
            return { 0 , 0 };

        pair<int,int> leftAns = diameterFast( root->left );
        pair<int,int> rightAns = diameterFast( root->right );

        int op1 = leftAns.first ;
        int op2 = rightAns.first ;
        int op3 = leftAns.second + rightAns.second ;

        pair<int,int> ans ;
        ans.first = max( op1 , max( op2,op3) );
        ans.second = 1 + max( leftAns.second , rightAns.second ) ;
        return ans ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first ;
    }
};



// Approach 1 : using height function
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    int height( TreeNode* root ){
        if( root == NULL )
            return 0 ;
        return 1 + max( height(root->left) , height( root->right) ) ;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if( root == NULL )
            return 0 ;

        int op1 = diameterOfBinaryTree( root->left );
        int op2 = diameterOfBinaryTree( root->right );
        int op3 = height( root->left) + height(root->right) ;
        int ans = max( op1 , max( op2 , op3) ) ;
        return ans ;
    }
};