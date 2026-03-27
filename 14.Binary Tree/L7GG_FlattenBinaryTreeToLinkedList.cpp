// User function Template for C++
// we use concept of morris traversal technique here as question have limitation to solve in SC = O(1) 
class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* curr = root ;
        
        while(curr != NULL ){
            if( curr->left ){
                Node* pred = curr->left ;
                while( pred->right)
                    pred = pred->right ;
                    
                pred->right = curr->right ;
                curr->right = curr->left ;
            }
            curr = curr->right ;
        }
        
        // left paart Null 
        curr = root ;
        while( curr != NULL ){
            curr->left =NULL ;
            curr = curr->right ;
        }
    }
};