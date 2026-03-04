// Approach 2 : online sol 
// TC : O(N) && SC : O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            // Duplicate block detected
            if (curr->next && curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                // Skip entire duplicate block
                while (curr && curr->val == duplicateVal) 
                    curr = curr->next;

                prev->next = curr;  // Remove duplicates
            }
            else {
                prev = curr;        // Move prev only if no duplicate
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};




// Approach 1 : My approach 
// TC : O(N) && SC : O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return head ;

        ListNode* dummy = new ListNode(-1) ;
        dummy->next = head ;

        ListNode* prev = dummy ;
        ListNode* curr = prev->next ;

        while( curr && curr->next ){
            if( curr->next && curr->val == curr->next->val ){
                while( curr->next && curr->val == curr->next->val ){
                    curr->next = curr->next->next ;
                }
                curr = curr->next ;
            }
            else{
                prev->next = curr ;
                prev = curr ;
                curr = curr->next ;
            }
        }

        prev->next = curr ;
        return dummy->next ;
    }
};