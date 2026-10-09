#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the end
void insert(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d inserted successfully.\n", value);
}

// Delete a node by value
void deleteNode(int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        head = head->next;
        free(temp);
        printf("%d deleted successfully.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully.\n", value);
}

// Display the linked list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for an element
void search(int value) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element found at position %d.\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element not found.\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}