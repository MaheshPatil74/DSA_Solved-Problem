/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Approach 2 : Same as Below
// TC : O(N)  , SC : O(N)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


 
// Approach 1 : Floyd Algo (Slow-fast Pointer)
// TC : O(N)  , SC : O(N)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if( head == NULL || head->next == NULL )
            return head ;
        
        if( head->next->next == NULL )
            return head->next ;
        
        ListNode* slow = head ;
        ListNode* fast = head->next ;
        while( fast != NULL ){
            fast = fast->next ;
            if( fast != NULL )
                fast = fast->next ;
            slow = slow->next ;
        }
        return slow ;
    }
};