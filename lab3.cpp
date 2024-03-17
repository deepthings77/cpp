#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float cgpi;
    int semester;
};

void displayRecords(const vector<Student>& students) {
    cout << "Roll No.\tName\tCGPI\tSemester" << endl;
    for (const auto& student : students) {
        cout << student.rollNo << "\t\t" << student.name << "\t" << fixed << setprecision(2) << student.cgpi << "\t" << student.semester << endl;
    }
}

void filterRecordsByCGPI(const vector<Student>& students, float k) {
    cout << "Students with CGPI greater than " << k << ":" << endl;
    cout << "Roll No.\tName\tCGPI\tSemester" << endl;
    for (const auto& student : students) {
        if (student.cgpi > k) {
            cout << student.rollNo << "\t\t" << student.name << "\t" << fixed << setprecision(2) << student.cgpi << "\t" << student.semester << endl;
        }
    }
}

void insertRecord(vector<Student>& students, int position, const Student& newStudent) {

    if(position <= 5){
    students.insert(students.begin() + position - 1, newStudent);
    cout << "Record inserted successfully at position " << position << endl;

    } else {
        cout<< "Invalid Position";
    }
}

int main() {
    cout << "Deepak Kumawat" << endl << "Roll no - 22BCS034" << endl;
    vector<Student> students;
    int choice;
    float k;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter Records\n";
        cout << "2. List all records of students having CGPI greater than a specific value\n";
        cout << "3. Insert a new record at a specific position\n";
        cout << "4. Display all records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter records of five students:\n";
                for (int i = 0; i < 5; ++i) {
                    Student student;
                    cout << "Enter Roll No. for student " << i + 1 << ": ";
                    cin >> student.rollNo;
                    cout << "Enter Name for student " << i + 1 << ": ";
                    cin>>student.name;
                    cout << "Enter CGPI for student " << i + 1 << ": ";
                    cin >> student.cgpi;
                    cout << "Enter Semester for student " << i + 1 << ": ";
                    cin >> student.semester;
                    students.push_back(student);
                }
                break;
            }
            case 2: {
                cout << "Enter the CGPI threshold: ";
                cin >> k;
                filterRecordsByCGPI(students, k);
                break;
            }
            case 3: {
                int position;
                Student newStudent;
                cout << "Enter the position to insert new record: ";
                cin >> position;
                cout << "Enter Roll No. for new student: ";
                cin >> newStudent.rollNo;
                cout << "Enter Name for new student: ";
                cin>>newStudent.name;
                cout << "Enter CGPI for new student: ";
                cin >> newStudent.cgpi;
                cout << "Enter Semester for new student: ";
                cin >> newStudent.semester;
                insertRecord(students, position, newStudent);
                break;
            }
            case 4: {
                displayRecords(students);
                break;
            }
            case 5: {
                cout << "Exiting program...\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    }

    return 0;
}
