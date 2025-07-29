#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    string name;
    string student_id;
    string department;
    string address;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // Clear newline from buffer

    vector<Student> students(n);

    // Input student data
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Student ID: ";
        getline(cin, students[i].student_id);
        cout << "Department: ";
        getline(cin, students[i].department);
        cout << "Address: ";
        getline(cin, students[i].address);
    }

    // Write to file
    ofstream fout("students.txt");
    if (!fout) {
        cout << "Error opening file for writing.\n";
        return 1;
    }
    for (const auto& s : students) {
        fout << s.name << '\n'
             << s.student_id << '\n'
             << s.department << '\n'
             << s.address << '\n';
    }
    fout.close();

    // Read from file and display
    ifstream fin("students.txt");
    if (!fin) {
        cout << "Error opening file for reading.\n";
        return 1;
    }
    cout << "\nStudent Information Retrieved from File:\n";
    Student s;
    int count = 1;
    while (getline(fin, s.name) &&
           getline(fin, s.student_id) &&
           getline(fin, s.department) &&
           getline(fin, s.address)) {
        cout << "\nStudent " << count++ << ":\n";
        cout << "Name      : " << s.name << endl;
        cout << "Student ID: " << s.student_id << endl;
        cout << "Department: " << s.department << endl;
        cout << "Address   : " << s.address << endl;
    }
    fin.close();

    return 0;
}