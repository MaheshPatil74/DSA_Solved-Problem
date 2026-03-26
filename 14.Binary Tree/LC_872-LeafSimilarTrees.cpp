class Solution {
public:
    void solve( TreeNode* root , vector<int>& arr ){
        if( root == NULL )
            return ;

        if( !root->left && !root->right ){
            arr.push_back(root->val) ;
            return ;
        }

        solve( root->left , arr );
        solve( root->right , arr );
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first , second ;
        solve( root1 , first );
        solve( root2 , second );

        if( first.size() != second.size() )
            return false ;

        for( int i = 0 ; i<first.size() ; i++ )
            if( first[i] != second[i] )
                return false ;

        return true ;
    }
};