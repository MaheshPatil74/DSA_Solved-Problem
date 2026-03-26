class Solution {
public:
    void solve(TreeNode* root , string temp , vector<string>& ans ){
        if( root == NULL )
            return ;

        if( !temp.empty() )
            temp += "->" ;
        
        temp += to_string(root->val) ;

        if( root->left==NULL && root->right==NULL ){
            ans.push_back(temp) ;
            return ;
        }

        solve( root->left , temp , ans );
        solve( root->right , temp , ans );
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ;
        solve( root , "" , ans );
        return ans ;
    }
};