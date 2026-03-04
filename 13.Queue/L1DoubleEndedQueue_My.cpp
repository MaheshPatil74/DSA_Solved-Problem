#include <bits/stdc++.h>
using namespace std;

class Deque {
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    // Check if empty
    bool isEmpty() {
        return (qfront == -1);
    }

    // Check if full
    bool isFull() {
        return ((rear + 1) % size == qfront);
    }

    // Insert at front
    bool pushFront(int x) {
        if (isFull())
            return false;

        if (isEmpty()) {
            qfront = rear = 0;
        } else {
            qfront = (qfront - 1 + size) % size;
        }

        arr[qfront] = x;
        return true;
    }

    // Insert at rear
    bool pushRear(int x) {
        if (isFull())
            return false;

        if (isEmpty()) {
            qfront = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
        return true;
    }

    // Remove from front
    int popFront() {
        if (isEmpty())
            return -1;

        int ans = arr[qfront];

        if (qfront == rear) {
            qfront = rear = -1;   // Only one element
        } else {
            qfront = (qfront + 1) % size;
        }

        return ans;
    }

    // Remove from rear
    int popRear() {
        if (isEmpty())
            return -1;

        int ans = arr[rear];

        if (qfront == rear) {
            qfront = rear = -1;   // Only one element
        } else {
            rear = (rear - 1 + size) % size;
        }

        return ans;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return arr[qfront];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    // Destructor
    ~Deque() {
        delete[] arr;
    }
};