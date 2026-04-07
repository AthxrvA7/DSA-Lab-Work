#include <stdio.h>
#define MAX 5

int data[MAX], priority[MAX];
int size = -1;

void enqueue(int value, int p) {
    if (size == MAX - 1) {
        printf("Queue Full\n");
        return;
    }
    size++;
    data[size] = value;
    priority[size] = p;
}

int getHighestPriorityIndex() {
    int i, max = 0;
    for (i = 1; i <= size; i++) {
        if (priority[i] > priority[max]) {
            max = i;
        }
    }
    return max;
}

void dequeue() {
    if (size == -1) {
        printf("Queue Empty\n");
        return;
    }
    int index = getHighestPriorityIndex();
    printf("Deleted: %d\n", data[index]);

    for (int i = index; i < size; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }
    size--;
}

void display() {
    if (size == -1) {
        printf("Queue Empty\n");
        return;
    }
    for (int i = 0; i <= size; i++) {
        printf("%d(%d) ", data[i], priority[i]);
    }
    printf("\n");
}

int main() {
    int choice, value, p;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &value, &p);
                enqueue(value, p);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
