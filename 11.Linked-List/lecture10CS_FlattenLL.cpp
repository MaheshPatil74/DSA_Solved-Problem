// Approach 1 :
// TC : O( N*M )
Node* merge(Node* left, Node* right){

    if(left==NULL) return right;
    if(right==NULL) return left;

    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left && right){
        if(left->data < right->data){
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else{
            temp->child = right;
            temp = right;
            right = right->child;
        }
        temp->next = NULL;   // very important
    }

	while(left){
		temp->child = left;
        temp = left;
        left = left->child;

        temp->next = NULL;   // very important
    }
	while(right){
		temp->child = right;
        temp = right;
        right = right->child;
		
        temp->next = NULL;   // very important
    }
    return ans->child;
}


Node* flattenLinkedList(Node* head) {
    if( head==NULL || head->next == NULL )
        return head;

    // Flatten right side
    head->next = flattenLinkedList(head->next);

    // Merge current vertical list with right list
    head = merge(head, head->next);
    return head;
}
