// All another traversal technique have TC = O(n) ans SC = O(n)

// Note==>> this is one of important traversal technique of binary tree
// Morris traversal
// TC = O(n) ans SC = O(1)

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        Node* curr = root;
    
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // If no left child, visit this node 
                // and go right
                res.push_back(curr->data);
                curr = curr->right;
            }
            else {
                // Find the inorder predecessor of curr
                Node* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr)
                    prev = prev->right;
    
                // Make curr the right child of its 
                // inorder predecessor
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } 
                else {
                    // Revert the changes made in 
                    // the tree structure
                    prev->right = nullptr;
                    res.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return res; 
    }
};