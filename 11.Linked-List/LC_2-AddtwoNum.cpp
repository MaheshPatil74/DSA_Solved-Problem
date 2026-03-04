// Approach 2 : only reduce loops
// TC : O(N+M) , SC : O(N+M)
class Solution {
private :
    ListNode* reverseLL(ListNode*& temp ){
        ListNode* curr = temp ;
        ListNode* prev = NULL ;
        ListNode* forward = NULL ;
        while( curr != NULL ){
            forward = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev ;
    }

    void insertAtTail( ListNode* &head , ListNode*& tail, int digit ){
        ListNode* temp = new ListNode(digit);
        if( head == NULL ){
            head = temp ;
            tail = temp ;
            return ;
        }
        else{
            tail->next = temp ;
            tail = temp ;
        }
    }
    ListNode* addLL(ListNode* first , ListNode* second ){
        int carry = 0 ;
        ListNode* ansHead = NULL ;
        ListNode* ansTail = NULL ;
        while( first!=NULL && second!=NULL ){
            int sum = carry + first->val + second->val ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
            first = first->next ;
            second = second->next ;
        }
        while( first!=NULL ){
            int sum = carry + first->val ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
            first = first->next ;
        }
        while( second!=NULL ){
            int sum = carry + second->val ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
            second = second->next ;
        }
        while( carry != 0 ){
            int sum = carry ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
        }
        return ansHead ;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // //This is when digit store in correct order
        // l1 = reverseLL(l1) ;
        // l2 = reverseLL(l2) ;
        // ListNode* ans = addLL(l1,l2) ;
        // ans = reverseLL(ans) ;
        // return ans ;

        // As digit store in reversed order
        return addLL(l1,l2);
    }
};


// Approach 1 :
// TC : O(N+M) , SC : O(N+M)
class Solution {
private :
    ListNode* reverseLL(ListNode*& temp ){
        ListNode* curr = temp ;
        ListNode* prev = NULL ;
        ListNode* forward = NULL ;
        while( curr != NULL ){
            forward = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev ;
    }

    void insertAtTail( ListNode* &head , ListNode*& tail, int digit ){
        ListNode* temp = new ListNode(digit);
        if( head == NULL ){
            head = temp ;
            tail = temp ;
            return ;
        }
        else{
            tail->next = temp ;
            tail = temp ;
        }
    }
    ListNode* addLL(ListNode* first , ListNode* second ){
        int carry = 0 ;
        ListNode* ansHead = NULL ;
        ListNode* ansTail = NULL ;
        while( first!=NULL && second!=NULL ){
            int sum = carry + first->val + second->val ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
            first = first->next ;
            second = second->next ;
        }
        while( first!=NULL ){
            int sum = carry + first->val ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
            first = first->next ;
        }
        while( second!=NULL ){
            int sum = carry + second->val ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
            second = second->next ;
        }
        while( carry != 0 ){
            int sum = carry ;
            int digit = sum%10 ;
            carry = sum/10 ;
            insertAtTail( ansHead , ansTail , digit );
        }
        return ansHead ;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // //This is when digit store in correct order
        // l1 = reverseLL(l1) ;
        // l2 = reverseLL(l2) ;
        // ListNode* ans = addLL(l1,l2) ;
        // ans = reverseLL(ans) ;
        // return ans ;

        // As digit store in reversed order
        return addLL(l1,l2);
    }
};