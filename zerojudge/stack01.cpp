// Stack implementation in C++

#include <iostream>

using namespace std;

int size = 0;

struct stack {
  int *items;
  int top;
  int capacity; 
};

typedef struct stack st;

int isfull(st *s) {
  if (s->top == s->capacity - 1)
    return 1;
  else
    return 0;
}


int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}


void push(st *s, int newitem) {
  if (isfull(s)) {
    return;
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  size++;
}


void pop(st *s) {
  if (isempty(s)) {
    return;
  } else {
    s->top--;
  }
  size--;
}

void peek(st *s) {
    if(isempty(s)) {
        cout << -1;
    } else {
        cout << s->items[s->top];
    }
    cout << endl;
}

// Driver code
int main() {
  int N, k, x;
  cin >> N;

  st *s = new st;
  s->top = -1;
  s->capacity = N;
  s->items = new int[N];
  
  for (int i = 0; i < N; i++)
  {
    cin >> k;
    switch (k)
    {
    case 1:
      cin >> x;
      push(s, x);
      break;
    
    case 2:
      peek(s);
      break;

    case 3:
      pop(s);
      break;

    default:
      break;
    }
  }
  
}