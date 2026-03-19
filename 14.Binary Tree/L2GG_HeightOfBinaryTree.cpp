// For Skew Tree : height = No.of Node(n) ==> hence : TC = O(n) ans SC = O(n) = O(height)

// approach 2 :
class Solution {
  public:
    int height( Node * root){
        if( root == NULL )
            return 0 ;
        return 1 + max(height(root->left),height(root->right)) ;
    }
};

    

// Approach 1 :
// TC = O(n) ans SC = O(height)
class Solution {
  private :
    int solve( Node * node){
        if(node==NULL)
            return 0 ;
        int left = solve(node->left) ;
        int right = solve(node->right) ;
        return 1 + max(left,right) ;
    }
  public:
    int height(Node* node) {
        int temp = solve(node) ;
        return temp - 1 ;       //we consider edges here so -1 .
    }
};
