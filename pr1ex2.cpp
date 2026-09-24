#include <iostream>
using namespace std;

struct Student
{
    int roll;
    string name;
    float marks;
};

void display(Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nRoll No: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nMarks: " << s[i].marks << endl;
    }
}

void search(Student *s, int n, int roll)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            cout << "\nStudent Found";
            cout << "\nName: " << s[i].name;
            cout << "\nMarks: " << s[i].marks;
            return;
        }
    }

    cout << "\nStudent Not Found";
}

void update(Student *s, int n, int roll)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            cout << "Enter new marks: ";
            cin >> s[i].marks;
            cout << "Record Updated";
            return;
        }
    }

    cout << "Student Not Found";
}

int main()
{
    Student s[10];
    int n, roll;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Roll No: ";
        cin >> s[i].roll;

        cout << "Enter Name: ";
        cin >> s[i].name;

        cout << "Enter Marks: ";
        cin >> s[i].marks;
    }

    cout << "\n--- Student Records ---";
    display(s, n);

    cout << "\n\nEnter roll number to search: ";
    cin >> roll;
    search(s, n, roll);

    cout << "\n\nEnter roll number to update marks: ";
    cin >> roll;
    update(s, n, roll);

    cout << "\n\n--- Updated Records ---";
    display(s,n);

    return 0;
}
