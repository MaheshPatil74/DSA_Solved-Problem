#include <bits/stdc++.h> 
// TC = O(n) ans SC = O(H)
void inorder(BinaryTreeNode<int>* root , vector<int>& ans ){
    if( root == NULL )
        return ;

    inorder(root->left , ans ) ;
    ans.push_back(root->data ) ;
    inorder(root->right , ans ) ;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> ans ;
    inorder(root,ans) ;

    int n = ans.size() ;
    int i = 0 ; 
    int j = n-1 ;
    int sum = 0 ;

    while( i<j ){
        sum = ans[i] + ans[j] ;
        if( sum == target )
            return true ;
        else if( sum > target )
            j-- ;
        else
            i++ ;
    }
    return false ;
}