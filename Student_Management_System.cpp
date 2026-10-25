
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

Student students[100];
int total = 0;

void addStudent() {
    if (total >= 100) {
        cout << "Student limit reached!\n";
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[total].id;

    cout << "Enter student name: ";
    getline(cin >> ws, students[total].name);

    cout << "Enter marks (0-100): ";
    cin >> students[total].marks;

    if (students[total].marks < 0 ||
        students[total].marks > 100) {
        cout << "Invalid marks!\n";
        return;
    }

    total++;
    cout << "Student added successfully!\n";
}

void showStudents() {
    if (total == 0) {
        cout << "No student records found.\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nMarks: " << students[i].marks;

        if (students[i].marks >= 80)
            cout << "\nGrade: A+";
        else if (students[i].marks >= 70)
            cout << "\nGrade: A";
        else if (students[i].marks >= 60)
            cout << "\nGrade: A-";
        else if (students[i].marks >= 50)
            cout << "\nGrade: B";
        else if (students[i].marks >= 40)
            cout << "\nGrade: C";
        else
            cout << "\nGrade: F";

        cout << "\n-------------------\n";
    }
}

void searchStudent() {
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID;

    for (int i = 0; i < total; i++) {
        if (students[i].id == searchID) {
            cout << "Student found!\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search Student\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 0:
                cout << "Program closed.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
