// In Insertion , deletion and search :
// Time complexity ==>> O(H)
// Worst Time complexity ==>> O(n) 
#include<iostream>
#include<queue>
using namespace std ; 
class Node{
    public :
        int data ;
        Node* left ;
        Node* right ;
    Node( int data ){
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

// for insertion in BST ==>> TC = O(logN) = O(H) 
Node* insertIntoBST(Node* root , int data ){
    // base case
    if(root==NULL){
        root = new Node(data) ;
        return root ;
    }

    if( data > root->data ){
        // right part main insert karna hain
        root->right = insertIntoBST(root->right , data ) ;
    }

    else{
        // left part main insert karna hain
        root->left = insertIntoBST(root->left , data );
    }
    return root ;
}

void takeInput(Node* & root){
    int data ;
    cin>>data ;
    while( data != -1 ){
        root = insertIntoBST(root,data);
        cin>> data ;
    }
}

void levelOrderTraversal(Node * root){
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;
    while( !q.empty() ){
        Node* temp = q.front() ;
        q.pop() ;
        if( temp == NULL ){
            cout<<endl ;
            if( !q.empty() )
                q.push(NULL) ;
        }
        else{
            cout<< temp->data <<" ";
            if(temp->left)
                q.push(temp->left) ;
            if(temp->right)
                q.push(temp->right) ;
        }
    }
}

// Note ==>> Inorder Traversal of BST always Sorted
void inorderTraversal(Node*root){
    if(root==NULL)
        return ;
    inorderTraversal(root->left) ;
    cout<< root->data <<" " ;
    inorderTraversal(root->right) ;
}

void preorderTraversal(Node*root){
    if(root==NULL)
        return ;
    cout<< root->data <<" " ;
    preorderTraversal(root->left) ;
    preorderTraversal(root->right) ;
}

void postorderTraversal(Node*root){
    if(root==NULL)
        return ;
    postorderTraversal(root->left) ;
    postorderTraversal(root->right) ;
    cout<< root->data <<" " ;
}

// Recursive Way ==>> TLE problem in below code as TC = O(H) and SC = O(H)
bool searchInBST1(Node *root, int x) {
    // Write your code here.
    if(root==NULL)
        return false ;

    if(root->data == x )
        return true ;

    if( x < root->data ){
        // left part 
        return searchInBST1(root->left,x) ;
    }
    else
        // right part
        return searchInBST1(root->right,x) ;
}

// Iterative Way ==>> TC = O(H) and SC = O(1)
bool searchInBST2(Node *root, int x) {
    Node* temp = root ;
    while(temp!=NULL){
        if( x == temp->data )
            return true ;
        if( x < temp->data )
            temp = temp->left ;
        else
            temp = temp->right ;        
    }
    return false ;
}

Node * minValue( Node *& root ){
    Node* temp = root ;
    while( temp->left != NULL )
        temp = temp->left ;
    return temp ;
} 

Node * maxValue( Node *& root ){
    Node* temp = root ;
    while( temp->right != NULL )
        temp = temp->right ;
    return temp ;
} 

Node * inorderPredecessor( Node * root ){
    if( root == NULL || root->left == NULL )
        return NULL ;

    Node* temp = root->left ;
    while( temp->right )
        temp = temp->right ;
    return temp ;
} 

Node * inorderSuccessor( Node * root ){
    if( root == NULL || root->right == NULL )
        return NULL ;

    Node* temp = root->right ;
    while( temp->left )
        temp = temp->left ;
    return temp ;
} 

// Most Imp that is deletion of node in BST
Node* deleteFromBST(Node* root , int val){
    if(root==NULL)
        return root ;

    if( root->data == val ){
        // 0 child
        if( root->left == NULL && root->right==NULL ){
            delete root ;
            return NULL ;
        }

        // 1 child
        // left child
        if( root->left != NULL && root->right==NULL ){
            Node* temp = root->left ;
            delete root ;
            return temp ;
        }
        //right child
        if( root->left == NULL && root->right != NULL ){
            Node* temp = root->right ;
            delete root ;
            return temp ;
        }

        // 2 child
        if( root->left != NULL && root->right != NULL ){
            int mini = minValue(root->right)->data ;
            root->data = mini ;
            root->right = deleteFromBST(root->right,mini);
            return root ;

            /*
            //here is approach but slight changes are done to correct it
            Node* mini = inorderPredecessor(root);
            delete root ;
            return mini ;
            */
        }
    }
    else if( root->data > val ){
        // left part main jao
        root->left = deleteFromBST(root->left,val) ;
        return root ;
    }
    else{
        // right part main jao
        root->right = deleteFromBST(root->right,val) ;
        return root ;
    }
}

int main(){
    Node* root = NULL ; 
    cout<<"Enter Data to create BST : "<<endl;
    takeInput(root) ;

    // 10 8 21 7 27 5 4 3 -1
    cout<<"Printing BST : "<<endl;
    cout<<endl <<"Level Order Traversal : "<<endl ;
    levelOrderTraversal(root) ;

    cout<<endl <<"In-Order Traversal : ";
    inorderTraversal(root) ;
    cout<<endl <<"Pre-Order Traversal : ";
    preorderTraversal(root) ;
    cout<<endl <<"Post-Order Traversal : ";
    postorderTraversal(root) ;
    cout<<endl ;

    cout<<endl<<"Min-value : "<< minValue(root)->data <<endl ;
    cout<<endl<<"Max-value : "<< maxValue(root)->data <<endl ;

    Node* pred = inorderPredecessor(root);
    if (pred)
        cout<<endl<<"InOrder Predecessor : "<< pred->data <<endl ;
    else
        cout<<endl<<"InOrder Predecessor : None"<<endl ;

    Node* succ = inorderSuccessor(root);
    if (succ)
        cout<<endl<<"InOrder Successor : "<< succ->data <<endl ;
    else
        cout<<endl<<"InOrder Successor : None"<<endl ;

    int choice ;
    do{
        int key ;
        cout<<"Enter The Value tobe Search in BST : ";
        cin>>key ;

        if(searchInBST1(root,key))
            cout<<key<<" is Found in BST."<<endl ;
        else    
            cout<<key<<" is Not Found in BST."<<endl;
        
        cout<<"Do you want to search another value in BST ? (1/0) : ";
        cin>>choice ;
    }
    while(choice != 0 ) ;

    // deletion
    cout<<"Enter the value tobe want to delete from BST : ";
    int val ;
    cin>>val ;
    root = deleteFromBST(root,val) ;

    cout<<"Printing BST : "<<endl;
    cout<<endl <<"Level Order Traversal : "<<endl ;
    levelOrderTraversal(root) ;
}