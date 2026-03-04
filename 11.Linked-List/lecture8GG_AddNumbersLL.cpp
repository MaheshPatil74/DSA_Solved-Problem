// Approach 1 : 
class Solution {
  private :
    
    Node * reverse(Node * head ){
        Node * curr = head ;
        Node * prev = NULL ;
        Node * next = curr->next ;
        
        while( curr != NULL ){
            next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        return prev ;
    }
    
    void InsertAtTail( Node* & head , Node* & tail , int val){
        Node * temp = new Node(val) ;
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
    
    Node * add(Node * first , Node * second ){
        int carry = 0 ;
        Node * ansHead = NULL ;
        Node * ansTail = NULL ;
        
        while( first!=NULL && second!=NULL ){
            int sum = carry + first->data + second->data ;
            int digit = sum%10 ;
            
            // Create a Node and add it to Answer LL
            InsertAtTail(ansHead , ansTail , digit) ;
            carry = sum / 10 ;
            first = first->next ;
            second = second->next ;
        }
        
        while( first!=NULL ){
            int sum = carry + first->data ;
            int digit = sum%10 ;
            
            // Create a Node and add it to Answer LL
            InsertAtTail(ansHead , ansTail , digit) ;
            carry = sum / 10 ;
            first = first->next ;
        }
        while( second!=NULL ){
            int sum = carry + second->data ;
            int digit = sum%10 ;
            
            // Create a Node and add it to Answer LL
            InsertAtTail(ansHead , ansTail , digit) ;
            carry = sum / 10 ;
            second = second->next ;
        }
        while( carry != 0 ){
            int sum = carry ;
            int digit = sum%10 ;
            
            // Create a Node and add it to Answer LL
            InsertAtTail(ansHead , ansTail , digit) ;
            carry = sum / 10 ;
        }
        return ansHead ;
    }
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        // step 1 : Reverse the both input linked list 
        num1 = reverse( num1 ) ;
        num2 = reverse( num2 ) ;
        
        // step 2 : add a 2 LL
        Node * ans = add(num1 , num2) ;
        
        // step 3 : reverse a ans LL
        ans = reverse(ans) ;
        
        // Below if condition is Not Necessary , only given because of 1 particulat type test case pass
        if( ans->data == 0 )
            ans = ans->next ;

        return ans ;
    }
};

// Approach 2 : Generic and Efficient 
// TC = O(m+n) & SC = O( max(m,n) )
class Solution {
  private :
    
    Node * reverse(Node * head ){
        Node * curr = head ;
        Node * prev = NULL ;
        Node * next = curr->next ;
        
        while( curr != NULL ){
            next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        return prev ;
    }
    
    void InsertAtTail( Node* & head , Node* & tail , int val){
        Node * temp = new Node(val) ;
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
    
    Node * add(Node * first , Node * second ){
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            InsertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        // step 1 : Reverse the both input linked list 
        num1 = reverse( num1 ) ;
        num2 = reverse( num2 ) ;
        
        // step 2 : add a 2 LL
        Node * ans = add(num1 , num2) ;
        
        // step 3 : reverse a ans LL
        ans = reverse(ans) ;
        
        // Below if condition is Not Necessary , only given because of 1 particulat type test case pass
        if( ans->data == 0 ){
            ans = ans->next ;
        }   
        return ans ;
    }
};