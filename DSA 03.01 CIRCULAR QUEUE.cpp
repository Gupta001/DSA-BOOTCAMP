#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted %d\n", element);
    }
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return (-1);
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return (element);
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front -> %d\n", front);
        printf("Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d\n", items[i]);
        printf("Rear -> %d\n", rear);
    }
}

int main() {
    dequeue();  // Queue is empty
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5); // Queue is full
    display();
    printf("Deleted element = %d\n", dequeue());
    display();
    enqueue(6);
    display();
    return 0;
}

