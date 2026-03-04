// Approach 2 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;
        for(int i = 0; i < right-left; i++){
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy.next;
    }
};



// Approach 1 :
// TC : O(N) , SC :O(1)
class Solution {
private :
    ListNode* reverseLL(ListNode*& head ){
        ListNode* prev = NULL ;
        ListNode* curr = head ;
        ListNode* forward = NULL ;
        while( curr!= NULL ){
            forward = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev ;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( head == NULL || head->next == NULL )
            return head ;

        ListNode* dummy = new ListNode(-1) ;
        dummy->next = head ;

        ListNode* prev = dummy ;
        ListNode* curr = prev->next ;
        for( int i = 1 ; i<right ; i++ ){
            if( i<left ){
                prev = curr ;
                curr = curr->next ;
            }
            else
                curr = curr->next ;
        }

        ListNode* forwardRemainingLL = curr->next ;
        curr->next = NULL ;
        prev->next = reverseLL(prev->next);

        ListNode* temp = prev ;
        while(temp->next != NULL )
            temp = temp->next ;

        temp->next = forwardRemainingLL ;

        return dummy->next ;
    }
};