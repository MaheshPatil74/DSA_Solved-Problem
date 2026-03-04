// Approach 2 :
void solve(BinaryTreeNode<int> *root , int & count ){
    if( root == NULL )
        return ;
    if( root->left == NULL && root->right == NULL ){
        count++ ;
        return ;
    }
    solve( root->left , count );
    solve( root->right , count ) ;   
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    if( root == NULL )
        return 0 ;

    int count = 0 ;
    solve(root ,count ) ;
    return count ;
}


// *****************************************************
// Approach 1 : using Inorder Traverssal
void Inorder( BinaryTreeNode<int> *root , int & count ){
    if( root == NULL )
        return ;

    Inorder( root->left , count );
    if( root->left==NULL && root->right==NULL)
        count++ ;
    Inorder( root->right , count ) ;
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0 ;
    Inorder(root , count ) ;
    return count ;
}