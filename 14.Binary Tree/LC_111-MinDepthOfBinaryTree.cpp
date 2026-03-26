// Approach 2 : BFS
// TC : O(N) , SC : O(N) faster than recursion
class Solution {
public:
    int minDepth(TreeNode* root) {
        if( root == NULL )
            return 0 ;

        queue<TreeNode*> q ;
        q.push( root ) ;
        int depth = 1 ;
        while( !q.empty() ){
            int size = q.size() ;
            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;

                if( frontNode->left == NULL && frontNode->right == NULL )
                    return depth ;

                if( frontNode->left )
                    q.push( frontNode->left );
                if( frontNode->right )
                    q.push( frontNode->right ) ;    
            }
            depth++ ;
        }
        return depth ;
    }
};


// Approach 1 : recursion
// TC : O(N) , SC : O(h) 
class Solution {
public:
    void solve(TreeNode* root , int len , int& minLen ){
        if( root == NULL )
            return ;

        len = len+1 ;
        if( root->left == NULL && root->right == NULL ){
            minLen = min( len , minLen );
        }

        solve( root->left , len , minLen );
        solve( root->right , len , minLen );
        len-- ;
    }

    int minDepth(TreeNode* root) {
        if( root == NULL )
            return 0 ;
        int len = 0 ;
        int minLen = INT_MAX ;
        solve( root , len , minLen ) ;
        return minLen ;
    }
};