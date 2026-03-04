// Approach 2 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if( list1 == NULL )
            return list2 ;
        if( list2 == NULL )
            return list1 ;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans ;
        while( list1 != NULL && list2 != NULL ){
            if( list1->val < list2->val ){
                temp->next = list1 ;
                temp = list1 ;
                list1 = list1->next ;
            }
            else{
                temp->next = list2 ;
                temp = list2 ;
                list2 = list2->next ;
            }
        }

        while( list1 != NULL ){
            temp->next = list1 ;
            temp = list1 ;
            list1 = list1->next ;
        }

        while( list2 != NULL ){
            temp->next = list2 ;
            temp = list2 ;
            list2 = list2->next ;
        }
        return ans->next ;
    }
};


// Approach 1 :
class Solution {
private:
    ListNode* solve(ListNode*& list1, ListNode*& list2) {
        if( list1->next == NULL ){
            list1->next = list2 ;
            return list1 ;
        }  

        ListNode* curr1 = list1 ; 
        ListNode* next1 = list1->next ;
        ListNode* curr2 = list2 ;
        ListNode* next2 = list2->next ;

        while( next1 != NULL && curr2 != NULL ){
            if( curr2->val >= curr1->val && curr2->val <= next1->val ){
                // Add Node in between first list
                curr1->next = curr2 ;
                // next2 = curr2->next ;
                curr2->next = next1 ;
                // update pointers
                curr1 = curr2 ;
                curr2 = next2 ;
            }
            else{
                curr1 = next1 ;
                next1 = next1->next ;
                if( next1 == NULL ){
                    curr1->next = curr2 ;
                    return list1 ;
                }
            }
        }
        return list1 ;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if( list1 == NULL )
            return list2 ;
        if( list2 == NULL )
            return list1 ;
        if( list1->val <= list2->val )
            return solve(list1,list2);
        return solve(list2,list1);   
    }
};
