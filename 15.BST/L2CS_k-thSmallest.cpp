#include <bits/stdc++.h> 
// Approach 1 : find inorder and return value using indexing
void inorder(BinaryTreeNode<int> *root , vector<int> & ans){
    if(root==NULL)
        return ;

    inorder(root->left,ans) ;
    ans.push_back(root->data) ;
    inorder(root->right,ans) ;
} 

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    vector<int> ans ;
    inorder(root,ans) ;

    if (k <= 0 || k > ans.size()) {
        // k is out of valid range
        return -1; // or throw an exception depending on your requirement
    }
    return ans[k-1] ;
}


// Approach 2 :recursive Efficient TC = O(n) and SC = O(H)
int solve(BinaryTreeNode<int>* root, int &i, int k){
    if(root==NULL)
        return -1 ;

    // Left part
    int left = solve(root->left , i , k );
    if(left != -1 )
        return left ;

    // data part
    i++ ;
    if( i==k )
        return root->data ;

    // right part
    return solve(root->right,i,k) ;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0 ;
    int ans = solve(root,i,k) ;
    return ans ;
}