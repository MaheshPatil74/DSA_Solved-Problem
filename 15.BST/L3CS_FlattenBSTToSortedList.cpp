#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
// TC = O(n) ans SC = O(H)

void inorder(TreeNode<int>* root , vector<TreeNode<int>*>& arr ){
    if( root == NULL )
        return ;

    inorder(root->left , arr ) ;
    arr.push_back(root ) ;
    inorder(root->right , arr ) ;
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<TreeNode<int>*> arr ;
    inorder(root , arr) ;
    int n = arr.size() ;
    int i = 0 ;
    while( i < n-1 ){
        arr[i]->left = NULL ;
        arr[i]->right = arr[i+1] ;
        i++ ;
    }

    // i points on last node
    arr[i]->left = NULL ;
    arr[i]->right = NULL ;

    return arr[0] ;   
}

// way 2 ==> same as slight change in implementation
// TC = O(n) ans SC = O(n)
void inorder(TreeNode<int>* root , vector<int>& arr ){
    if( root == NULL )
        return ;

    inorder(root->left , arr ) ;
    arr.push_back(root->data) ;
    inorder(root->right , arr ) ;
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> arr ;

    // store inorder sorted values
    inorder(root , arr) ;
    int n = arr.size() ;
    
    TreeNode<int>* newRoot = new TreeNode<int>(arr[0]) ;
    TreeNode<int>* curr = newRoot ;

    // 2nd step
    for( int i = 1 ; i<n ; i++ ){
        TreeNode<int>* temp = new TreeNode<int>(arr[i]) ;
        curr->left = NULL ;
        curr->right = temp ;
        curr = temp ;
    }

    // 3rd step
    curr->left = NULL ;
    curr->right = NULL ;

    return newRoot ;
}