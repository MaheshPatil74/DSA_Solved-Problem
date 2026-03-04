#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
//Approach 1 ==>> Iterative Approach :
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if( head == NULL || head->next == NULL )
        return head ; 
    
    LinkedListNode<int>* curr = head ;
    LinkedListNode<int>* prev = NULL ;
    LinkedListNode<int>* forward = NULL ;

    while( curr != NULL ){
        forward = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forward ;
    }
    head = prev ;
    return head ;
}



//Approach 2 ==>> Recursive
//Custom Function for approach 2 
void reverse( LinkedListNode<int> * &head , LinkedListNode<int> *curr , LinkedListNode<int> *prev ){
    //base case
    if(curr == NULL ){
        head = prev ;
        return ;
    }
    LinkedListNode<int> * forward = curr -> next ;
    reverse(head , forward , curr );
    curr->next = prev ;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //Approach 2 ==>> Recursive Approach :
    LinkedListNode<int>* curr = head ;
    LinkedListNode<int>* prev = NULL ;
    reverse(head , curr , prev) ;
    return head ;
}




//Approach 3 ==>> Original Recursive Approach
//Custom Function for approach 3
LinkedListNode<int> * reverse1(LinkedListNode<int> * head){
    //base case
    if( head == NULL || head ->next == NULL ){
        return head ;
    }

    LinkedListNode<int> * ChotaHead = reverse1( head -> next );
    head->next->next = head ;
    head->next = NULL ;

    return ChotaHead ;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //Approach 3 ==>> Original Recursive Approach :
    return reverse1(head) ;
}