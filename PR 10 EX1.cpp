#include <stdio.h>

#define MAX 100

struct Employee {
    int id;
    float salary;
};

struct Employee emp[MAX], temp[MAX];
int choice;

void merge(int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if ((choice == 1 && emp[i].salary <= emp[j].salary) ||
            (choice == 2 && emp[i].salary >= emp[j].salary)) {
            temp[k++] = emp[i++];
        } else {
            temp[k++] = emp[j++];
        }
    }

    while (i <= mid)
        temp[k++] = emp[i++];

    while (j <= high)
        temp[k++] = emp[j++];

    for (i = low; i <= high; i++)
        emp[i] = temp[i];
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of employees!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter employee ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\n1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice!\n");
        return 1;
    }

    mergeSort(0, n - 1);

    if (choice == 1)
        printf("\nEmployee Records (Ascending Salary):\n");
    else
        printf("\nEmployee Records (Descending Salary):\n");

    printf("Employee ID\tSalary\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%.2f\n", emp[i].id, emp[i].salary);
    }

    return 0;
}
