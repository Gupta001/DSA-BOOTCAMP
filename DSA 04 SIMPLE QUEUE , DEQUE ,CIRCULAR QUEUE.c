#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Queue Functions
int queue[SIZE], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == SIZE - 1)
        printf("Queue is Full
");
    else {
        if (front == -1)
            front = 0;
queue[++rear] = data;
}
}
void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty
");
    else
        printf("Dequeued: %d
", queue[front++]);
}
void displayQueue() {
    if (front == -1 || front > rear)
printf("Queue is Empty
");
 else {
     printf("Queue: ");
    int i;
for (i = 0; i < SIZE; i++) {   // compatible with older C standards
    printf("%d ", queue[i]);
}
printf("
");
}
///
Circular Queue Operations
int circularQueue[SIZE], frontCQ = -1, rearCQ = -1;
void enqueueCircular(int data) {
     if ((frontCQ == 0 && rearCQ == SIZE - 1) || (rearCQ + 1 == frontCQ))
          printf("Circular Queue is Full
");
     else {
          if (frontCQ == -1
frontCQ = 0;
    rearCQ = (rearCQ + 1) % SIZE;
    circularQueue[rearCQ] = data;
}
}
void dequeueCircular() {
    if (frontCQ == -1)
        printf("Circular Queue is Empty
");
    else
printf("Dequeued: %d
", circularQueue[frontCQ]);
    if (frontCQ == rearCQ)
        frontCQ = rearCQ = -1;
    else
        frontCQ = (frontCQ + 1) % SIZE;
void displayCircularQueue() {\
    if (frontCQ == -1)\
        printf("Circular Queue is Empty\
");\
    else {\
        printf("Circular Queue: ");\
        int i = frontCQ;\
        while (i != rearCQ)
printf("%d ", circularQueue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d
", circularQueue[rearCQ]);
    }
}

// Double Ended Queue Functions
int deque[SIZE], frontDQ = -1, rearDQ = -1;
void insertFront(int data) {
if ((frontDQ == 0 && rearDQ == SIZE -1 ) || (rearDQ + 1 == frontDQ))
            printf("Deque is Full
");
        else {
            if (frontDQ == -1)
                frontDQ = rearDQ = 0;
else if (frontDQ == 0)
            frontDQ = SIZE - 1;
        else
            frontDQ--;
        deque[frontDQ] = data;
    }
}
void insertRear(int data)
if ((frontDQ == 0 && rearDQ == SIZE - 1) || (rearDQ + 1 == frontDQ))
        printf("Deque is Full
");
    else {
        if (frontDQ == -1)
            frontDQ = rearDQ = 0;
else
    rearDQ = (rearDQ + 1) % SIZE;
    deque[rearDQ] = data;
}
}
void deleteFront() {
    if (frontDQ == -1)
        printf("Deque is Empty
");
    else
printf("Deleted Front: %d
if (frontDQ == rearDQ)
        frontDQ = rearDQ = -1;
    else
        frontDQ = (frontDQ + 1) % SIZE;
void deleteRear() {
    if (rearDQ == -1)
        printf("Deque is Empty
");
    else {
        printf("Deleted Rear: %d
", deque[rearDQ]);
        if (frontDQ == rearDQ)
            frontDQ = rearDQ = -1;
else if (rearDQ == 0)
            rearDQ = SIZE - 1;
        else
            rearDQ--;
    }
}
void displayDeque() {
    if (frontDQ == -1)
printf("Deque is Empty
");
    else {
        printf("Deque: ");
        int i = frontDQ;
        while (i != rearDQ) {
            printf("%d ", deque[i]);
i = (i + 1) % SIZE;
    }
    printf("%d
", deque[rearDQ]);
}
floppy disk
int main() {
    int choice, data, type;
    while (1)
printf("Select Queue Type: 1. Queue 2. Circular Queue 3. Deque 4. Exit
");
        scanf("%d", &type);

        if (type == 4)
            break;

        switch (type)
case 1: // Queue Operations
                printf("1. Enqueue 2. Dequeue 3. Display
");
                scanf("%d", &choice);
switch (choice) {
                    case 1:
                        printf("Enter data: ");
scanf("%d", &data);
                        enqueue(data);
break;
                    case 2:
dequeue();
                        break;
Case 3:
                displayQueue();
break;
            }
            break;
case 2: // Circular Queue Operations
                printf("1. Enqueue 2. Dequeue 3. Display
");
                scanf("%d", &choice);
switch (choice) {
                case 1:
                    printf("Enter data: ");
}
scanf("%d", &data);
                        enqueueCircular(data);
break;
                case 2:
dequeueCircular();
                    break;
case 3:
                displayCircularQueue();
break;
                }
                break;
case 3: // Deque Operations
                printf("1. Insert Front 2. Insert Rear 3. Delete Front 4. Delete Rear 5. Display
");
                scanf("%d", &choice);
switch (choice) {
            case 1:
                printf("Enter data: ");
        }]
scanf("%d", &data);
                    insertFront(data);
break;
                    case 2:
printf("Enter data: ");
                    scanf("%d", &data);
insertRear(data);
                        break;
case 3:
                        deleteFront();
Break;
                    case 4:
deleteRear();
             end
case 5:
                displayDeque();
break;
                }
break;

            default:
printf("Invalid Choice!
");
      }
  }
  return 0;
}

