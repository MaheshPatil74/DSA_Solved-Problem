/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root , vector<int>& arr ){
    if( root == NULL )
        return ;

    inorder(root->left , arr ) ;
    arr.push_back(root->data) ;
    inorder(root->right , arr ) ;
}

TreeNode<int>* inorderToBST(int start , int end , vector<int> arr ){
    // base case
    if( start>end )
        return NULL ;

    int mid = (start + end)/2 ;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]) ;
    root->left = inorderToBST(start, mid-1 , arr);
    root->right = inorderToBST(mid+1,end,arr) ;
    return root ;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> arr ;

    // store inorder sorted values
    inorder(root , arr) ;
    int n = arr.size() ;

    return inorderToBST(0,n-1,arr) ;
}
