// TC : O(N) , SC : O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return NULL ;

        ListNode* dummy = new ListNode(-1) ;
        ListNode* slow = dummy ;
        ListNode* fast = head ;
        while( fast && fast->next ){
            fast = fast->next->next ;
            slow = slow->next ;
        }
        ListNode* temp = slow->next ;
        slow->next = slow->next->next ;
        delete temp ;
        
        head = dummy->next ;
        delete dummy ;
        return head ;
    }
};