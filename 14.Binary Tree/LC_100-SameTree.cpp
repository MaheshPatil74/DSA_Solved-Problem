// TC : O(N) , SC : O(N)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL && q == NULL )
            return true ;
        if( p != NULL && q == NULL )
            return false ;
        if( p == NULL && q != NULL )
            return false ;
        
        bool leftAns = isSameTree( p->left , q->left ) ;
        bool rightAns = isSameTree( p->right , q->right ) ;
        bool value = ( p->val == q->val ) ;
        return( leftAns && rightAns && value ) ;        
    }
};