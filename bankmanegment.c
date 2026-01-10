#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 1;

struct bank {
    int accno, num, pin;
    char name[50];
    int balance;
    char nominee[50], address[50];
} bank[55];
void createAccount() {
    printf("Enter Account Name: ");
    scanf("%s", bank[i].name);
    printf("Enter Account Number: ");
    scanf("%d", &bank[i].accno);
    printf("Enter Mobile Number: ");
    scanf("%d", &bank[i].num);
    printf("Enter Address: ");
    scanf("%s", bank[i].address);
    printf("Enter Security PIN: ");
    scanf("%d", &bank[i].pin);
    printf("Enter Nominee Name: ");
    scanf("%s", bank[i].nominee);
    bank[i].balance = 0;  
    printf("\n\t▪︎▪︎▪︎ Account Created Successfully ▪︎▪︎▪︎\n\n");
    i++;
}

void displayAccount() {
    int acc, pin, found = 0;
    printf("Enter your account number: ");
    scanf("%d", &acc);
    printf("Enter PIN: ");
    scanf("%d", &pin);
    for (int j = 1; j < i; j++) {
        if (acc == bank[j].accno && pin == bank[j].pin) {
            printf("\t*** Your Account Details ***\n");
            printf("Account Name: %s\n", bank[j].name);
            printf("Account Number: %d\n", bank[j].accno);
            printf("Phone Number: %d\n", bank[j].num);
            printf("Address: %s\n", bank[j].address);
            printf("Balance: Rs. %d\n", bank[j].balance);
            printf("Nominee Name: %s\n", bank[j].nominee);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid account number or PIN! Please try again.\n");
    }
}

void depositMoney() {
    int acc, pin, amount, found = 0;
    printf("\nEnter your account number: ");
    scanf("%d", &acc);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    
    for (int j = 1; j < i; j++) {
        if (acc == bank[j].accno && pin == bank[j].pin) {
            printf("Enter deposit amount: ");
            scanf("%d", &amount);
            bank[j].balance += amount;
            printf("Rs. %d deposited successfully.\n", amount);
            printf("New balance: Rs. %d\n\n", bank[j].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid account number or PIN! Please try again.\n");
    }
}

void withdrawMoney() {
    int acc, pin, amount, found = 0;
    printf("\nEnter your account number: ");
    scanf("%d", &acc);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    
    for (int j = 1; j < i; j++) {
        if (acc == bank[j].accno && pin == bank[j].pin) {
            printf("Enter withdrawal amount: ");
            scanf("%d", &amount);
            if (amount > bank[j].balance) {
                printf("Insufficient balance!\n");
            } else {
                bank[j].balance -= amount;
                printf("Rs. %d withdrawn successfully.\n", amount);
                printf("New balance: Rs. %d\n\n", bank[j].balance);
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Invalid account number or PIN! Please try again.\n");
    }
}

// ATM Management System
void atmMenu() {
    int acc, pin, choice, found = 0;
    
    printf("\n--- ATM Management System ---\n");
    printf("Enter your account number: ");
    scanf("%d", &acc);
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    
    for (int j = 1; j < i; j++) {
        if (acc == bank[j].accno && pin == bank[j].pin) {
            found = 1;
            while (1) {
                printf("\n--- ATM Menu ---\n");
                printf("1. Withdraw Cash\n");
                printf("2. Check Balance\n");
                printf("3. Change PIN\n");
                printf("4. Exit ATM\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        withdrawMoney();
                        break;
                    case 2:
                        printf("Your current balance: Rs. %d\n", bank[j].balance);
                        break;
                    case 3:
                        printf("Enter new PIN: ");
                        scanf("%d", &bank[j].pin);
                        printf("PIN changed successfully!\n");
                        break;
                    case 4:
                        return;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            }
        }
    }
    if (!found) {
        printf("Invalid account number or PIN! Please try again.\n");
    }
}

void bankingMenu() {
    int choice;
    while (1) {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create an Account\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void main() {
    int choice;
    while (1) {
        printf("\n\t\t*** Welcome ***\n");
        printf("\t\t==============\n");
        printf("1. Banking Management System\n");
        printf("2. ATM     Management System\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bankingMenu();
                break;
            case 2:
                atmMenu();
                break;
            case 3:
                printf("Thank you for using our services!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

