#include<iostream>

using namespace std;


class Queue
{   
public:
    Queue(int n) {
        nums = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }

    int* nums;
    int size;
    int front;
    int rear; 


    bool isFull() {
        if(front == 0 && rear == size - 1) {
            cout << "isfull" << endl;
            return true;
        }else {
            return false;
        }
    }

    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        }else {
            return false;
        }
    }

    void enQueue(int num) {
        if(!isFull()) {
            if(front == -1) front = 0;
            nums[++rear] = num;
        }else {
            return;
        }
    }

    void deQueue() {
        if(!isEmpty() && front < rear) {
            front++;
        }else if(front >= rear) {
            front = -1;
            rear = -1;
        }else {
            return;
        }
    }

    void peek() {
        if(front == -1 && rear == -1) {
            cout << -1 << endl;
        }else {
            cout << nums[front] << endl;
        }  
    }


};


int main() {

    int n, op, num;
    cin >> n;


    Queue q = Queue(n); // ºc³y

    for(int i = 0;  i < n; i++) {
        
        cin >> op;
            switch (op)
            {
            case 1:
                cin >> num;
                q.enQueue(num);
                break;

            case 2:
                q.peek();
                break;
            
            case 3:
                q.deQueue();

            default:
                break;
            }
    }
}



