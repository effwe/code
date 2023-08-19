#include <iostream>

using namespace std;

class Queue {
public:
    int* array;
    int capacity;
    int front, rear;

    Queue(int size) {
        array = new int[size];
        capacity = size;
        front = 0;
        rear = 0;
    }
    
    void enQueue(int element) {
        int pos = (rear + 1) % capacity; //計算位置(一格位置不使用)
        if(pos == front) return; //佇列是否已滿

        rear = pos;
        array[rear] = element;
    }

    bool isEmpty() {
        return rear == front;
    }

    int deQueue() {
        front = (front + 1) % capacity;
        return array[front];
    }
};


int main() {
    Queue queue = Queue(10 + 1); // (10 + 1) 一個位置不使用
    for(int i = 0; i < 10; i++) {
        queue.enQueue(i * 11);
    }
    while(!queue.isEmpty()) {
        cout << queue.deQueue() << " ";
    }
}