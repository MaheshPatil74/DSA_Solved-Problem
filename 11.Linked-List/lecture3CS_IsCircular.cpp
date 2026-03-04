// Approach 2 : Using Floys Cycle detection algo
// TC : O(N) , SC : O(1)
bool isCircular(Node* head){
    if(head == NULL)
        return true;

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // Cycle found
            return slow == head;   // true only if cycle starts at head
        }
    }
    return false;
}


//Approach 1 :
// Correct Approach but TLE problem get in certain cases
// So Sir Suggest to Learn algo ==>> Floyd Cycle detect Algo
// So solve these question after learning algo at Code Studio

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) 
        return true;

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}