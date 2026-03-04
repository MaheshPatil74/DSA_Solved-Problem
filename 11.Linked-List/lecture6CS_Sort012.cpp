// Approach 1 : 
// Counting number of 0,1,2 and then put in Original list
// TC = O(n) && SC = O(1)
Node* sortList(Node *head){
    if( head == NULL )
        return head ;

    Node* temp = head ;
    int zeroCount = 0 ;
    int oneCount = 0 ;
    int twoCount = 0 ;
    while( temp!=NULL ){
        if( temp->data == 0 )
            zeroCount++ ;
        else if( temp->data == 1 )
            oneCount++ ;
        else if( temp->data == 2 )
            twoCount++ ;
        temp = temp->next ;
    }
    temp = head ;
    while( zeroCount ){
        temp->data = 0 ;
        temp = temp->next ;
        zeroCount-- ;
    }
    while( oneCount ){
        temp->data = 1 ;
        temp = temp->next ;
        oneCount-- ;
    }
    while( twoCount ){
        temp->data = 2 ;
        temp = temp->next ;
        twoCount-- ;
    }
    return head ;    
}


// Approach 2 :  when data Replacement Not Allowed
// Creating 0,1,2 sublist separately and merge list
// TC = O(n) && SC = O(1)
void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}
Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        int value = curr -> data;
        if(value == 0) 
            insertAtTail(zeroTail, curr);
        else if(value == 1) 
            insertAtTail(oneTail, curr);
        else if(value == 2) 
            insertAtTail(twoTail, curr);
        curr = curr -> next;
    }
    
    //merge 3 sublist
    // 1s list not empty
    if(oneHead -> next != NULL) 
        zeroTail -> next = oneHead -> next;
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}