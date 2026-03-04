// Approach 2 : slight improvement  
// TC : O(N) , SC : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // Move fast n+1 steps ahead
        for(int i = 0; i <= n; i++)
            fast = fast->next;
        
        // Move both pointers
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete target node
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        
        return dummy.next;
    }
};



// Approach 1 : 
// TC : O(N) , SC : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head ;
        int count = 0 ;
        while( fast != NULL && count<n ){
            fast = fast->next ;
            count++ ;
        }
        if( fast == NULL )
            return head->next ;
            
        ListNode* curr = head ;
        ListNode* prev = NULL ;
        while( fast != NULL ){
            prev = curr ;
            curr = curr->next ;
            fast = fast->next ;
        }
        prev->next = curr->next ;
        curr->next = NULL ;
        return head ;
    }
};
