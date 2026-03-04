#include<iostream>
using namespace std ;

class Stack{
private:
        int *arr ;
        int size ;
        int top ;
public :
    Stack( int size ){
        this->size = size ;
        arr = new int[size] ;
        top = -1 ;
    }

    void push(int data ){
        if( size-top > 1 ){
            cout<<"Element Push Into Stack : "<< data <<endl ;
            top++ ;
            arr[top] = data ;
        }
        else{
            cout<<"Stack is Overflow ==>> Data Can't Inserted Into Stack !!!"<<endl ;
        }
    }

    void pop(){
        if( top >= 0 ){
            cout<<"Popped Element ==>> " << arr[top] <<endl ;
            top-- ;
        }
        else{
            cout<<"Stack is Underflow ==>> Data Can't Deleted from Stack !!!"<<endl ;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true ;
        }
        return false ;
    }

    int Size(){
        return top+1 ;
    }

    int peek(){
        if( top >= 0  ){
            return arr[top] ;
        }
        else{
            cout<<"Stack is Empty " <<endl ;
            return -1 ;
        }
    }
};

int main(){
    // Creating stack
    Stack s(5) ;

    // Checking Stack is empty or not initially
    cout<<"Stack is Empty or NOt : "<< s.isEmpty() <<endl ;
    // Pushing Element Into Stack
    s.push(1) ;
    s.push(2) ;
    s.push(3) ;
    s.push(4) ;

    // Checking size of stack
    cout<<"Size of Stack : " << s.Size() <<endl ;
    
    // Popping element from stack 
    s.pop() ;
    cout<<"Size of Stack : " << s.Size() <<endl ;
    cout<<"Stack is Empty or NOt : "<< s.isEmpty() <<endl ;

    // Printing top elemen of stack
    cout<<"Top element : "<< s.peek() <<endl ;

    s.push(4) ;
    s.push(5) ;
    s.push(6) ;

    cout<<"Top element : "<< s.peek() <<endl ;
    cout<<"Size of Stack : " << s.Size() <<endl ;
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<"Top element : "<< s.peek() <<endl ;
    cout<<"Size of Stack : " << s.Size() <<endl ;
    
    s.pop() ;

    cout<<"Top element : "<< s.peek() <<endl ;
    cout<<"Size of Stack : " << s.Size() <<endl ;
}