/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

// Approach 1 :
// TC = O(n*n) 
class Solution {
  private :
    int height( Node * root){
        if( root == NULL ){
            return 0 ;
        }
        return 1 + max(height(root->left),height(root->right)) ;
    }
  
  public:
    bool isBalanced(Node* root) {
        // Code here
        if( root == NULL ){
            return true ;
        }
        
        bool left = isBalanced(root->left) ;
        bool right = isBalanced(root->right) ;
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1 ;
        
        if( left && right && diff ){
            return true ;
        }
        else{
            return false ;
        }
    }
};

// Approach 2 :
// TC = O(n) 
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
        // base case
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }

    bool isBalanced(Node *root)
    {
        // write your code here
        return isBalancedFast(root).first;
    }  
};
