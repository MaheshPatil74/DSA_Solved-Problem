// Approach 2 : Using AI : Same as Me but slight simle
// TC : O(N) , SC :(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return head ;

        ListNode* dummy = new ListNode(-1) ;
        dummy->next = head ;

        ListNode* prev = dummy ;

        while( prev->next != NULL && prev->next->next != NULL ){
            ListNode* first = prev->next ;
            ListNode* second = prev->next->next ;

            // Swap
            first->next = second->next ;
            second->next = first ;
            prev->next = second ;

            prev = first
        }
        return dummy->next ;
    }
};



// Approach 1 : My own ( Iterative )
// TC : O(N) , SC :(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return head ;

        ListNode* dummy = new ListNode(-1) ;
        dummy->next = head ;
        ListNode* prev = dummy ;
        ListNode* curr = prev->next ;

        while( curr != NULL && curr->next!=NULL ){
            ListNode* forward = curr->next->next ;
            curr->next->next = prev->next ;
            prev->next = curr->next ;
            curr->next = forward ;
            prev = curr ;
            curr = prev->next ;
        }

        return dummy->next ;
    }
};