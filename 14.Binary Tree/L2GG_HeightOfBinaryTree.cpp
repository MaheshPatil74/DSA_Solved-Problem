/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Approach  :
// TC = O(n) ans SC = O(height)
// For Skew Tree : height = No.of Node(n) ==> hence : TC = O(n) ans SC = O(n) = O(height)

class Solution {
  private :
    int solve( Node * node){
        if(node==NULL){
            return 0 ;
        }
        int left = solve(node->left) ;
        int right = solve(node->right) ;
        return 1 + max(left,right) ;
    }
  public:
    int height(Node* node) {
        // code here
        int temp = solve(node) ;
        return temp - 1 ;       //we consider edges here so -1 .
    }
};
