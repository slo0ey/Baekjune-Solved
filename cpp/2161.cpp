#include <iostream>

#define MAX_CAPACITY 1000

int queue[MAX_CAPACITY];
int front, rear = -1;

void enqueue(int data) {
  rear = (rear + 1) % MAX_CAPACITY;
  queue[rear] = data;
}

int peek() { return queue[front]; }

void dequeue() {  //큐가 빈경우는 생각하지 않아도 됨
  front = (front + 1) % MAX_CAPACITY;
}

int N, head;

int main() {
  std::cin >> N;

  for (int i = 0; i < N; i++) enqueue(i + 1);

  for (int i = 0; i < N - 1; i++) {
    std::cout << peek() << " ";
    dequeue();

    head = peek();
    dequeue();
    enqueue(head);
  }

  std::cout << peek();
}