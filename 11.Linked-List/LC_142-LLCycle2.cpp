// TC : O(N) , SC : O(1)
class Solution {
private :
    ListNode* getIntersection(ListNode* head ){
        if( head == NULL )
            return NULL ;

        ListNode* slow = head ;
        ListNode* fast = head ;
        while( fast != NULL && fast->next != NULL ){
            fast = fast->next->next ;
            slow = slow->next ;

            if( slow == fast )
                return slow ;
        }
        return NULL ;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if( head == NULL )
            return head ;

        ListNode* intersection = getIntersection(head) ;
        if( intersection == NULL )
            return NULL ;

        ListNode* slow = head ;
        while( slow != intersection ){
            slow = slow->next ;
            intersection = intersection->next ;
        }
        return slow ;
    }
};