// Approach 2 : Recursive
// TC : O(N) , SC : O(H)
class Solution {
public:
    void solve( TreeNode* root , int depth , int& maxDepth , int& ans ){
        if( root == NULL )
            return ;

        if( depth > maxDepth ){
            maxDepth = depth ;
            ans = root->val ;
        }

        solve( root->left , depth+1 , maxDepth , ans );
        solve( root->right , depth+1 , maxDepth , ans );
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0 , maxDepth = -1 ;
        int ans = 0 ;
        solve( root , depth , maxDepth , ans );
        return ans ;
    }
};




// Approach 1 : BFS
// TC : O(N) , SC : O(N)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0 ;

        queue<TreeNode*> q ;
        q.push( root ) ;

        while( !q.empty() ){
            int size = q.size() ;
            ans = q.front()->val ;

            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;
                
                if( frontNode->left )
                    q.push( frontNode->left ) ;
                if( frontNode->right )
                    q.push( frontNode->right ) ;
            }
        }
        return ans ;
    }
};