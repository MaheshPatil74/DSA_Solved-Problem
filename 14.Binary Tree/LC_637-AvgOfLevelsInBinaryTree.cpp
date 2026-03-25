// Approach : BFS method
// TC : O(N) , SC : O(N) queue
class Solution {
public: 
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans ;
        queue<TreeNode*> q ;
        q.push( root ) ;

        while( !q.empty() ){
            int size = q.size() ;
            long long sum = 0 ; 
            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;
                sum += frontNode->val ;
                if( frontNode->left )
                    q.push( frontNode->left );
                if( frontNode->right )
                    q.push( frontNode->right );
            }
            ans.push_back( (double)sum / size ) ;
        }
        return ans ;
    }
};