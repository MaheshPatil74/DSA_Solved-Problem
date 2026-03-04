#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
// Approach 1 : find inorder and check sorted ==>>TC = O(n) & SC=O(n) i think check once
bool checkSorted(vector<int> arr ){
    int n = arr.size() ;
    for(int i = 0 ; i<n-1 ; i++ ){
        if( arr[i] >  arr[i+1] )
            return false ;
    }
    return true ;
}

void inorder(BinaryTreeNode<int> *root , vector<int> & ans){
    if(root==NULL)
        return ;

    inorder(root->left,ans) ;
    ans.push_back(root->data) ;
    inorder(root->right,ans) ;
} 

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> ans ;
    inorder(root,ans) ;

    return checkSorted(ans) ? true : false ;
}




// Approach 2 : Efficient TC = O(n) and SC = O(H)
bool isBST(BinaryTreeNode<int> *root , int mini , int maxi ){
    if(root==NULL)
        return true ;

    if( root->data >= mini && root->data <= maxi ){
        bool left = isBST(root->left, mini , root->data) ;
        bool right = isBST(root->right, root->data , maxi ) ;
        return ( left && right ) ;
    }
    else{
        return false ;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root , INT_MIN , INT_MAX ) ; 
}