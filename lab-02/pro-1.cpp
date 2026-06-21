/* REQUIREMENTS
We want to manage a list of students. Information of each student consists
of  the  following  fields:  name,  date  of  birth  (day,  month,  year),  math  mark,  physic
mark,  language  mark.  Write  a  program  solving  the  following  requirements  using
singly linked list (using menu):
Read data of students from a file named StudentList.txt
a)  Input n students’ information. //input untit name=”  “
b)  Print out the student list.
c)  Add a new student to the list.
d)  Count the number of students in a given year of birth.
e)  Check if a student name x exists in the list or not.
f) Delete a student from the list by a given name x.
g)  Find the student(s) having the biggest average of math, physic and language
marks.
h)  Print the list of students whose math mark is less than 5.
i) Write the student list to a file named StudentList.txt
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;
struct student
{
    string name;
    int day;
    int month;
    int year;
    float mathMark, physicsMark, languageMark;
    student *next;
};

// Initialize the linked list
student *list = nullptr;

// Read data from file
void readFromFile(const string &filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        student *newStudent = new student;
        istringstream ss(line);
        ss >> newStudent->name >> newStudent->day >> newStudent->month >> newStudent->year >> newStudent->mathMark >> newStudent->physicsMark >> newStudent->languageMark;
        newStudent->next = list;
        list = newStudent;
    }
    file.close();
}

// Write data to file
void writeFile(const string &filename)
{
    ofstream file(filename);
    student *current = list;
    while (current != nullptr)
    {
        file << current->name << " " << current->day << " " << current->month << " " << current->year
             << " " << current->mathMark << " " << current->physicsMark << " " << current->languageMark << endl;
        current = current->next;
    }
    file.close();
}

// Add a new student to the list
void addStudent()
{
    student *newStudent = new student;
    cout << "Enter student name: ";
    getline(cin, newStudent->name);
    cout << "Enter date of birth (day month year): ";
    cin >> newStudent->day >> newStudent->month >> newStudent->year;
    cout << "Enter math mark, physics mark, language mark: ";
    cin >> newStudent->mathMark >> newStudent->physicsMark >> newStudent->languageMark;
    newStudent->next = list;
    list = newStudent;
}

// Print the student list
void printList()
{
    student *current = list;
    while (current != nullptr)
    {
        cout << current->name << " " << current->day << " " << current->month << " " << current->year
             << " " << current->mathMark << " " << current->physicsMark << " " << current->languageMark << endl;
        current = current->next;
    }
}

// Count the number of students in a given year of birth
int countStudentsInYear(int year)
{
    student *current = list;
    int count = 0;
    while (current != nullptr)
    {
        if (current->year == year)
            count++;
        current = current->next;
    }
    return count;
}

// Check if a student name x exists in the list or not
bool studentExists(const string &name)
{
    student *current = list;
    while (current != nullptr)
    {
        if (current->name == name)
            return true;
        current = current->next;
    }
    return false;
}

// Delete a student from the list by a given name x
void deleteStudent(const string &name)
{
    student **prev = &list;
    student *current = list;
    while (current != nullptr)
    {
        if (current->name == name)
        {
            *prev = current->next;
            delete current;
            return;
        }
        prev = &(current->next);
        current = current->next;
    }
}

// Find the student(s) having the biggest average of math, physics and language marks
void findStudentWithBiggestAverage()
{
    student *current = list;
    double maxAverage = 0;
    student *studentWithMaxAverage = nullptr;
    while (current != nullptr)
    {
        double average = (current->mathMark + current->physicsMark + current->languageMark) / 3.0;
        if (average > maxAverage)
        {
            maxAverage = average;
            studentWithMaxAverage = current;
        }
        current = current->next;
    }
    cout << "student with the biggest average: " << studentWithMaxAverage->name << " " << studentWithMaxAverage->mathMark << " " << studentWithMaxAverage->physicsMark << " " << studentWithMaxAverage->languageMark << endl;
}

// Print the list of students whose math mark is less than 5.
void printStudentsWithMathMarkLessThan5()
{
    student *current = list;
    while (current != nullptr)
    {
        if (current->mathMark < 5)
        {
            cout << current->name << " " << current->day << " " << current->month << " " << current->year
                 << " " << current->mathMark << " " << current->physicsMark << " " << current->languageMark << endl;
        }
        current = current->next;
    }
}

// Write the student list to a file named StudentList.txt
void writeStudentListToFile(const string &filename)
{
    ofstream file(filename);
    student *current = list;
    while (current != nullptr)
    {
        file << current->name << " " << current->day << " " << current->month << " " << current->year
             << " " << current->mathMark << " " << current->physicsMark << " " << current->languageMark << endl;
        current = current->next;
    }
    file.close();
}

int main()
{
    std::string filename = "test_input.txt";
    readFromFile(filename);

    // Check if the list is populated correctly
    assert(list != nullptr);
    assert(list->name == "John Doe");
    assert(list->mathMark == 10);

    // Check if the next student's data is correct
    student *current = list->next;
    assert(current != nullptr);
    assert(current->name == "Jane Smith");
    assert(current->mathMark == 7);

    std::string outputFile = "test_output.txt";
    writeStudentListToFile(outputFile);

    // Check if the file exists
    std::ifstream file(outputFile);
    assert(file.is_open());

    // Check if the file contains the correct data
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name;
        int mathMark;
        iss >> name >> mathMark;
        assert(name == "John Doe");
        assert(mathMark == 10);
    }
    file.close();

    return 0;
}