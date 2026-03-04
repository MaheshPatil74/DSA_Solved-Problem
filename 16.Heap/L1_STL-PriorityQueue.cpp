#include<iostream>
#include<queue>
using namespace std ;

int main(){
    // // MaxHeap
    // priority_queue<int> pq ;

    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);

    // cout<<"element at top : "<< pq.top() <<endl ;
    // pq.pop() ;
    // cout<<"element at top : "<< pq.top() <<endl ;
    // cout<<"Size : "<< pq.size() <<endl ;

    // if( pq.empty() ){
    //     cout<<"PriorityQueue is Empty!!"<<endl ;
    // }
    // else{
    //     cout<<"PriorityQueue is Not Empty!!"<<endl ;
    // }


    // MinHeap
    priority_queue<int , vector<int> , greater<int> > minheap ;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"element at top : "<< minheap.top() <<endl ;
    minheap.pop() ;
    cout<<"element at top : "<< minheap.top() <<endl ;
    cout<<"Size : "<< minheap.size() <<endl ;

    if( minheap.empty() ){
        cout<<"minheap is Empty!!"<<endl ;
    }
    else{
        cout<<"minheap is Not Empty!!"<<endl ;
    }
}