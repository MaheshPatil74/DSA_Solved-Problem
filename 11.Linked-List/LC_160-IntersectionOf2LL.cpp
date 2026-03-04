// Approach 3 : Two Pointers - II
// TC : O( N+M )
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while (l1 != l2) {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        return l1;
    }
};


// Approach 2 : Two Pointers - I 
// TC : O( N+M ) 
class Solution {
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int m = getLength(headA), n = getLength(headB);
        ListNode* l1 = headA, *l2 = headB;
        if (m < n) {
            swap(m, n);
            swap(l1, l2);
        }
        while ( m > n ) {
            l1 = l1->next;
            m-- ;
        }
        while (l1 && l1 != l2) {
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
};


// Approach 1 : Brute force 
// TC : O( N*M ) 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while( headA ){
            ListNode* curr = headB ;
            while( curr ){
                if( headA == curr )
                    return headA ;
                curr = curr->next ;
            }
            headA = headA->next ;
        }
        return nullptr ;
    }
};