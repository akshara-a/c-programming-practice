#include <stdio.h>
#include <stdlib.h>

enum continue_choice {
    CONTINUE = 1,
    EXIT = 2
};

struct Bankacc {
    int accNum;
    char accHolder[100];
    float Bal;
};

void createacc(struct Bankacc *acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc->accNum);
    printf("Enter Account Holder Name: ");
    scanf("%s", acc->accHolder);
    acc->Bal = 0.0;
    printf("Account created successfully!\n");
}

void deposit(struct Bankacc *acc) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    acc->Bal += amount;
    printf("Deposit successful! Current Balance is %.2f\n", acc->Bal);
}

void withdraw(struct Bankacc *acc) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > acc->Bal) {
        printf("Insufficient funds!\n");
    } else {
        acc->Bal -= amount;
        printf("Withdrawal successful! Current Balance: %.2f\n", acc->Bal);
    }
}

void checkBal(struct Bankacc *acc) {
    printf("Account Holder: %s\n", acc->accHolder);
    printf("Account Number: %d\n", acc->accNum);
    printf("Current Balance: %.2f\n", acc->Bal);
}

int main() {
    struct Bankacc acc;
    int choice;
    enum continue_choice continue_choice;

    do {
        printf("\nBank Management System\n");
        printf("1. Create acc\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createacc(&acc);
                break;
            case 2:
                deposit(&acc);
                break;
            case 3:
                withdraw(&acc);
                break;
            case 4:
                checkBal(&acc);
                break;
            case 5:
                printf("Exiting the program!\n");
                continue_choice = EXIT;
                break;
            default:
                printf("Invalid choice!\n");
        }

        if (choice != 5) {
            printf("Do you want to perform another operation? (1 for Yes / 2 for No): ");
            scanf("%d", (int*)&continue_choice);
        }
    } while (continue_choice == CONTINUE);

    return 0;
}
