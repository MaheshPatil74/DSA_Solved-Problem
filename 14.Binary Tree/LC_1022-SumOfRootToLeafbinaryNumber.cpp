class Solution {
public:
    void solve( TreeNode* root , int temp , long long int& sum ){
        if( root == NULL )
            return ;

        temp = ( temp<<1) | (root->val) ;

        if( !root->left && !root->right ){
            sum += temp ;
            return ;
        }

        solve( root->left , temp , sum );
        solve( root->right , temp , sum );
    }

    int sumRootToLeaf(TreeNode* root) {
        long long int sum = 0 ;
        int temp = 0 ;
        solve( root , temp , sum );
        return sum ;
    }
};