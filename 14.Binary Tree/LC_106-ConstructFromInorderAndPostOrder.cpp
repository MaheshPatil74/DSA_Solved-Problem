// Approach : Optimised TC Using Map
// TC : O(N) , SC : O(N)
class Solution {
public:
    void createMapping( vector<int>& inorder , unordered_map<int,int>& mp , int n ){
        for( int i = 0 ; i<n ; i++ )
            mp[inorder[i]] = i ;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , unordered_map<int,int> &mp , int &postorderIndex , int inorderStart , int inorderEnd , int n ){
        if( postorderIndex < 0 || inorderStart > inorderEnd )
            return NULL ;

        int element = postorder[postorderIndex--] ;
        TreeNode* root = new TreeNode(element) ;
        int position = mp[element] ;

        root->right = solve( inorder , postorder, mp , postorderIndex , position+1 , inorderEnd , n ) ;
        root->left = solve( inorder , postorder , mp , postorderIndex , inorderStart , position-1 , n ) ;
        return root ;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() ;
        int postOrderIndex = n-1 ;
        unordered_map<int,int> mp ;
        createMapping(inorder,mp,n) ;
        TreeNode* ans = solve( inorder, postorder , mp  , postOrderIndex , 0 , n-1 , n  ) ;
        return ans ;
    }
};