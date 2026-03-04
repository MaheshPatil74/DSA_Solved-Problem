#include<iostream>
using namespace std ;

// For Creating A Node Type data Structure
class Node{
    public:

    Node * prev ;
    int data ;
    Node * next ;

    Node(int data){
        this -> prev = NULL ;
        this -> data = data ;
        this -> next = NULL ;
    }

    // Destructor
    ~Node(){
        int value = this->data ;
        //memory Free
        if(this->next != NULL ){
            delete next ;
            this->next = NULL ;
        }
        cout<<"Memory Free For Node With Data ==>> "<<value<<endl ;
    }
};

// Function For Traversing/Printing of LL
void print( Node * & head ){
    Node * temp = head ;
    while( temp != NULL ){
        cout<< temp -> data <<" ";
        temp = temp -> next ;
    }
    cout<<endl;
}

// To find length of Linked-List
int getLength(Node * & head ){
    int len = 0 ;
    Node * temp = head ;

    while( temp != NULL ){
        len++ ;
        temp = temp->next ;
    }
    return len ;
}

// Function to Insert New Node at Starting/Head Position in LL
void InsertAtHead(Node* & head ,Node* & tail , int data){
    Node * temp = new Node(data) ;
    
    // When list is empty
    if(head==NULL){
        head = temp ;
        tail = temp ;
    }
    else{
        head->prev = temp ;
        temp->next = head ;
        head = temp ;
    }
}

// Function to Insert New Node at Ending/Tail Position in LL
void InsertAtTail(Node* & head ,Node* & tail  , int data ){
    Node * temp = new Node(data) ;
    if(tail==NULL){
        head = temp ;
        tail = temp ;
    }
    else{
        temp->prev = tail ;
        tail -> next = temp ;
        tail = temp ;
    }
}

// Function to Insert New Node at Particular Position in LL
void InsertAtPosition(Node* & head ,Node* & tail  , int position , int data ){
    // Insert at Start
    if( position == 1 ){
        InsertAtHead(head,tail,data) ;
        return ;
    }

    Node* temp = head ;
    int count = 1 ;

    while( count < position-1 ){
        temp = temp->next ;
        count++ ;
    }

    // Insert at Last Position
    if( temp->next == NULL ){
        InsertAtTail(head,tail,data) ;
        return ;
    }

    // creating a new node to insert data
    Node * NodeToInsert = new Node(data) ;

    NodeToInsert -> next = temp -> next ;
    NodeToInsert -> prev = temp ;
    temp->next->prev = NodeToInsert ;
    temp -> next = NodeToInsert ;
}

// Function to Delete a Node at Particular Position in LL
void DeleteAtPosition(Node* & head , Node * tail , int position ){
    
    // Deleting First or Starting Node
    if(position == 1 ){
        Node * temp = head ;
        temp->next->prev = NULL ; 
        head = temp->next ;
        //Memory Free For Start Node
        temp->next = NULL ;
        delete temp ;
    }
    else{ //Deleting any middle or last node

        Node * curr = head ;
        Node * prev = NULL ;

        int count = 1 ;
        while( count < position ){
            prev = curr ;
            curr = curr->next ;
            count++ ;
        }
        // if deleting Node is Last Node
        if( curr == tail ){
            tail = tail->prev;
            tail->next=NULL;
        }
        else{
            prev->next = curr->next ;
            curr->next->prev =curr->prev ;
        }
        curr->prev = NULL ;
        curr->next = NULL ; 
        delete curr ;
        

       /* prev->next = curr->next ;
        curr->prev = NULL ;
        curr->next = NULL ;        

        

        delete curr ;*/
    }
}

int main(){
    // Node * node1 = new Node(5) ;

    // cout<< "Prev ==>> " << node1->prev <<endl;
    // cout<< "Data ==>> " << node1->data <<endl;
    // cout<< "Next  ==>> " << node1->next <<endl;

    // Node * head = node1 ;
    // Node * tail = node1 ;

    Node * head = NULL ;
    Node * tail = NULL ;

    print(head) ;
    // cout<<"Length of LL : "<<getLength(head)<<endl ;

    InsertAtHead(head,tail , 7) ;
    print(head) ;

    InsertAtHead(head,tail , 8) ;
    print(head) ;

    InsertAtHead(head,tail , 9) ;
    print(head) ;

    InsertAtHead(head,tail , 10) ;
    print(head) ;

    InsertAtTail(head,tail , 4) ;
    print(head) ;

    InsertAtTail(head,tail , 100) ;
    print(head) ;

    InsertAtPosition(head,tail,3,50);
    print(head) ;

    InsertAtPosition(head,tail,1,60);
    print(head) ;

    InsertAtPosition(head,tail,8,150);
    print(head) ;

    cout<< "head ==>> " << head->data <<endl;
    cout<< "tail ==>> " << tail->data <<endl;

    DeleteAtPosition(head,tail,3) ;
    print(head) ;

    DeleteAtPosition(head,tail,1) ;
    print(head) ;

    DeleteAtPosition(head,tail,7) ;
    print(head) ;

    cout<< "head ==>> " << head->data <<endl;
    cout<< "tail ==>> " << tail->data <<endl;
    return 0 ;
}