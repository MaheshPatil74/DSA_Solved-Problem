// Approach 2 : 
// Time: O(N) , Space: O(H)
class Solution {
public:
    long dfs(TreeNode* root , int minValue ){
        if( root == NULL )
            return LONG_MAX ;

        if( root->val > minValue )
            return root->val ;
        long left = dfs( root->left , minValue );
        long right = dfs( root->right , minValue );
        return min( left , right );
    }

    int findSecondMinimumValue(TreeNode* root) {
        long ans = dfs( root , root->val ) ; ;
        return ( ans == LONG_MAX ) ? -1 : ans ;
    }
};


// Approach 1 : Brute force ==>> check all node
class Solution {
public:
    void solve( TreeNode* root , int& firstMin , int& secondMin ){
        if( root == NULL )
            return ;

        if( root->val < firstMin ){
            secondMin = firstMin ;
            firstMin = root->val ;
        }
        else if( root->val < secondMin  && root->val > firstMin )
            secondMin = root->val ;

        solve( root->left , firstMin , secondMin );
        solve( root->right , firstMin , secondMin );
    }

    int findSecondMinimumValue(TreeNode* root) {
        int firstMin = INT_MAX ;
        int secondMin = INT_MAX ;
        solve( root , firstMin , secondMin );
        return ( secondMin == INT_MAX ) ? -1 : secondMin ;
    }
};