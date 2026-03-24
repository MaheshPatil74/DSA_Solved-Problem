class Solution {
  public:
    Node* solve(Node* root, int &k, int node) {
        //base case
        if(root == NULL)
            return NULL;
            
        if(root->data == node) 
            return root;
        
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);
    
        //wapas
        if(leftAns != NULL && rightAns == NULL) {
            k--;
            if(k<=0) {
                //answer lock
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }
        
        if(leftAns == NULL && rightAns != NULL) {
            k--;
            if(k<=0) {
                //answer lock
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        return NULL;
    }
    
    int kthAncestor(Node *root, int k, int node)
    {
        Node* ans = solve(root, k, node);
        // to much imp edge case in below line==>after OR condition
        return (ans == NULL || ans->data == node) ? -1 : ans->data ;
    }
};
