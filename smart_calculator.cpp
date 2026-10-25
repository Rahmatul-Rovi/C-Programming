
#include <iostream>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int main() {
    int choice;
    double a, b;

    do {
        cout << "\n===== SMART CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Remainder\n";
        cout << "6. Power\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Calculator closed.\n";
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter two numbers: ";
        cin >> a >> b;

        switch (choice) {
            case 1:
                cout << "Result = " << add(a, b) << endl;
                break;

            case 2:
                cout << "Result = " << subtract(a, b) << endl;
                break;

            case 3:
                cout << "Result = " << multiply(a, b) << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Result = " << divide(a, b) << endl;
                else
                    cout << "Cannot divide by zero!\n";
                break;

            case 5:
                if (b != 0 &&
                    a == static_cast<int>(a) &&
                    b == static_cast<int>(b)) {
                    cout << "Remainder = "
                         << static_cast<int>(a) %
                            static_cast<int>(b) << endl;
                } else {
                    cout << "Enter non-zero integer values!\n";
                }
                break;

            case 6:
                cout << "Result = " << pow(a, b) << endl;
                break;
        }

    } while (true);

    return 0;
}

