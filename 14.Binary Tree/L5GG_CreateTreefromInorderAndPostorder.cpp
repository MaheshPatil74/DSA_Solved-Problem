/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  private :
  
    void createMapping(vector<int> inorder, map<int,int> & nodeToIndex , int n){
        for(int i = 0 ; i<n ; i++)
            nodeToIndex[inorder[i]] = i ;
    }
    
    Node* solve(vector<int> inorder, vector<int> postorder, int & index , int inorderStart , int inorderEnd , int n , map<int,int> & nodeToIndex){
        // base case
        if(index<0 || inorderStart>inorderEnd ){
            return NULL ;
        }
        
        // create a root node for element
        int element = postorder[index--] ;
        Node* root = new Node(element) ;
        
        // find element index in Inorder
        int position = nodeToIndex[element] ;
        
        // recursive call
        root->right = solve(inorder,postorder,index,position+1,inorderEnd,n,nodeToIndex) ;
        root->left = solve(inorder,postorder,index,inorderStart,position-1,n, nodeToIndex) ;
        
        return root ;
    }
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int n = inorder.size() ;
        int postOrderIndex = n-1 ;
        map<int,int> nodeToIndex ;
        
        // create node to index mapping
        createMapping(inorder,nodeToIndex,n);
        
        Node* ans = solve(inorder,postorder,postOrderIndex,0,n-1,n,nodeToIndex) ;
        return ans ;
        
    }
};