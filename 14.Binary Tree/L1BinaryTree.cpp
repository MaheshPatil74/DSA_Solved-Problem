#include<iostream>
#include<queue>
using namespace std ;

class Node{
    public :
        int data ;
        Node * left ;
        Node * right ;
        
    Node(int data ){
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

Node * buildTree( Node * root ){
    cout<<"Enter The data : ";
    int data ;
    cin>>data ;
    root = new Node(data) ;
    
    if( data == -1 ){
        return NULL ;
    }
    
    cout<<"Enter the data for Inserting Left of "<<data<<endl ;
    root->left = buildTree( root->left ) ;
    cout<<"Enter the data for Inserting Right of "<<data<<endl ;
    root->right = buildTree( root->right ) ;
    return root ;
}

// Level order Travesal ==>> Breath First Search
void levelOrderTraversal( Node * root ){
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;
    
    while( !q.empty() ){
        Node * temp = q.front() ;
        q.pop() ;
        
        if( temp == NULL ){
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if( !q.empty() )
                q.push(NULL) ;      //queue still has some child nodes
        }
        else{
            cout<<temp->data<< " ";
            if(temp->left)
                q.push(temp->left) ;
            if(temp->right)
                q.push(temp->right) ;
        }
    }
}

void Inorder( Node * root ){
    if( root == NULL )
        return ;
    Inorder(root->left) ;
    cout << root->data << " " ; 
    Inorder(root->right) ;
}

void Preorder( Node * root ){
    if( root == NULL )
        return ;
    cout << root->data << " " ; 
    Preorder(root->left) ;
    Preorder(root->right) ;
}

void Postorder( Node * root ){
    if( root == NULL )
        return ;
    Postorder(root->left) ;
    Postorder(root->right) ;
    cout << root->data << " " ;
}

void buildFromLevelOrder(Node * & root ){
    queue<Node*> q ;
    cout<<"Enter The Data for Root : ";
    int data ;
    cin>>data ;
    root = new Node(data) ;

    q.push(root) ;

    while( !q.empty() ){
        Node * temp = q.front() ;
        q.pop() ;

        cout<<"Enter Left Node for : "<< temp->data <<endl;
        int leftdata ;
        cin>>leftdata ;
        if(leftdata != -1 ){
            temp->left = new Node(leftdata) ;
            q.push(temp->left) ;
        }

        cout<<"Enter Right Node for : "<< temp->data <<endl;
        int rightdata ;
        cin>>rightdata ;
        if(rightdata != -1 ){
            temp->right = new Node(rightdata) ;
            q.push(temp->right) ;
        }
    }
}

int main() {
    Node * root = NULL ;
    
    /*
    // creating a tree
    root = buildTree(root) ;
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 
    
    // Level order Travesal
    cout <<endl<< "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root) ;

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

    buildFromLevelOrder(root) ;
    levelOrderTraversal(root) ;

    return 0;
}