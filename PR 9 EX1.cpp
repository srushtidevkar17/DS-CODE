#include <stdio.h>

int main() {
    int marks[100], n, i, j, temp, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of students!\n");
        return 1;
    }

    printf("Enter student marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    printf("\n1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice!\n");
        return 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if ((choice == 1 && marks[j] > marks[j + 1]) ||
                (choice == 2 && marks[j] < marks[j + 1])) {

                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    if (choice == 1)
        printf("\nMarks in Ascending Order:\n");
    else
        printf("\nMarks in Descending Order:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    printf("\n");
    return 0;
}
