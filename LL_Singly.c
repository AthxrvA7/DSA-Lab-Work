#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/* 1. Create List */
void createList() {
    int n, i;
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
        } else {
            current = head;
            while (current->next != NULL)
                current = current->next;

            current->next = newNode;
        }
    }
}

/* 2. Display List */
void displayList() {
    struct Node* current = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/* 3. Add at Beginning */
void addAtBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;
}

/* 4. Add at End */
void addAtEnd() {
    struct Node *newNode, *current;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

/* 5. Delete at Beginning */
void deleteAtBeginning() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

/* 6. Delete at End */
void deleteAtEnd() {
    struct Node *current, *prev_current;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    current = head;
    while (current->next != NULL) {
        prev_current = current;
        current = current->next;
    }

    prev_current->next = NULL;
    free(current);
}

/* 7. Delete After Data Value */
void deleteAfterValue() {
    int value;
    struct Node *current, *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    current = head;

    while (current != NULL && current->data != value)
        current = current->next;

    if (current == NULL || current->next == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}

/* 8. Delete Entire List */
void deleteEntireList() {
    struct Node *current, *temp;

    current = head;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    head = NULL;
}

/* Main Function */
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
