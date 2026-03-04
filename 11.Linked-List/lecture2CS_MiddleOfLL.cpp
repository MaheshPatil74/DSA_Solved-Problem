/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

//Approach 1 ==>> having TC = T(n)
//Function for finding length of LL
int getLength(Node * head ){
    int len = 0 ;

    while(head != NULL ){
        head = head->next ;
        len++ ;
    }
    return len ;
}

Node *findMiddle(Node *head) {
    // Write your code here

    /*
    //Approach 1 : having TC = T(n)
    int len = getLength(head) ;
    int ans = len/2 ;

    int count = 0 ;
    Node * temp = head ;

    while( count < ans ){
        temp = temp->next ;
        count++ ;
    }
    return temp ;
    */

    //Approach 2 : Optimised Approach : having TC = 

}

// ********************************************************

//Approach 2 ==>> Optimised Approach
//Custom Function For Approach 2
Node * getMiddle( Node * head){

    //for 1 Node or empty llist
    if(head == NULL || head->next == NULL )
        return head ;

    //For 2 Node 
    if( head->next->next == NULL)
        return head->next ;

    Node* slow = head ;
    Node* fast = head->next ;

    while(fast != NULL){
        fast = fast->next ;
        if(fast != NULL )
            fast = fast->next ;
        slow = slow->next ;
    }
    return slow ;
}

Node *findMiddle(Node *head) {
    // Write your code here

    //Approach 2 ==>> Optimised Approach
    return getMiddle(head) ;
}