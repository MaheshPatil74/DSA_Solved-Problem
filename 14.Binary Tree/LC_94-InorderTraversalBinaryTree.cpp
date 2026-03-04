// TC : O(N) , SC: O(N)
class Solution {
private :
    void traversal(vector<int>& ans , TreeNode* root) {
        if( root == NULL )
            return ;

        traversal(ans,root->left) ;
        ans.push_back(root->val) ;
        traversal(ans,root->right) ;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        traversal(ans,root);
        return ans ; 
    }
};