#include<iostream>
using namespace std ;

// For Creating A Node Type data Structure
class Node{
    public:
        int data ;
        Node* next ;

        // Constructor
        Node(int data){
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
void Print(Node* &head){
    Node * temp = head ;
    while ( temp != NULL ) {
        cout<< temp->data <<" ";
        temp = temp->next ;
    }
    cout<<endl ;
}


// Function to Insert New Node at Starting/Head Position in LL
void InsertAtHead(Node* & head , int data ){
    Node* temp = new Node(data) ;
    temp -> next = head ;
    head = temp ;
}

// Function to Insert New Node at Ending/Tail Position in LL
void InsertAtTail(Node* & tail  , int data ){
    Node* temp = new Node(data) ;
    tail -> next = temp ;
    tail = temp ;
}

// Function to Insert New Node at Particular Position in LL
void InsertAtPosition(Node* & head ,Node* & tail  , int position , int data ){
    // Insert at Start
    if( position == 1 ){
        InsertAtHead(head,data) ;
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
        InsertAtTail(tail,data) ;
        return ;
    }

    // creating a new node to insert data
    Node * NodeToInsert = new Node(data) ;  
    NodeToInsert -> next = temp -> next ;
    temp -> next = NodeToInsert ;
}

// Function to Delete a Node at Particular Position in LL
void DeleteAtPosition(Node* & head , Node* & tail , int position ){
    
    // Deleting First or Starting Node
    if(position == 1 ){
        Node * temp = head ;
        head = head->next ;
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

        prev -> next = curr->next ;
        curr->next = NULL ;

        // if deleting Node is Last Node
        if( curr == tail )
            tail = prev ;
        delete curr ;
    }

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

int main(){

    //Head Means Node which are pointing to first Node of LL

    Node * node1 = new Node(5) ;
    // cout<< "Data ==>> " << node1->data <<endl;
    // cout<< "PTR  ==>> " << node1->next <<endl;

    Node* head = node1 ;
    Node* tail = node1 ;

    Print(head) ;
    
    // InsertAtHead(head , 3) ;
    InsertAtTail(tail,3) ;
    
    Print(head) ;
    
    // InsertAtHead(head , 7) ;
    InsertAtTail(tail,7) ;
    
    Print(head) ;

    InsertAtPosition(head ,tail, 2 , 18) ;

    Print(head) ;

    InsertAtPosition(head ,tail, 3 , 87) ;
    Print(head) ;

    InsertAtPosition(head ,tail, 1 , 100) ;
    Print(head) ;

    InsertAtPosition(head ,tail, 7 , 200) ;
    Print(head) ;

    DeleteAtPosition(head , tail , 3) ;
    Print(head) ;

    DeleteAtPosition(head , tail , 1) ;
    Print(head) ;

    DeleteAtPosition(head , tail , 5) ;
    Print(head) ;

    DeleteAtPosition(head , tail , 1) ;
    Print(head) ;

    DeleteAtPosition(head , tail , 3) ;
    Print(head) ;
    
    cout<< "head ==>> " << head->data <<endl;
    cout<< "tail ==>> " << tail->data <<endl;

    cout<<"Length of LL : "<< getLength(head) ;
    
    return 0 ;
}
