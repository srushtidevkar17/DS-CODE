#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Book {
    int id;
    char title[100];
    char author[100];
};

int linearSearchID(struct Book books[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (books[i].id == id)
            return i;
    }
    return -1;
}

int equalIgnoreCase(char a[], char b[]) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) !=
            tolower((unsigned char)*b))
            return 0;
        a++;
        b++;
    }
    return *a == '\0' && *b == '\0';
}

int linearSearchText(struct Book books[], int n,
                     char key[], int choice) {
    for (int i = 0; i < n; i++) {
        if ((choice == 2 &&
             equalIgnoreCase(books[i].title, key)) ||
            (choice == 3 &&
             equalIgnoreCase(books[i].author, key))) {
            return i;
        }
    }
    return -1;
}

void displayBook(struct Book b) {
    printf("\nBook Found!\n");
    printf("Book ID   : %d\n", b.id);
    printf("Title     : %s\n", b.title);
    printf("Author    : %s\n", b.author);
}

int main() {
    struct Book books[MAX];
    int n, choice, id, result;
    char key[100];

    printf("Enter number of books: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of books.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of book %d\n", i + 1);

        printf("Book ID: ");
        scanf("%d", &books[i].id);
        getchar();

        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
    }

    printf("\n--- Library Book Search ---\n");
    printf("1. Search by Book ID\n");
    printf("2. Search by Title\n");
    printf("3. Search by Author Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &id);
            result = linearSearchID(books, n, id);
            break;

        case 2:
            printf("Enter book title: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';
            result = linearSearchText(books, n, key, choice);
            break;

        case 3:
            printf("Enter author name: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';
            result = linearSearchText(books, n, key, choice);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    if (result != -1)
        displayBook(books[result]);
    else
        printf("\nBook not found.\n");

    return 0;
}
