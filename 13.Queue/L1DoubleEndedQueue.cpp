#include <bits/stdc++.h> 
#include<queue>

class Deque{
    int *arr ;
    int qfront ;
    int rear ;
    int size ;
public:
    Deque(int n){
        size = n ;
        qfront = rear = -1 ;
        arr = new int[size] ;
    }

    bool pushFront(int x){
        if( isFull() )
            return false ;
        else if( isEmpty() )
            qfront = rear = 0 ; 
        else if( qfront==0 && rear!=size-1 )
            qfront = size-1 ;
        else
            qfront-- ;
        arr[qfront] = x ;
        return true ;
    }

    bool pushRear(int x){
        if( isFull() )
            return false ;
        else if( isEmpty() )
            qfront = rear = 0 ; 
        else if( rear==size-1 && qfront!=0 )
            rear = 0 ;
        else
            rear++ ;
        arr[rear] = x ;
        return true ;
    }

    int popFront(){
        if( isEmpty() )
            return -1 ;
        int ans = arr[qfront] ;
        arr[qfront] = -1 ;

        if( qfront==rear )
            qfront=rear=-1 ;
        else if( qfront==size-1 )
            qfront = 0 ;
        else
            qfront++ ;
        
        return ans ;
    }

    int popRear(){
        if( isEmpty() )
            return -1 ;
        int ans = arr[rear] ;
        arr[rear] = -1 ;

        if( qfront==rear )
            qfront=rear=-1 ;
        else if( rear==0 )
            rear=size-1 ;
        else
            rear-- ;
        return ans ;
    }

    int getFront(){
        return ( isEmpty() ? -1 : arr[qfront] ) ;
    }

    int getRear(){
        return ( isEmpty() ? -1 : arr[rear] ) ;
    }

    bool isEmpty(){
        return ( qfront == -1 ) ;
    }

    bool isFull(){
        // return  ( ( qfront==0 && rear==size-1 ) || 
        //           ( qfront!=0 && rear==(qfront-1)%(size-1) )
        //         ) ;
        return ((rear + 1) % size == qfront);
    }
};