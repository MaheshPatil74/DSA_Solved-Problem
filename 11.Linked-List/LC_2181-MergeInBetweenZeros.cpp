// Time: O(n)
// Space: O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* write = head ;
        ListNode* curr = head->next ;
        int sum = 0 ;
        while( curr ){
            if( curr->val == 0 ){
                write->val = sum ;
                write->next = curr->next ;
                write = write->next ; 
                sum = 0 ;
            }
            else
                sum += curr->val ;
            curr = curr->next ;
        }
        return head ;
    }
};
