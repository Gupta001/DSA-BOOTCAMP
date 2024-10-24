#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int key) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) { // Initial condition
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front = front - 1;
    }

    deque[front] = key;
    printf("Inserted %d at front\n", key);
}

void insertRear(int key) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) { // Initial condition
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }

    deque[rear] = key;
    printf("Inserted %d at rear\n", key);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted %d from front\n", deque[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted %d from rear\n", deque[rear]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear = rear - 1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in deque are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    insertRear(5);
    insertRear(10);
    insertFront(15);
    insertFront(20);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}

