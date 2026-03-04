/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    // Write your code here.

    if( head == NULL )
        return NULL ; 

    // Step 1: Check if there are at least k nodes ahead
    Node* temp = head;
    int len = 0;
    while (temp != NULL && len < k) {
        temp = temp->next;
        len++;
    }

    // If there are less than k nodes, return head as is (no reversal)
    if (len < k) return head;

    // Step 2 : Reverse a First k Node
    Node * forward = NULL ;
    Node * curr = head ;
    Node * prev = NULL ;
    int count = 0 ;
    while( curr != NULL && count < k ){
        forward = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forward ;
        count++ ;
    }

    // step 3 : Recursion dekhlega aage ka
    if( forward != NULL ){
        head->next = kReverse( forward , k ) ;
    }

    //step 4 : return head of Reverse
    return prev ;
}