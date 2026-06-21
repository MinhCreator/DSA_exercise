#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string id;
    string name;
    string class_;
    float mMath;
    float mPhysical;
    float avg() const
    {
        return (mMath + mPhysical) / 2;
    }
};
// Function to input a student
Student inputStudent()
{
    Student s;
    cin >> s.id >> s.name >> s.class_ >> s.mMath >> s.mPhysical;
    return s;
}

// Function to output a student
void outputStudent(const Student &s)
{
    cout << s.id << " " << s.name << " " << s.class_ << " " << s.mMath << " " << s.mPhysical << endl;
}

// Function to search a student by id
bool searchStudent(const vector<Student> &students, const string &id)
{
    return find_if(students.begin(), students.end(), [id](const Student &s)
                   { return s.id == id; }) != students.end();
}

// Function to sort students by avg in descending order
void sortStudents(vector<Student> &students)
{
    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
         { return a.avg() > b.avg(); });
}

int main()
{
    vector<Student> students;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        students.push_back(inputStudent());
    }
    sortStudents(students);
    string id;
    while (true)
    {
        cout << "Enter id to search (or 'q' to quit): ";
        cin >> id;
        if (id == "q")
        {
            break;
        }
        if (searchStudent(students, id))
        {
            cout << "Found!" << endl;
            for (const auto &s : students)
            {
                if (s.id == id)
                {
                    outputStudent(s);
                    break;
                }
            }
        }
        else
        {
            cout << "Not found!" << endl;
        }
    }
    return 0;
}