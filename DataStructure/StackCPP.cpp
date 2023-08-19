#include <iostream>

using namespace std;

class Stack {
public:
    int * array;
    int capacity;
    int top;

    Stack(int size) {
        array = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int element) {
        if(top >= capacity) return;
        array[++top] = element;
    }

    bool isEmpty() {
        return top == -1;
    }

    int pop() {
        return array[top--];
    }
};


int main() {
    Stack stack = Stack(10);
    for(int i = 0; i < 10; i++) {
        stack.push(i * 11);
    }
    while(!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
}





