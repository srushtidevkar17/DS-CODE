#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int request) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = request;
    printf("Call request %d added successfully.\n", request);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No calls waiting.\n");
        return;
    }

    printf("Call request %d handled.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("No call requests in the queue.\n");
        return;
    }

    printf("Call center requests: ");
    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, request;

    do {
        printf("\n--- Call Center Request Queue ---\n");
        printf("1. Enqueue (Add Call)\n");
        printf("2. Dequeue (Handle Call)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter call request ID: ");
                scanf("%d", &request);
                enqueue(request);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
