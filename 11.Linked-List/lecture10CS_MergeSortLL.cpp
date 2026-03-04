// Approach 2 : slight change in merge 2 LL Logic
// TC = O(nlogn) and SC = O(logn)
node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}

node* mergeSort(node *head) {
    //base case
    if( head == NULL || head -> next == NULL ) 
        return head;
    
    // break linked list into 2 halvs, after finding mid
    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}





// ****************************************************************
// Approach 1 :
node * getMid( node* head ){
    if( head==NULL )
        return NULL ;

    node * slow = head ;
    node * fast = head->next ;
    while( fast!=NULL && fast->next!=NULL ){
        fast = fast->next->next ;
        slow = slow->next ; 
    }
    return slow ;
}

node * solve(  node* first , node* second ){
    // If Only one element is present in first list
    if( first->next == NULL ){
        first->next = second ;
        return first ;
    }

    node * curr1 = first ;
    node * next1 = curr1->next ;
    node * curr2 = second ;
    node * next2 = curr2->next ;

    while( next1 != NULL && curr2 != NULL ){
        if( curr2->data >= curr1->data && curr2->data <= next1->data ){
            // Add Node in between first list
            curr1->next = curr2 ;
            next2 = curr2->next ;
            curr2->next = next1 ;
            
            // update pointers
            curr1 = curr2 ;
            curr2 = next2 ;
        }
        else{
            // curr1 and next1 ko aage bdha do
            curr1 = next1 ;
            next1 = next1->next ;
            if( next1 == NULL ){
                curr1->next = curr2 ;
                return first ;
            }
        }
    }
    return first ;
}

node * merge( node * left , node * right ){
    if( left == NULL )
        return right ;

    if( right == NULL )
        return left ;

    if( left->data <= right->data )
        return solve(left , right);
    else
        return solve(right,left) ;
}

node* mergeSort(node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL )
        return head ;

    // Breaking LL into two halves , after finding mid
    node * mid = getMid(head) ;

    node * left = head ;
    node * right = mid->next ;
    mid->next = NULL ;

    // Recursive call to both Halves
    left = mergeSort(left) ;
    right = mergeSort(right) ;

    // Merge Both left and right halves
    node * result = merge( left , right ) ; 
    return result ;
}