// Approach 2 : Better aproach by storing nodes directly instead of values
// TC : O(N) , SC : O(H)
class Solution {
public:
    void inorderBST( TreeNode* root , vector<TreeNode*>& inorder ){
        if( root == NULL )
            return ;

        inorderBST( root->left , inorder );
        inorder.push_back( root ) ;
        inorderBST( root->right , inorder );
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> inorder ;
        inorderBST( root , inorder ) ;

        int N = inorder.size() ;
        for( int i = 0 ; i+1<N ; i++ ){
            inorder[i]->left = nullptr ;
            inorder[i]->right = inorder[i+1] ; 
        }
        inorder[N-1]->left = nullptr ;
        inorder[N-1]->right = nullptr ;

        return inorder[0] ;
    }
};


// Approach 1 : Brute Force using inorder of values
// TC : O(N) , 
// SC : O(N)    <<== Vector + Recursion
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