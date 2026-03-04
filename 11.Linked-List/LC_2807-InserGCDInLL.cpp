// TC : O( N*LogV )      
class Solution {
    int gcd(int a , int b ){
        while( b!= 0 ){
            int temp = a%b ;
            a = b ;
            b = temp ;
        }
        return a ;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if( head == NULL || head->next==NULL )
            return head ;

        ListNode* temp = head ;

        while( temp && temp->next ){
            int first = temp->val ;
            int second = temp->next->val ;
            int gcdNum = gcd(first,second) ;
            ListNode* newNode = new ListNode(gcdNum) ;
            newNode->next = temp->next ;
            temp->next = newNode ;

            temp = temp->next->next ;
        }
        return head ;
    }
};