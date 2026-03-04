/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
 
// TC = O(n) and SC = O(1)
Node * removeDuplicates(Node *head)
{
    // Write your code here
    if (head == NULL ){
        return NULL ;
    }

    Node * curr = head ;
    Node * next_next = NULL ;
    Node * NodeToDelete = NULL ;

    while( curr != NULL ){

        if( ( curr->next != NULL ) && ( curr->data == curr->next->data ) ){

            next_next = curr->next->next ;
            NodeToDelete = curr->next ; 
            delete(NodeToDelete) ;
            curr->next = next_next ;
        }
        else{
            curr = curr->next ;
        }
    }
    return head ;
}
