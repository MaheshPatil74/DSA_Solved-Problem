#include<iostream>
#include<queue>
using namespace std ;

class node{
    public:
        int data ;
        node * left ;
        node * right ;

    node(int data){
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

node * buildTree( node * root){
    cout<<"Enter the data : ";
    int data ;
    cin>>data ;
    root = new node(data) ;

    if( data == -1 ){
        return NULL ; 
    }

    cout<<"Enter data for inserting left of "<<data<<endl;
    root->left = buildTree(root->left) ;
    cout<<"Enter data for inserting right of "<<data<<endl;
    root->right = buildTree(root->right) ;
    return root ;
}

void Inorder(node * root ){
    if( root == NULL ){
        return ;
    }
    Inorder(root->left) ;
    cout<< root->data <<" " ;
    Inorder(root->right) ;
}

void Preorder(node * root ){
    if( root == NULL ){
        return ;
    }
    cout<< root->data <<" " ;
    Preorder(root->left) ;
    Preorder(root->right) ;
}

void Postorder(node * root ){
    if( root == NULL ){
        return ;
    }
    Postorder(root->left) ;
    Postorder(root->right) ;
    cout<< root->data <<" " ;
}

void levelOrderTraversal(node * root){
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while( !q.empty() ){
        node * temp = q.front() ;
        q.pop() ;

        if(temp==NULL){
            cout<<endl ;
            if( !q.empty() ){
                q.push(NULL) ;
            }
        }
        else{
            cout<<temp->data<<" ";
            if( temp->left ){
                q.push(temp->left) ;
            }
            if( temp->right ){
                q.push(temp->right) ;
            }
        }
    }
}

void buildFromLevelOrder( node * & root ){
    queue<node * > q ;
    cout<<"Enter the data for Root : ";
    int data ;
    cin>>data ;
    root = new node(data) ;
    q.push(root) ;
    while( !q.empty() ){
        node * temp = q.front() ;
        q.pop() ;

        cout<<"Enter Left Node For "<<temp->data<<endl ;
        int leftData ;
        cin>>leftData ;
        if(leftData != -1 ){
            temp->left = new node(leftData) ;
            q.push(temp->left) ;
        }

        cout<<"Enter right Node For "<<temp->data<<endl ;
        int rightData ;
        cin>>rightData ;
        if(rightData != -1 ){
            temp->right = new node(rightData) ;
            q.push(temp->right) ;
        }
    }
}

int main(){
    node * root = NULL ;
    /*
    root = buildTree(root) ;

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

    // Level order Traversal
    cout <<endl<< "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root) ;
    */

    buildFromLevelOrder(root) ;
    cout <<endl<< "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root) ;
}