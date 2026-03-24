#include <bits/stdc++.h> 
// Approach 1 ==>> directly build a tree like as first lecture of BST but problem is that tC is O(n*n) which is inefficient
// approach 2 ==>> sort tthe preoprder so that we get inorder and using both that is inorder and preorder create a tree and TC = O(N*logN)
// approach 3 ==>>
BinaryTreeNode<int>* solve(vector<int> &preorder , int mini , int maxi , int & i){
    if( i>= preorder.size() )
        return NULL ;

    if( preorder[i] < mini || preorder[i] > maxi )
        return NULL ;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]) ;
    root->left = solve(preorder,mini,root->data , i) ;
    root->right = solve(preorder,root->data , maxi,i) ;
    return root ;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int maxi = INT_MAX ;
    int mini = INT_MIN ;
    int i = 0 ;
    return solve(preorder , mini , maxi , i) ;
}