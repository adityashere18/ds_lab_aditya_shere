#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the end
void insert(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted successfully.\n", value);
}

// Display the circular linked list
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Delete a node by value
void deleteNode(int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Find the node to delete
    while (temp->data != value) {
        prev = temp;
        temp = temp->next;

        if (temp == head) {
            printf("Element not found.\n");
            return;
        }
    }

    // Only one node exists
    if (temp->next == head && temp == head) {
        head = NULL;
    }
    // Delete the first node
    else if (temp == head) {
        struct Node *last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
    }
    // Delete any other node
    else {
        prev->next = temp->next;
    }

    free(temp);
    printf("%d deleted successfully.\n", value);
}

// Search for an element
void search(int value) {
    struct Node *temp;
    int position = 1;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    do {
        if (temp->data == value) {
            printf("Element found at position %d.\n",
                   position);
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    printf("Element not found.\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1)
                    return 1;
                insert(value);
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1)
                    return 1;
                deleteNode(value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1)
                    return 1;
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