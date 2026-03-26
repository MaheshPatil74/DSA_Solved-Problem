// Approach 3 : optimal
// O(log² N)
// TC : O(log² N) , SC : O(log N) recursive stack
class Solution {
public:
    int leftHeight( TreeNode* root ){
        int h = 0 ;
        while( root ){
            h++ ;
            root = root->left ;
        }
        return h ;
    }

    int rightHeight( TreeNode* root ){
        int h = 0 ;
        while( root ){
            h++ ;
            root = root->right ;
        }
        return h ;
    }

    int countNodes(TreeNode* root) {
        if( root == NULL )
            return 0 ;

        int lh = leftHeight(root) ;
        int rh = rightHeight(root) ;

        if( lh == rh )
            return ( 1<<lh)-1 ;
        return 1 + countNodes( root->left) + countNodes(root->right);
    }
};



// Approach 2 : Accepted solution ==>> but still O(N) , questn want less than O(N)
// TC : O(N) , SC : O(H) recursive stack
class Solution {
public:
    int countNodes(TreeNode* root) {
        if( root == NULL )
            return 0 ;
        return 1 + countNodes( root->left) + countNodes(root->right) ;
    }
};


// Approach 1 : Accepted solution ==>> but question want TC < O(N)
// TC : O(N) , SC : O(H) recursive stack
class Solution {
public:
    void solve( TreeNode* root , int& count ){
        if( root == NULL )
            return ;

        count++ ;
        solve( root->left , count );
        solve( root->right , count );
    }

    int countNodes(TreeNode* root) {
        int count = 0 ;
        solve( root , count ) ;
        return count ;
    }
};