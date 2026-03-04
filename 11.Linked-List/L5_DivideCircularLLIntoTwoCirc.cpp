// Lecture 5 HW
// Given a circular LL break it into two circular LL

vector<Node*> divideCircularLL(Node* head){
    if(head == NULL)
        return {};

    if(head->next == head)
        return {head, NULL};

    Node* slow = head;
    Node* fast = head;

    // Find Middle
    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    // if even Number of Nodes
    if(fast->next->next == head)
        fast = fast->next;

    Node* head2 = slow->next;
    // Make first Half Circular
    slow->next = head;
    // Make first Half Circular
    fast->next = head2;

    return {head, head2};
}
