#include <iostream>
using namespace std;

struct Employee
{
    int id;
    string name;
    Employee *next;
};
Employee *head = NULL;
void insert()
{
    Employee *newNode = new Employee;
    cout << "Enter ID: ";
    cin >> newNode->id;
    cout << "Enter Name: ";
    cin >> newNode->name;
    newNode->next = head;
    head = newNode;
}
void display()
{
    Employee *temp = head;
    while (temp != NULL)
    {
        cout << "\nID: " << temp->id;
        cout << "\nName: " << temp->name << endl;
        temp = temp->next;
    }
}
void search()
{
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    Employee *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Employee Found!";
            return;
        }
        temp = temp->next;
    }
    cout << "Employee Not Found!";
}
void deleteEmployee()
{
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    Employee *temp = head;
    Employee *prev = NULL;
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Employee Not Found!";
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    delete temp;
    cout << "Employee Deleted!";
}
int main()
{
    insert();
    insert();
    cout << "\nEmployees:";
    display();
    search();
    deleteEmployee();
    cout << "\nEmployees after deletion:";
    display();
    return 0;
}
