#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 1. Create List
void createList() {
    int n, value, i;
    struct Node *newNode, *current;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
        return;

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            current = head;
            while (current->next != head)
                current = current->next;

            current->next = newNode;
            newNode->next = head;
        }
    }
}

// 2. Display List
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;

    printf("List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(Back to Head)\n");
}

// 3. Add at Beginning
void addAtBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* current = head;
        while (current->next != head)
            current = current->next;

        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
}

// 4. Add at End
void addAtEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* current = head;
        while (current->next != head)
            current = current->next;

        current->next = newNode;
        newNode->next = head;
    }
}

// 5. Delete at Beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    struct Node* temp = head;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    while (current->next != head)
        current = current->next;

    head = head->next;
    current->next = head;
    free(temp);
}

// 6. Delete at End
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head, *prev_current = NULL;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    while (current->next != head) {
        prev_current = current;
        current = current->next;
    }

    prev_current->next = head;
    free(current);
}

// 7. Delete After Data Value
void deleteAfterValue() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *current = head;

    do {
        if (current->data == value) {
            struct Node* temp = current->next;

            if (temp == head) {
                printf("Cannot delete head in this operation\n");
                return;
            }

            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Value not found\n");
}

// 8. Delete Entire List
void deleteEntireList() {
    if (head == NULL)
        return;

    struct Node *current = head->next, *temp;

    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
    head = NULL;
}

// Main Menu
int main() {
    int choice;

    do {
        printf("\n***** MAIN MENU *****\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Add at Beginning\n");
        printf("4. Add at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete After Data Value\n");
        printf("8. Delete Entire List\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: displayList(); break;
            case 3: addAtBeginning(); break;
            case 4: addAtEnd(); break;
            case 5: deleteAtBeginning(); break;
            case 6: deleteAtEnd(); break;
            case 7: deleteAfterValue(); break;
            case 8: deleteEntireList(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 9);

    return 0;
}
