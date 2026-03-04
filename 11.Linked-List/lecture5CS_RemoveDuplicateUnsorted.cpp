// Approach 3 : ==>> Used Extra space ==> unordered set
// TC : O(N) , SC : O(N)
Node *removeDuplicates(Node *head)
{
    if( head == NULL )
        return head ;
    
    unordered_set<int> visited ;
    Node* curr = head ;
    Node* prev = NULL ;
    while( curr!=NULL ){
        if( visited.find(curr->data) != visited.end() ){
            // duplicate found
            prev->next = curr->next ;
            Node* nodeToDelete = curr ;
            curr = prev->next ;
            delete(nodeToDelete) ;
        }
        else{
            visited.insert(curr->data) ;
            prev = curr ;
            curr = curr->next ;
        }
    }
    return head ;
}


// Approach 2 : ==>> Sort Then Used Logic of duplicate node removal Sorted LL 
// TC : O(N*LogN) , SC : O(1)



// Approach 1 : ==>> TLE Occur
// TC : O(N*N) , SC : O(1)
Node *removeDuplicates(Node *head)
{
    Node* temp = head ;
    while( temp!=NULL ){
        Node* prev = temp ; 
        Node* curr = temp->next ;
        while( curr != NULL ){
            if( curr->data == temp->data ){
                Node* nodeToDelete = curr ;
                prev->next = curr->next ;
                curr = prev->next ;
                delete(nodeToDelete) ;
            }
            else{
                prev = curr ;
                curr = curr->next ;
            }
        }
        temp = temp->next ;
    }
    return head ;
}