#include <stdio.h>
#include <string.h>

int i = 1;

struct bank {
    int number;
    int acc_no;
    int deposit;
    char name[50];
    float balance;
} bank[5];

void creat() {
    printf("\n**** CREATE YOUR ACCOUNT ****\n");

    printf("Enter your name: ");
    scanf("%s", bank[i].name);

    printf("Enter your mobile number: ");
    scanf("%d", &bank[i].number);

    printf("Enter account number: ");
    scanf("%d", &bank[i].acc_no);

    printf("Deposit minimum 100 Rs: ");
    scanf("%d", &bank[i].deposit);

    if (bank[i].deposit < 100) {
        printf("Minimum deposit should be 100 Rs\n");
        return;
    }

    bank[i].balance = bank[i].deposit;

    printf("\nCONGRATULATIONS!\n");
    printf("Your account is created successfully.\n");
}

int main() {
    int choose;

    printf("\n1. Create the account");
    printf("\n2. Display the account");
    printf("\n3. Check the balance");
    printf("\n4. Withdraw the balance");
    printf("\n5. Add the balance\n");

    scanf("%d", &choose);

    switch (choose) {
        case 1:
            creat();
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}

