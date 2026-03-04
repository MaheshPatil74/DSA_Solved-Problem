#include<iostream>
#include<queue>
using namespace std ;

class node{
    public : 
        int data ;
        node* left ;
        node* right ;
    
        node( int data){
            this->data = data ;
            this->left = NULL ;
            this->right = NULL ;
        }   
};

node* buildTree( node* root ){
    cout<<"Enter The Data : ";
    int data ;
    cin>>data ;
    root = new node(data) ; 
    if( data == -1 )
        return NULL ;

    cout<<"Enter The data for inserting left of "<<data<<endl ;
    root->left = buildTree( root->left );
    cout<<"Enter The data for inserting Right of "<<data<<endl ;
    root->right = buildTree( root->right );
    return root ;
}

void levelOrderTraversal( node * root ){
    queue<node*> q ;
    q.push( root ) ;
    q.push( NULL ) ;

    while( !q.empty() ){
        node* temp = q.front() ;
        q.pop() ;
        
    }
}


int main(){
    node * root = NULL ;
    root = buildTree(root) ;
    /*
    // Inorder Traversal of Tree
    cout<<"Inorder Traversal of Tree : " ;
    Inorder(root) ;
    cout<<endl ;

    // Preorder Traversal of Tree
    cout<<"Preorder Traversal of Tree : ";
    Preorder(root) ;
    cout<<endl ;

    // Postorder Traversal of Tree
    cout<<"Postorder Traversal of Tree : ";
    Postorder(root) ;
    cout<<endl ;
    */

    // Level order Traversal
    cout <<endl<< "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root) ;

    buildFromLevelOrder(root) ;
    cout <<endl<< "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root) ;
}