
#include <iostream>
#include <string>
using namespace std;

string accountName;
int accountNumber;
double balance = 0;

void createAccount() {
    cout << "Enter account holder name: ";
    getline(cin >> ws, accountName);

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial deposit: ";
    cin >> balance;

    if (balance < 0) {
        balance = 0;
        cout << "Invalid deposit. Balance set to zero.\n";
        return;
    }

    cout << "Account created successfully!\n";
}

void checkBalance() {
    cout << "\nAccount Holder: " << accountName << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: " << balance << endl;
}

void depositMoney() {
    double amount;

    cout << "Enter deposit amount: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful!\n";
        cout << "New Balance: " << balance << endl;
    } else {
        cout << "Invalid amount!\n";
    }
}

void withdrawMoney() {
    double amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount!\n";
    }
    else if (amount > balance) {
        cout << "Insufficient balance!\n";
    }
    else {
        balance -= amount;
        cout << "Withdrawal successful!\n";
        cout << "Remaining Balance: " << balance << endl;
    }
}

int main() {
    int choice;
    bool accountCreated = false;

    do {
        cout << "\n===== BANK MANAGEMENT =====\n";
        cout << "1. Create Account\n";
        cout << "2. Check Balance\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            createAccount();
            accountCreated = true;
        }
        else if (choice >= 2 && choice <= 4) {
            if (!accountCreated) {
                cout << "Please create an account first!\n";
                continue;
            }

            switch (choice) {
                case 2:
                    checkBalance();
                    break;
                case 3:
                    depositMoney();
                    break;
                case 4:
                    withdrawMoney();
                    break;
            }
        }
        else if (choice == 0) {
            cout << "Thank you!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}

