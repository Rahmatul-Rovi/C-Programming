
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[100];
int total = 0;

void addStudent() {
    if (total >= 100) {
        printf("Student limit is full!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &students[total].id);

    for (int i = 0; i < total; i++) {
        if (students[i].id == students[total].id) {
            printf("This ID already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[total].name);

    printf("Enter Marks (0-100): ");
    scanf("%f", &students[total].marks);

    if (students[total].marks < 0 ||
        students[total].marks > 100) {
        printf("Invalid marks!\n");
        return;
    }

    total++;
    printf("Student added successfully!\n");
}

void showStudents() {
    if (total == 0) {
        printf("No student records found!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\n----------------------\n");
        printf("Student ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);

        if (students[i].marks >= 80)
            printf("Grade: A+\n");
        else if (students[i].marks >= 70)
            printf("Grade: A\n");
        else if (students[i].marks >= 60)
            printf("Grade: A-\n");
        else if (students[i].marks >= 50)
            printf("Grade: B\n");
        else if (students[i].marks >= 40)
            printf("Grade: C\n");
        else
            printf("Grade: F\n");

        if (students[i].marks >= 40)
            printf("Status: Pass\n");
        else
            printf("Status: Fail\n");
    }
}

void searchStudent() {
    int id, found = 0;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Student not found!\n");
}

void calculateAverage() {
    if (total == 0) {
        printf("No marks available!\n");
        return;
    }

    float sum = 0;

    for (int i = 0; i < total; i++) {
        sum += students[i].marks;
    }

    printf("Total Students: %d\n", total);
    printf("Average Marks: %.2f\n", sum / total);
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Average Marks\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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

            case 4:
                calculateAverage();
                break;

            case 0:
                printf("Program closed!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}

