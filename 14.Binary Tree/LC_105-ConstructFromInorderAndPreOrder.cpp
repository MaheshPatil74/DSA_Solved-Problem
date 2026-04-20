// Approach 2 : Optimised TC Using Map
// TC : O(N) , SC : O(N)
class Solution {
public:
    void createMapping( vector<int>& inorder , unordered_map<int,int>& mp , int n ){
        for( int i = 0 ; i<n ; i++ )
            mp[inorder[i]] = i ;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , unordered_map<int,int> &mp , int &preorderIndex , int inorderStart , int inorderEnd , int n ){
        if( preorderIndex >= n || inorderStart > inorderEnd )
            return NULL ;

        int element = preorder[preorderIndex++] ;
        TreeNode* root = new TreeNode(element) ;
        int position = mp[element] ;

        root->left = solve(preorder, inorder , mp , preorderIndex , inorderStart , position-1 , n ) ;
        root->right = solve(preorder, inorder , mp , preorderIndex , position+1 , inorderEnd , n ) ;
        return root ;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() ;
        int preOrderIndex = 0 ;
        unordered_map<int,int> mp ;
        createMapping(inorder,mp,n) ;
        TreeNode* ans = solve( preorder, inorder , mp  , preOrderIndex , 0 , n-1 , n  ) ;
        return ans ;
    }
};




// Approach 1 : Brute force
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    int findPosition( vector<int>& inorder , int element , int n ){
        for( int i = 0 ; i<n ; i++ )
            if( inorder[i] == element )
                return i ;
        return -1 ;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int &preorderIndex , int inorderStart , int inorderEnd , int n ){
        if( preorderIndex >= n || inorderStart > inorderEnd )
            return NULL ;

        int element = preorder[preorderIndex++] ;
        TreeNode* root = new TreeNode(element) ;
        int position = findPosition(inorder,element,n) ;

        root->left = solve(preorder, inorder , preorderIndex , inorderStart , position-1 , n ) ;
        root->right = solve(preorder, inorder , preorderIndex , position+1 , inorderEnd , n ) ;
        return root ;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() ;
        int preOrderIndex = 0 ;
        TreeNode* ans = solve( preorder, inorder , preOrderIndex , 0 , n-1 , n  ) ;
        return ans ;
    }
};