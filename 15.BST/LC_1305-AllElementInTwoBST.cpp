// TC : O(M+N) , SC :O(M+N)
class Solution {
public:
    void inorder( TreeNode * root , vector<int>& arr ){
        if( root == NULL )
            return ;
        inorder( root->left , arr );
        arr.push_back( root->val );
        inorder( root->right , arr );
    }

    vector<int> mergeArray( vector<int>arr1 , vector<int>arr2 ){
        int i = 0 , j = 0 ;
        vector<int> arr ;
        while( i < arr1.size() && j<arr2.size() ){
            if( arr1[i] < arr2[j] )
                arr.push_back( arr1[i++] ) ;
            else
                arr.push_back( arr2[j++] );
        }

        while( i < arr1.size() )
            arr.push_back( arr1[i++] ) ;

        while( j<arr2.size() )
            arr.push_back( arr2[j++] );

        return arr ;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1 , arr2 ;
        inorder( root1 , arr1 ) ;
        inorder( root2 , arr2 ) ;

        return mergeArray(arr1 , arr2) ;
    }
};