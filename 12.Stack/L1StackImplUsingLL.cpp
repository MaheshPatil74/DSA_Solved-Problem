#include<iostream>
using namespace std ;

class Node{
public:
    int data ;
    Node* next ;

    Node( int data ){
        this->data = data ;
        this->next = NULL ;
    }
};

class Stack{
private :
    Node* head ;
    int size ;

public :
    Stack(){
        head = NULL ;
        size = 0 ;
    }

    ~Stack(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = head ;
        head = newNode ;
        size++ ;
    }

    void pop(){
        if( head == NULL ){
            cout<<"Nothing To POP : Stack is Empty "<<endl ;
            return ;
        }
        Node* temp = head ;
        head = head->next ;
        delete temp ;
        size-- ;
    }

    int Size(){
        return size ;
    }

    bool isEmpty(){
        return ( head == NULL ) ;
    }

    int peek(){
        if( head == NULL ){
            cout<<"Stack is Empty:: returning -1"<<endl;
            return -1 ;
        }
        return head->data ;
    }
};

int main(){

    Stack s;

    cout<<"Is Stack Empty? "<<s.isEmpty()<<endl;

    cout<<"\nPushing elements...\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Current Stack Size: "<<s.size()<<endl;

    cout<<"Top element (peek): "<<s.peek()<<endl;

    cout<<"\nPopping element...\n";
    s.pop();

    cout<<"Top element after pop: "<<s.peek()<<endl;

    cout<<"Current Stack Size: "<<s.size()<<endl;

    cout<<"\nPopping all elements...\n";
    while(!s.isEmpty()){
        cout<<"Removing: "<<s.peek()<<endl;
        s.pop();
    }

    cout<<"\nIs Stack Empty now? "<<s.isEmpty()<<endl;

    cout<<"Trying pop on empty stack:\n";
    s.pop();

    cout<<"Trying peek on empty stack:\n";
    cout<<s.peek()<<endl;

    return 0;
}