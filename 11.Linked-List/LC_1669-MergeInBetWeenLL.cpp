// Approach 2 : Same but only less comparision
// Time: O(n + m)
// Space: O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = list1;

        ListNode* prev = dummy;
        ListNode* curr = list1;

        int index = 0;
        // find prev (a-1) and curr (b+1)
        while(index <= b){
            if(index < a)
                prev = curr;
            curr = curr->next;
            index++;
        }

        // connect prev to list2
        prev->next = list2;

        // find tail of list2
        while(list2->next)
            list2 = list2->next;

        // connect tail to remaining list
        list2->next = curr;

        return dummy->next;
    }
};


// Approach 1 
// Time: O(n + m)
// Space: O(1)
    class Solution {
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* dummy = new ListNode(0) ;
            dummy->next = list1 ; 
            ListNode* prevA = dummy ;
            for( int i = 0 ; i<a ; i++ )
                prevA = prevA->next ;

            ListNode* afterB = prevA ;
            for( int i = 0 ; i<b-a+2 ; i++ )
                afterB = afterB->next ;

            prevA->next = list2 ;
            ListNode* tail = list2 ;
            while( tail->next != nullptr )
                tail = tail->next ;

            tail->next = afterB ;
            return dummy->next ;
        }
    };  