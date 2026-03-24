// Querstion : Level Order Traversal from bottom to top
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans ;
        if( root == NULL )
            return ans ;

        queue<TreeNode*> q ;
        q.push( root ) ;

        while( !q.empty() ){
            int size = q.size() ;
            vector<int> temp ;

            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;

                temp.push_back( frontNode->val ) ;
                if( frontNode->left )
                    q.push( frontNode->left ) ;
                if( frontNode->right )
                    q.push( frontNode->right ) ;
            }
            ans.push_back(temp) ;
        }
        int n = ans.size() ;
        for( int i = 0 ; i<n/2 ; i++ )
            swap( ans[i] , ans[n-1-i] );
        return ans ;      
    }
};