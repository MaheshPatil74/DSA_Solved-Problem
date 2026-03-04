// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

// Approach 1 ==>> timeComplexity is high but low space complexity
class Solution {
  private :
  
    int findPosition(vector<int> inorder, int element , int n){
        for(int i = 0 ; i<n ; i++){
            if(inorder[i]==element)
                return i;
        }
        return -1 ;
    }
    
    Node* solve(vector<int> inorder, vector<int> preorder, int & index , int inorderStart , int inorderEnd , int n){
        // base case
        if(index>=n || inorderStart>inorderEnd ){
            return NULL ;
        }
        
        int element = preorder[index++] ;
        Node* root = new Node(element) ;
        int position = findPosition(inorder,element,n) ;
        
        // recursive call
        root->left = solve(inorder,preorder,index,inorderStart,position-1,n) ;
        root->right = solve(inorder,preorder,index,position+1,inorderEnd,n) ;
        
        return root ;
    }
    
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0 ;
        int n = inorder.size() ;
        Node* ans = solve(inorder,preorder,preOrderIndex,0,n-1,n) ;
        return ans ;
    }
};

// Approach 2 ==>> timeComplexity is low but space complexity  increase because of map
class Solution {
  private :
  
    void createMapping(vector<int> inorder, map<int,int> & nodeToIndex , int n){
        for(int i = 0 ; i<n ; i++)
            nodeToIndex[inorder[i]] = i ;
    }
    
    Node* solve(vector<int> inorder, vector<int> preorder, int & index , int inorderStart , int inorderEnd , int n , map<int,int> & nodeToIndex){
        // base case
        if(index>=n || inorderStart>inorderEnd ){
            return NULL ;
        }
        
        // create a root node for element
        int element = preorder[index++] ;
        Node* root = new Node(element) ;
        
        // find element index in Inorder
        int position = nodeToIndex[element] ;
        
        // recursive call
        root->left = solve(inorder,preorder,index,inorderStart,position-1,n, nodeToIndex) ;
        root->right = solve(inorder,preorder,index,position+1,inorderEnd,n,nodeToIndex) ;
        
        return root ;
    }
    
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0 ;
        int n = inorder.size() ;
        map<int,int> nodeToIndex ;
        
        // create node to index mapping
        createMapping(inorder,nodeToIndex,n);
        
        Node* ans = solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex) ;
        return ans ;
    }
};