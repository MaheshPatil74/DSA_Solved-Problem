// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if( root == NULL )
            return ans ;

        queue<TreeNode*> q ;
        q.push( root ) ;
        bool leftToRight = true ;

        while( !q.empty() ){
            int size = q.size() ;
            vector<int> temp(size) ;

            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;

                int idx = leftToRight ? i : size-1-i ;
                temp[idx] =  frontNode->val ;
                if( frontNode->left )
                    q.push( frontNode->left ) ;
                if( frontNode->right )
                    q.push( frontNode->right ) ;
            }

            leftToRight = !leftToRight ;
            ans.push_back(temp) ;
        }
        return ans ;     
    }
};