// Approach 1 : Brute Force
// TC : O(N) , SC : O(N)
class Solution {
public:
    void inorderBST( TreeNode* root , vector<int>& inorder ){
        if( root == NULL )
            return ;

        inorderBST( root->left , inorder );
        inorder.push_back( root->val ) ;
        inorderBST( root->right , inorder );
    }
     
    TreeNode* buildBST(vector<int>& inorder , int N ){
        TreeNode* head = new TreeNode( inorder[0] ) ;
        TreeNode* curr = head ;
        for( int i = 1 ; i<N ; i++ ){
            TreeNode* temp = new TreeNode( inorder[i] ) ;
            curr->right = temp ;
            curr = temp ;
        }
        return head ;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder ;
        inorderBST( root , inorder ) ;

        int n = inorder.size() ;
        return buildBST( inorder , n ) ;
    }
};