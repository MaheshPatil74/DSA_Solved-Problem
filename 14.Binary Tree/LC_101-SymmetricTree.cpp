// Approach 3 : Iterative 
// TC : O(N) , SC : O(N) == queue
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q ;
        q.push( root->left ) ;
        q.push( root->right ) ;

        while( !q.empty() ){
            TreeNode* left = q.front() ; q.pop() ;
            TreeNode* right = q.front() ; q.pop() ;

            if( left == NULL &&  right == NULL )
                continue ;
            if( left == NULL || right == NULL )
                return false ;
            if( left->val != right->val )
                return false ;

            q.push( left->left );
            q.push( right->right );
            q.push( left->right );
            q.push( right->left );
        }
        return true ;
    }
};

// Approach 2 : recursive mirror    
// Tree symmetric means: left->val == right->val , left->left == right->right , left->right == right->left
// TC : O(N) , SC : O(H) == recursive stack
class Solution {
public:
    bool isMirror( TreeNode* left , TreeNode* right ){
        if( left == NULL && right == NULL )
            return true ;
        if( left == NULL || right == NULL )
            return false ;
        if( left->val != right->val )
            return false ;

        return isMirror(left->left,right->right) && isMirror(left->right,right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror( root->left , root->right );
    }
};


// Approach 1 : Brute Force ==>> find preorder of both left and right then compare
// TC : O(N) , SC : O(N)
class Solution {
public:
    void preorderLeft(TreeNode* root , vector<int> &left ){
        if( root == NULL ){
            left.push_back(-1);
            return ;
        }
        left.push_back( root->val );
        preorderLeft( root->left , left );
        preorderLeft( root->right , left );        
    }

    void preorderRight(TreeNode* root , vector<int> &right ){
        if( root == NULL ){
            right.push_back(-1);
            return ;
        }
        right.push_back( root->val );
        preorderRight( root->right , right );
        preorderRight( root->left , right );        
    }

    bool isSymmetric(TreeNode* root) {
        vector<int> left,right ;
        preorderLeft(root->left,left);
        preorderRight(root->right,right);
        return (left == right) ;
    }
};