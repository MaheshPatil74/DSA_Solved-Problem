//Approach 1 : Normal Approach To detect loop/Cycle in LL
// Correct but not efficient
// Time Complexity = O(n) && Space Complexity = O(n)
// Efficient algo ==>> Floyd Cycle detect Algo

bool detectLoop(Node* head) {
    if(head == NULL)
        return false;
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp !=NULL) {
        //cycle is present
        if(visited[temp] == true) {
            cout<< "Present on Element : "<< temp->data <<endl ;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

// Approach 2 : Efficient Algo
// There is Algorithm ==>> Floys cycle Detection Algo
// Helps to detect loop in optimised way 
// Time Complexity = O(n) && Space Complexity = O(1)

// i) ==>> Detecting Cycle in LL using Floyd Cycle Algo
Node * floydCyleDetectAlgo(Node * head ){
    if(head == NULL ){
        // return false ;
        return NULL ;
    }

    Node * slow = head ;
    Node * fast = head ;

    while( slow!=NULL && fast!=NULL ){
        fast = fast->next ;
        if( fast != NULL ){
            fast = fast->next ;
        }
        slow = slow->next ;

        if( slow == fast ){
            cout<<" Cycle present at Element : "<< slow -> data <<endl ;
            // return true ;
            return slow ;
        }
    }
    // return false ;
    return NULL ;
}

// ii) ==>> Detecting Cycle in LL and return Node from where Node start using Floyd Cycle Algo
// Also one another way is by Map method ==>> HW
Node * getStartingnode( Node * head ){
    if ( head == NULL )
        return NULL ;

    Node * intersection = floydCyleDetectAlgo( head ) ;

    if( intersection == NULL )
        return NULL ;

    Node * slow = head ;

    while( slow != intersection ){
        slow = slow->next ;
        intersection = intersection->next ;
    }

    return slow ;
}

// iii) ==>> Detecting Cycle and remove cycle from LL 
Node* removeCycle( Node * head ){
    if(head == NULL ){
        return NULL;
    }

    Node * startOfLoop = getStartingnode(head) ;

    if( startOfLoop == NULL ){
        return head ;
    }

    Node * temp = startOfLoop ;

    while( temp->next != startOfLoop ){
        temp = temp->next ;
    }
    temp->next = NULL ;
    return head ;
}

// iv) ==>> Original Code Studio Question ==>> Detect and Remove Loop

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node * floydCyleDetectAlgo(Node * head ){
    if(head == NULL )
        return NULL ;

    Node * slow = head ;
    Node * fast = head ;

    while( slow!=NULL && fast!=NULL ){
        fast = fast->next ;
        if( fast != NULL ){
            fast = fast->next ;
        }
        slow = slow->next ;

        if( slow == fast ){
            return slow ;
        }
    }
    return NULL ;
}

Node * getStartingnode( Node * head ){
    if ( head == NULL )
        return NULL ;

    Node * intersection = floydCyleDetectAlgo( head ) ;

    if( intersection == NULL )
        return NULL ;

    Node * slow = head ;
    while( slow != intersection ){
        slow = slow->next ;
        intersection = intersection->next ;
    }
    return slow ;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head == NULL ){
        return NULL ;
    }

    Node * startOfLoop = getStartingnode(head) ;

    if( startOfLoop == NULL ){
        return head ;
    }

    Node * temp = startOfLoop ;

    while( temp->next != startOfLoop ){
        temp = temp->next ;
    }
    temp->next = NULL ;
    return head ;
}
