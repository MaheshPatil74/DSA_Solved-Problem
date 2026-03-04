#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // Check if empty
    bool isEmpty() {
        return (qfront == rear);
    }

    // Check if full
    bool isFull() {
        return (rear == size);
    }

    // Insert element
    bool enqueue(int value) {
        if (isFull())
            return false;

        arr[rear] = value;
        rear++;
        return true;
    }

    // Remove element
    int dequeue() {
        if (isEmpty())
            return -1;

        int ans = arr[qfront];
        qfront++;
        
        if( qfront == rear ){
            qfront = 0 ;
            rear = 0 ;
        }
        return ans ;
    }

    // Get front element
    int front() {
        if (isEmpty())
            return -1;
        return arr[qfront];
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};