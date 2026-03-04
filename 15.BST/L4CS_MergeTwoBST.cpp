/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
// Approach 1 : TC = O(m+n) && SC = O(m+n)
void inorder(TreeNode *root , vector<int>& arr){
    if( root == NULL )
        return ;

    inorder(root->left,arr) ;
    arr.push_back(root->data) ;
    inorder(root->right , arr);
}

vector<int> mergeArrays(vector<int>& a , vector<int>& b ){
    vector<int> ans(a.size() + b.size()) ;

    int i = 0 , j=0 ;
    int k = 0 ;
    while(i<a.size() && j<b.size() ){
        if(a[i]<b[j] ){
            ans[k++] = a[i++];
        }
        else{
            ans[k++] = b[j++] ;
        }
    }
    while(i<a.size() ){
        ans[k++] = a[i++];
    } 
    while(j<b.size() ){
        ans[k++] = b[j++];
    } 
    return ans ;
}

TreeNode* inorderToBST(int start , int end , vector<int> arr ){
    // base case
    if( start>end )
        return NULL ;

    int mid = (start + end)/2 ;
    TreeNode* root = new TreeNode(arr[mid]) ;
    root->left = inorderToBST(start, mid-1 , arr);
    root->right = inorderToBST(mid+1,end,arr) ;
    return root ;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // step 1 : store inorders
    vector<int> bst1 , bst2 ;
    inorder(root1,bst1) ;
    inorder(root2,bst2) ;

    // step 2 : merge both sorted array
    vector<int> mergeArray = mergeArrays(bst1,bst2) ;
    
    // step 3 : use merged inorder array to buil tree
    // int n = mergeArray.size() ;
    // int s = 0 , e = n-1 ;
    // return inorderToBST(s,e,mergeArray) ;

    // but in sir question ==>> node of two merge BST have to be returned 
    // so we have to done step 3 but in my quetion only sorted list have to be asked so directly we returnesd a mergeArray
    return mergeArray ;    
}

// Approach 2 : TC = O(m+n) && SC = O(H1 + H2)
// conversion to sorted doubly LL
void convertIntoSortedDLL(TreeNode *root1 , TreeNode* head ){
    // base case
    if( root == NULL )
        return NULL ;
    
    convertIntoSortedDLL(root->right , head) ;

    root->right = head ;

    if(head!=NULL)
        head->left = root ;

    head = root ;

    convertIntoSortedDLL(root->left , head) ;
}

TreeNode* mergeLinkedList(TreeNode* head1 , TreeNode* head2){
    TreeNode* head = NULL ;
    TreeNode* tail = NULL ;

    while(head1!=NULL && head2!=NULL ){
        if( head1->data < head2->data){
            if( head==NULL){
                head = head1 ;
                tail = head1 ;
                head1 = head1->right ;
            }
            else{
                tail->right = head1 ;
                head1->left = tail ;
                tail = head1 ;
                head1 = head1->right ;
            }
        }
        else{
            if( head==NULL){
                head = head2 ;
                tail = head2 ;
                head2 = head2->right ;
            }
            else{
                tail->right = head2 ;
                head2->left = tail ;
                tail = head2 ;
                head2 = head2->right ;
            }
        }
    }

    while( head1 != NULL ){
        tail->right = head1 ;
        head1->left = tail ;
        tail = head1 ;
        head1 = head1->right ;
    }

    while( head2 != NULL ){
        tail->right = head2 ;
        head2->left = tail ;
        tail = head2 ;
        head2 = head2->right ;
    }
    return head ;
}

int countNode(TreeNode* head ){
    int count = 0 ; 
    TreeNode* temp = head ;

    while( temp!=NULL ){
        count++ ;
        temp = temp->right ;
    }
    return count ;
}

TreeNode* soretedLLToBST(TreeNode* head, int n){
    // base case
    if( n<=0 || root==NULL ){
        return NULL ;
    }

    TreeNode* left = soretedLLToBST(head,n/2);
    TreeNode* root = head ;
    root->left = left ;

    head = head->next ;
    root->right = soretedLLToBST(head,n-n/2-1);
    return root ;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2){
    // step 1 : convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL ;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL ;

    TreeNode* head2 = NULL ;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL ;

    // step2 : merge sorted LL
    TreeNode* head = mergeLinkedList( head1 , head2 );

    // step 3 : convert Sorted LL 
    return soretedLLToBST( head , countNode(head)) ;
}