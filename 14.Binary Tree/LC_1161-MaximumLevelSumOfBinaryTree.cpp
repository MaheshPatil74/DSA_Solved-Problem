class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q ;
        q.push( root ) ;

        int level = 1 ;
        int maxLevelIdx = 1 ;
        int maxLevelSum = INT_MIN ;

        while( !q.empty() ){
            int size = q.size() ;
            int sum = 0 ;
            for( int i = 0 ; i<size ; i++ ){
                TreeNode* frontNode = q.front() ;
                q.pop() ;

                sum += frontNode->val ;
                if( frontNode->left )
                    q.push( frontNode->left );
                if( frontNode->right )
                    q.push( frontNode->right ) ;
            }
            if( sum > maxLevelSum ){
                maxLevelSum = sum ;
                maxLevelIdx = level ;
            }
            level++ ;
        }
        return maxLevelIdx ;
    }
};