// Approach 2 : By do not reverse input list
// TC : O( N+M ) , SC : O( N+M )
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 , s2 ;

        while( l1 ){
            s1.push(l1->val) ;
            l1 = l1->next ;
        }

        while( l2 ){
            s2.push(l2->val) ;
            l2 = l2->next ;
        }

        int carry = 0 ;
        ListNode* head = NULL ;

        while( !s1.empty() || !s2.empty() || carry!=0 ){
            int sum = carry ;
            if( !s1.empty() ){
                sum += s1.top() ;
                s1.pop() ;
            }
            if( !s2.empty() ){
                sum += s2.top() ;
                s2.pop() ;
            }

            int digit = sum % 10 ;
            carry = sum / 10 ;

            ListNode* node = new ListNode(digit) ;
            node->next = head ;
            head = node ;
        }
        return head ;
    }
};


// Approach 1 : By reversing Input listb but question says do not reverse input list
// TC : O( N+M ) , SC : O( N+M )
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
        }
        else{
            tail->next = temp ;
            tail = temp ;
        }
    }
    
    ListNode* addLL(ListNode* first , ListNode* second ){
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        while( first || second || carry != 0) {
            int val1 = 0;
            if( first ){
                val1 = first -> val;
                first = first -> next;
            }
            int val2 = 0;
            if( second ){
                val2 = second -> val;
                second = second -> next;
            }
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            carry = sum/10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
        }
        return ansHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* first = reverseLL(l1) ;
        ListNode* second = reverseLL(l2) ;

        ListNode* ans = addLL(first,second);
        return reverseLL( ans ) ;
    }
};