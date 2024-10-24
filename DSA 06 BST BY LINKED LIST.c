#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search for a node in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find the minimum value node in the BST
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// Find the maximum value node in the BST
struct Node* findMax(struct Node* root) {
    while (root != NULL && root->right != NULL)
        root = root->right;
    return root;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function with switch case
int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Inorder\n");
        printf("5. Display Preorder\n");
        printf("6. Display Postorder\n");
        printf("7. Find Minimum\n");
        printf("8. Find Maximum\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL)
                    printf("Data found in the tree.\n");
                else
                    printf("Data not found in the tree.\n");
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                if (root != NULL)
                    printf("Minimum value: %d\n", findMin(root)->data);
                else
                    printf("Tree is empty.\n");
                break;
            case 8:
                if (root != NULL)
                    printf("Maximum value: %d\n", findMax(root)->data);
                else
                    printf("Tree is empty.\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}

