// Approach 2 :
// TC = O(n) 
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
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
        ans.first = (leftAns && rightAns && diff) ;
        return ans;
    }

    bool isBalanced(Node *root){
        return isBalancedFast(root).first;
    }  
};


// Approach 1 :
// TC = O(n*n) 
class Solution {
  private :
    int height( Node * root){
        if( root == NULL )
            return 0 ;
        return 1 + max(height(root->left),height(root->right)) ;
    }
  public:
    bool isBalanced(Node* root) {
        if( root == NULL )
            return true ;
        
        bool left = isBalanced(root->left) ;
        bool right = isBalanced(root->right) ;
        bool diff = abs(height(root->left) - height(root->right)) <= 1 ;
        
        return ( left && right && diff ) ; 
    }
};