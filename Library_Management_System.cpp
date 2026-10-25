
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    bool issued;
};

Book books[100];
int totalBooks = 0;

void addBook() {
    if (totalBooks >= 100) {
        cout << "Library storage is full!\n";
        return;
    }

    cout << "Enter book ID: ";
    cin >> books[totalBooks].id;

    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == books[totalBooks].id) {
            cout << "Book ID already exists!\n";
            return;
        }
    }

    cout << "Enter book title: ";
    getline(cin >> ws, books[totalBooks].title);

    books[totalBooks].issued = false;
    totalBooks++;

    cout << "Book added successfully!\n";
}

void showBooks() {
    if (totalBooks == 0) {
        cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < totalBooks; i++) {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;

        if (books[i].issued)
            cout << "\nStatus: Issued\n";
        else
            cout << "\nStatus: Available\n";
    }
}

int findBook(int id) {
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}

void issueBook() {
    int id;

    cout << "Enter book ID to issue: ";
    cin >> id;

    int index = findBook(id);

    if (index == -1) {
        cout << "Book not found!\n";
    }
    else if (books[index].issued) {
        cout << "Book is already issued!\n";
    }
    else {
        books[index].issued = true;
        cout << "Book issued successfully!\n";
    }
}

void returnBook() {
    int id;

    cout << "Enter book ID to return: ";
    cin >> id;

    int index = findBook(id);

    if (index == -1) {
        cout << "Book not found!\n";
    }
    else if (!books[index].issued) {
        cout << "This book was not issued.\n";
    }
    else {
        books[index].issued = false;
        cout << "Book returned successfully!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                showBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 0:
                cout << "Library system closed.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

