
#include <stdio.h>

struct Account {
    int number;
    char name[50];
    float balance;
};

struct Account accounts[100];
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= 100) {
        printf("Account limit reached!\n");
        return;
    }

    int number;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].number == number) {
            printf("Account already exists!\n");
            return;
        }
    }

    accounts[totalAccounts].number = number;

    printf("Enter Account Holder Name: ");
    scanf(" %49[^\n]", accounts[totalAccounts].name);

    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[totalAccounts].balance);

    if (accounts[totalAccounts].balance < 0) {
        printf("Invalid balance!\n");
        return;
    }

    totalAccounts++;
    printf("Account created successfully!\n");
}

int findAccount(int number) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].number == number)
            return i;
    }

    return -1;
}

void showAccounts() {
    if (totalAccounts == 0) {
        printf("No accounts found!\n");
        return;
    }

    for (int i = 0; i < totalAccounts; i++) {
        printf("\n----------------------\n");
        printf("Account Number: %d\n", accounts[i].number);
        printf("Holder Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
    }
}

void checkBalance() {
    int number;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1) {
        printf("Account not found!\n");
    } else {
        printf("Account Holder: %s\n", accounts[index].name);
        printf("Current Balance: %.2f\n",
               accounts[index].balance);
    }
}

void depositMoney() {
    int number;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    } else {
        accounts[index].balance += amount;
        printf("Deposit successful!\n");
        printf("New Balance: %.2f\n",
               accounts[index].balance);
    }
}

void withdrawMoney() {
    int number;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    }
    else if (amount > accounts[index].balance) {
        printf("Insufficient balance!\n");
    }
    else {
        accounts[index].balance -= amount;
        printf("Withdrawal successful!\n");
        printf("Remaining Balance: %.2f\n",
               accounts[index].balance);
    }
}

void totalBankBalance() {
    float sum = 0;

    for (int i = 0; i < totalAccounts; i++) {
        sum += accounts[i].balance;
    }

    printf("Total Accounts: %d\n", totalAccounts);
    printf("Total Bank Balance: %.2f\n", sum);
}

int main() {
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Show All Accounts\n");
        printf("3. Check Balance\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Total Bank Balance\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                showAccounts();
                break;

            case 3:
                checkBalance();
                break;

            case 4:
                depositMoney();
                break;

            case 5:
                withdrawMoney();
                break;

            case 6:
                totalBankBalance();
                break;

            case 0:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}

