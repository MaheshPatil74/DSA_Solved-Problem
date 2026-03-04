// Approach 2 : without mapping
// TC = O(n) & SC = O(1)
class Solution {
private :
    void insertAtTail(Node*& head , Node*& tail , int data ){
        Node* newNode = new Node(data);
        if( head == NULL ){
            head = newNode ;
            tail = newNode ;
        }
        else{
            tail->next = newNode ;
            tail = newNode ;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // Step -I : Creation of Clone list only next pointer
        Node* cloneHead = NULL ;
        Node* cloneTail = NULL ;

        Node* temp = head ;
        while( temp != NULL ){
            insertAtTail(cloneHead , cloneTail , temp->val );
            temp = temp->next ;
        }

        // step 2: insert nodes of Clone List in between originalList
        Node* originalNode = head ;
        Node* cloneNode = cloneHead ;
        while( originalNode != NULL && cloneNode != NULL ){
            Node* forward = originalNode->next ;
            originalNode->next = cloneNode ;
            originalNode = forward ;

            forward = cloneNode->next ;
            cloneNode->next = originalNode ;
            cloneNode = forward ;
        }
        
        // step 3: Random pointer copy
        originalNode = head ;
        while( originalNode != NULL ){
            if( originalNode->random != NULL )
                originalNode->next->random = originalNode->random->next ;
            
            originalNode = originalNode->next->next ;
        }

        //step 4: revert step 2 changes
        Node* original = head ;
        Node* copy = cloneHead ;
        while( original && copy ){
            original->next = original->next ? original->next->next : original->next ;
            copy->next = copy->next ? copy->next->next : copy->next ;
            
            original = original->next ;
            copy = copy->next ;
        }

        // step 5 answer return
        return cloneHead ;
    }
};


// Approach 1 : using map
// TC = O(n) & SC = O(n)
class Solution {
private :
    void insertAtTail(Node*& head , Node*& tail , Node* &temp ){
        Node* newNode = new Node(temp->val);
        if( head == NULL ){
            head = newNode ;
            tail = newNode ;
        }
        else{
            tail->next = newNode ;
            tail = newNode ;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // Step -I : Creation of Clone list only next pointer
        Node* cloneHead = NULL ;
        Node* cloneTail = NULL ;

        Node* temp = head ;
        while( temp != NULL ){
            insertAtTail(cloneHead , cloneTail , temp );
            temp = temp->next ;
        }

        // Step-II : Creation of Map
        unordered_map<Node* , Node*> oldToNew ;
        Node* originalNode = head ;
        Node* cloneNode = cloneHead ;
        while( originalNode != NULL && cloneNode != NULL ){
            oldToNew[originalNode] = cloneNode ;
            originalNode = originalNode->next ;
            cloneNode = cloneNode->next ;
        } 

        // step-III : attached random Pointers
        originalNode = head ;
        cloneNode = cloneHead ;
        while( originalNode != NULL ){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next ;
            cloneNode = cloneNode->next ;
        }
        return cloneHead ;
    }
};