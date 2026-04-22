// Approach 2 : Optimal Used Of BST Property
// TC : O(LogN) , SC : O(H)
class Solution {
public:
    void solve(TreeNode* root, int low, int high , long long &sum ){
        if( root == NULL )
            return ;

        if( root->val >= low && root->val <= high )
            sum += root->val ;

        if( root->val > low)
            solve( root->left , low , high , sum );
        if( root->val < high)
            solve( root->right , low , high , sum );
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        long long sum = 0 ;
        solve( root , low , high , sum );
        return sum ;
    }
};

// Approach 1 : Brute force
// TC : O(N) , SC : O(H)
class Solution {
public:
    void solve(TreeNode* root, int low, int high , long long &sum ){
        if( root == NULL )
            return ;

        if( root->val >= low && root->val <= high )
            sum += root->val ;

        solve( root->left , low , high , sum );
        solve( root->right , low , high , sum );
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        long long sum = 0 ;
        solve( root , low , high , sum );
        return sum ;
    }
};