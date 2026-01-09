#include <stdio.h>
#include <string.h>

int i = 0;

struct bank {
    char name[50];
    int mobile;
    int acc_no;
    float balance;
} bank[5];

void createAccount() {
    if (i >= 5) {
        printf("Account limit reached!\n");
        return;
    }

    printf("\n--- Create Bank Account ---\n");
    printf("Enter Name: ");
    scanf("%s", bank[i].name);

    printf("Enter Mobile No: ");
    scanf("%d", &bank[i].mobile);

    printf("Enter Account No: ");
    scanf("%d", &bank[i].acc_no);

    printf("Enter Initial Deposit (min 100): ");
    scanf("%f", &bank[i].balance);

    if (bank[i].balance < 100) {
        printf("Minimum deposit must be 100\n");
        return;
    }

    printf("Account Created Successfully!\n");
    i++;
}

void displayAccount() {
    if (i == 0) {
        printf("No accounts available\n");
        return;
    }
    int j;
    for ( j = 0; j < i; j++) {
        printf("\nAccount %d\n", j + 1);
        printf("Name: %s\n", bank[j].name);
        printf("Mobile: %d\n", bank[j].mobile);
        printf("Account No: %d\n", bank[j].acc_no);
        printf("Balance: %.2f\n", bank[j].balance);
    }
}

void atmMenu() {
    int acc, choice;
    float amount;
    int found = -1;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);
     int j;
    for ( j = 0; j < i; j++) {
        if (bank[j].acc_no == acc) {
            found = j;
            break;
        }
    }

    if (found == -1) {
        printf("Account not found!\n");
        return;
    }

    while (1) {
        printf("\n--- ATM MENU ---");
        printf("\n1. Check Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Exit ATM\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current Balance: %.2f\n", bank[found].balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                bank[found].balance += amount;
                printf("Amount Deposited Successfully\n");
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > bank[found].balance) {
                    printf("Insufficient Balance\n");
                } else {
                    bank[found].balance -= amount;
                    printf("Please collect your cash\n");
                }
                break;

            case 4:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n====== MAIN MENU ======");
        printf("\n1. Bank System");
        printf("\n2. ATM System");
        printf("\n3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                displayAccount();
                break;

            case 2:
                atmMenu();
                break;

            case 3:
                printf("Thank you for using Bank System\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
