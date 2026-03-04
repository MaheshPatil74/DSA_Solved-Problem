#include<iostream>
#include<map>
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
void print(Node* &tail){

    Node * temp = tail ;
    
    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do{
        cout<< tail->data <<" ";
        tail = tail->next ;
    }
    while ( tail != temp );
    cout<<endl ;
}

void insertNode(Node* & tail , int element , int data ){

    // When LL is empty
    if(tail == NULL){
        Node * temp = new Node(data) ;
        tail = temp ;
        temp->next = temp ;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        Node * curr = tail ;

        while( curr -> data != element )
            curr = curr -> next ;

        //here current point to node having data equals to element ;
        Node * temp = new Node(data) ;
        temp -> next = curr -> next ;
        curr -> next = temp ;
    }
}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL)
        return true;

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) 
        temp = temp -> next;

    if(temp == head ) 
        return true;
    return false;
}

bool detectLoop(Node* head) {
    if(head == NULL)
        return false;
    map<Node*, bool> visited;

    Node* temp = head;
    while(temp !=NULL) {
        //cycle is present
        if(visited[temp] == true) {
            cout<< "Present on Element : "<< temp->data <<endl ;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}


// THere is Algorithm ==>> Floys cycle Detection Algo
// Helps to detect loop in optimised way 
// Time Complexity = O(n) && Space Complexity = O(1)
Node * floydCyleDetectAlgo(Node * head ){
    if(head == NULL ){
        return NULL ;
    }

    Node * slow = head ;
    Node * fast = head ;

    while( slow!=NULL && fast!=NULL ){
        fast = fast->next ;
        if( fast != NULL ){
            fast = fast->next ;
        }
        slow = slow->next ;

        if( slow == fast ){
            cout<<" Cycle present at Element : "<< slow -> data <<endl ;
            return slow ;
        }
    }
    return NULL ;
}


int main(){
    Node * tail = NULL ;
    
    insertNode(tail , 5, 3 );
    print(tail) ;
    
    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
   

    deleteNode(tail, 5);
    print(tail);


    if(isCircularList(tail)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }

    if(floydCyleDetectAlgo(tail)) != NULL {
        cout << " Cycle is Present " << endl;
    }
    else{
        cout << " Cycle is Absent  " << endl;
    }   

}