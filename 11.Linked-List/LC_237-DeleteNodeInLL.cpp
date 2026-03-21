// Approach 2 : Optimal => Copy next node value and delete next node
// TC : O(1) , SC : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val ;
        ListNode* temp = node->next ;
        node->next = node->next->next ;
        delete temp ;
    }
};

// Approach 1 : brute force => Shift all values left and delete last node
// TC : O(N) , SC : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node ;
        while( curr->next ){
            curr->val = curr->next->val ;
            if( curr->next->next == NULL ){
                delete curr->next ;
                curr->next = NULL ;
                break ;
            }
            curr = curr->next ;
        }
    }
};