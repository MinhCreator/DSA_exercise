#include <iostream>
#include <cstring>

using namespace std;

struct Student
{
    char name[30];
    char className[10]; 
    float mMath;
    float mPhysical;
};

// Function Prototypes
void addStudent(Student *s, int &count);
void searchByName(Student *s, int count);
void editClassByName(Student *s, int count);

int main()
{
    // Dynamic allocation using 'new'
    Student *s = new Student[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n--- Student Management (Char Array Version) ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Edit Student Class" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer

        switch (choice)
        {
        case 1:
            addStudent(s, count);
            break;
        case 2:
            searchByName(s, count);
            break;
        case 3:
            editClassByName(s, count);
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    delete[] s; // Free allocated memory
    return 0;
}

// a) Add a new student
void addStudent(Student *s, int &count)
{
    if (count >= 100)
    {
        cout << "List is full!" << endl;
        return;
    }

    cout << "Enter name: ";
    cin.getline(s[count].name, 30);

    cout << "Enter class: ";
    cin.getline(s[count].className, 10);

    cout << "Enter Math: ";
    cin >> s[count].mMath;
    cout << "Enter Physics: ";
    cin >> s[count].mPhysical;
    cin.ignore(); // Clean buffer for the next string input

    count++;
    cout << "Student added." << endl;
}

// b) Search a student by name
void searchByName(Student *s, int count)
{
    char query[30];
    cout << "Enter name to search: ";
    cin.getline(query, 30);

    for (int i = 0; i < count; i++)
    {
        // strcmp returns 0 if the strings are identical
        if (strcmp(s[i].name, query) == 0)
        {
            cout << "Found: " << s[i].name << " | Class: " << s[i].className
                 << " | Math: " << s[i].mMath << " | Phys: " << s[i].mPhysical << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// c) Search by name and edit class
void editClassByName(Student *s, int count)
{
    char query[30];
    cout << "Enter name to edit: ";
    cin.getline(query, 30);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(s[i].name, query) == 0)
        {
            cout << "Current class: " << s[i].className << endl;
            cout << "Enter new class: ";
            cin.getline(s[i].className, 10);
            cout << "Class updated successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}