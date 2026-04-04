// Approach 1 : BFS
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans ;
        if( root == NULL )
            return ans ;
        
        queue<TreeNode*> q ;
        q.push( root ) ;

        while( !q.empty() ){
            int size = q.size() ;
            int maxi = INT_MIN ;

            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;
                
                maxi = max( maxi , frontNode->val ) ;

                if( frontNode->left )
                    q.push( frontNode->left ) ;
                if( frontNode->right )
                    q.push( frontNode->right ) ;
            }
            ans.push_back( maxi );
        }
        return ans ;
    }
};