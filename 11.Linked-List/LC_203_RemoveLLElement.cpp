// Approach 2 : With single pointer
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1,head) ;
        ListNode* curr = &dummy ;

        while( curr->next ){
            if( curr->next->val == val )
                curr->next = curr->next->next ;
            else
                curr = curr->next ; 
        }
        return dummy.next ;
    }
};


// Approach 1 : With two pointer
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if( head == NULL )
            return head ;

        while( head != NULL && head->val == val )
            head = head->next ;

        ListNode* curr = head ;
        ListNode* prev = NULL ;
        while( curr != NULL ){
            if( curr->val == val ){
                prev->next = curr->next ;
                curr = prev->next ;
            }
            else{
                prev = curr ;
                curr = curr->next ;
            }
        }
        return head ;
    }
};