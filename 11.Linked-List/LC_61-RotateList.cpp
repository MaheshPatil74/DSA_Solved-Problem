// Approach 2 : Make LL Circlar then break cycle ( efficient )
// TC : O(N) , SC : O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0 )
            return head;

        // Step 1 : find length and last Node
        ListNode* temp = head ;
        int len = 1 ;
        while( temp->next != NULL ){
            temp = temp->next ;
            len++ ;
        }

        // Step 2 : make circular
        temp->next = head ;

        // Step 3 : reduce k
        k = k%len ;

        // step 4 : 
        int steps = len - k - 1;
        temp = head ;
        for( int i = 0 ; i<steps ; i++ )
            temp = temp->next ;

        // Step 5 : break circle
        head = temp->next ;
        temp->next = NULL ;
        return head ;
    }
};

// Approach 1 : three reversal method
// TC : O(N) , SC : O(1)
class Solution {
private :
    ListNode* reverseLL(ListNode*& head){
        ListNode* prev = NULL ;
        ListNode* curr = head ;
        ListNode* forward = NULL ;
        while( curr != NULL ){
            forward = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev ;
    }
    int getLength(ListNode* head){
        ListNode* temp = head ;
        int len = 0 ;
        while( temp != NULL ){
            len++ ;
            temp = temp->next ;
        }
        return len ;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int len = getLength(head) ;
        k = k%len ;

        if( k == 0 )
            return head ;

        head = reverseLL(head) ;

        ListNode* temp = head ;
        int count = 0 ;
        while( temp != NULL && count<k-1 ){
            temp = temp->next ;
            count++ ;
        }

        ListNode* list1 = head ;
        ListNode* list2 = temp->next ;
        temp->next = NULL ;

        list1 = reverseLL(list1) ;
        list2 = reverseLL(list2) ;

        temp = list1 ;
        while( temp->next != NULL )
            temp = temp->next ;

        temp->next = list2 ;
        return list1 ;
    }
};