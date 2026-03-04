// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  private :
    // TC = O(n) and SC = O(n)
    int countNodes( Node* root ){
        if(root == NULL )
            return 0 ;
        
        int ans = 1 + countNodes(root->left) + countNodes(root->right) ;
        return ans ;
    }
    
    // TC = O(n) and SC = O(n)
    bool isCBT(Node * root , int index , int count ){
        if( root == NULL )
            return true ;
            
        if(index>=count){
            return false ;
        }
        else{
            bool left = isCBT(root->left,2*index+1,count) ;
            bool right = isCBT(root->right,2*index+2,count) ;
            return ( left && right ) ;
        }
    }
    
    // TC = O(n) and SC = O(n)
    bool isMaxOrder( Node * root ){
        // leaf Node
        if( root->left ==NULL && root->right==NULL )
            return true ;
        if( root->right == NULL ){
            return (root->data > root->left->data) ;
        }
        else{
            bool left = isMaxOrder( root->left ) ;
            bool right = isMaxOrder( root->right ) ;
            
            return ( left && right && ( root->data > root->left->data && root->data > root->right->data ));
        }
    }
  public:
    // TC = O(n) and SC = O(n)
    bool isHeap(Node* tree) {
        // code here
        int index = 0 ;
        int totalNodes  = countNodes(tree) ;
        if( isCBT(tree,index,totalNodes) && isMaxOrder(tree) )
            return true ;
        return false ;
    }
};