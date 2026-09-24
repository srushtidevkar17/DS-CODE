#include <iostream>
using namespace std;

string stack[10];
int top = -1;

void push()
{
    string url;
    cout << "Enter webpage URL: ";
    cin >> url;

    if (top == 9)
        cout << "Stack is full";
    else
    {
        top++;
        stack[top] = url;
        cout << "Webpage visited.\n";
    }
}

void pop()
{
    if (top == -1)
        cout << "No webpage to go back.";
    else
    {
        cout << "Going back from: " << stack[top] << endl;
        top--;
    }
}

void peek()
{
    if (top == -1)
        cout << "Stack is empty.";
    else
        cout << "Current webpage: " << stack[top] << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty.";
        return;
    }

    cout << "\nVisited Webpages:\n";

    for (int i = top; i >= 0; i--)
        cout << stack[i] << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Push";
        cout << "\n2. Pop (Back)";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
}
