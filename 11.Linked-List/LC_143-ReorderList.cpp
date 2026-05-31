// TC : O(N) , SC : O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return ;

        // Finding Middle Node
        ListNode* slow = head ;
        ListNode* fast = head ;
        while( fast->next && fast->next->next ){
            slow = slow->next ;
            fast = fast->next->next ;
        }

        // reversing the second half
        ListNode* half = slow->next ;
        slow->next = NULL ;

        ListNode* prev = NULL ;
        
        while( half ){
            ListNode* temp = half->next ;
            half->next = prev ;
            prev = half ;
            half = temp ;
        }

        ListNode* first = head ;
        ListNode* second = prev ;

        while( first && second ){
            ListNode* firstNext = first->next ;
            ListNode* secondNext = second->next ;
            first->next = second ;
            second->next = firstNext ;
            second = secondNext ;
            first = firstNext ;
        }
    }
};