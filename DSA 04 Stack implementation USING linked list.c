#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function to add element to stack
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack\n", data);
}

// Pop function to remove element from stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", top->data);
    top = top->next;
    free(temp);
}

// Display function to show the elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

