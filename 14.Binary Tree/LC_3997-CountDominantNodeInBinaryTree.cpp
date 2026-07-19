// TC : O(N) , SC : O(H)
class Solution {
public:
    int solve(TreeNode* root , int &count ){
        if( root == NULL )
            return INT_MIN ;

        int leftMax = solve( root->left , count ) ;
        int rightMax = solve( root->right , count ) ; 

        int subTreeMax = max( root->val , max( leftMax , rightMax )) ;
        if( root->val == subTreeMax )
            count++ ;
        return subTreeMax ;        
    }

    int countDominantNodes(TreeNode* root) {
        int count = 0 ;
        int temp = solve(root,count);
        return count ;
    }
};