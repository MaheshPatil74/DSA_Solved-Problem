// Question : Level Order Traversal from top to bottom
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return ans ;
    }
};