void inorder(TreeNode<int>* root , vector<int>& arr ){
    if( root == NULL )
        return ;

    inorder(root->left , arr ) ;
    arr.push_back(root->data) ;
    inorder(root->right , arr ) ;
}

TreeNode<int>* inorderToBST(int start , int end , vector<int> arr ){
    if( start>end )
        return NULL ;

    int mid = (start + end)/2 ;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]) ;
    root->left = inorderToBST(start, mid-1 , arr);
    root->right = inorderToBST(mid+1,end,arr) ;
    return root ;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> arr ;

    // store inorder sorted values
    inorder(root , arr) ;
    int n = arr.size() ;
    return inorderToBST(0,n-1,arr) ;
}
