#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int ticket) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = ticket;

    printf("Ticket request %d added successfully.\n", ticket);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No requests available.\n");
        return;
    }

    printf("Ticket request %d removed.\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Ticket reservation requests: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, ticket;

    do {
        printf("\n--- Ticket Reservation Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ticket request ID: ");
                scanf("%d", &ticket);
                enqueue(ticket);
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
