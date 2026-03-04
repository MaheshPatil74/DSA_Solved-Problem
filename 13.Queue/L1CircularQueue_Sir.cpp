#include <bits/stdc++.h> 
class CircularQueue{
    int size ;
    int qfront ;
    int rear ;
    int * arr ;

    public:
    CircularQueue(int n){
        size = n ;
        arr = new int[size] ;
        qfront = rear = -1 ;
    }

    bool enqueue(int value){
        if( ( qfront==0 && rear==size-1 ) || ( rear==(qfront-1)%(size-1) ) )
            return false ;
        else if( qfront == -1 )
            qfront = rear = 0 ;     //first element to push
        else if( rear==size-1 && qfront!=0 )
            rear = 0 ;              //to maintain cyclic nature
        else
            rear++ ;                // Normal flow

        arr[rear] = value ;
        return true ;
    }

    int dequeue(){
        if( qfront == -1)
            return -1 ;

        int ans = arr[qfront] ;
        arr[qfront] = -1 ;

        if( qfront==rear )          //single element is present
            qfront = rear = -1 ;
        else if( qfront==size-1 )   //to maintain cyclic nature
            qfront = 0 ;
        else                        //normal flow
            qfront++ ;
        return ans ;
    }
};