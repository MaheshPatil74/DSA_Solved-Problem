#include <bits/stdc++.h>
class CircularQueue {
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (qfront == -1);
    }

    bool isFull() {
        return ( (rear + 1) % size == qfront );
    }

    bool enqueue(int value) {
        if (isFull())
            return false;

        if (isEmpty()) 
            qfront = rear = 0;
        else
            rear = (rear + 1) % size;

        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (isEmpty())
            return -1;

        int ans = arr[qfront];
        if (qfront == rear)     // Only one element
            qfront = rear = -1;
        else
            qfront = (qfront + 1) % size;

        return ans;
    }

    int front() {
        if (isEmpty())
            return -1;
        return arr[qfront];
    }

    ~CircularQueue() {
        delete[] arr;
    }
};