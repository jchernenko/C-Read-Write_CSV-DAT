// Created by: Jeff Chenenko - A00745858
// COMP 2511 - Procedural Programming with C

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// account info struct
typedef struct {
    int accountNumber;
    char firstName[50];
    char lastName[50];
    float accountBalance;
    float lastPaymentAmount;
} Account;


int main(int argc, char *argv[]) {

    // check for correct number of arguments and exit if incorrect
    if (argc != 2) {
        printf("To run program use: %s filename\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* binFile = fopen(filename, "rb"); // open and read binary accounts.dat


    // if file doesn't exist display error and exit the program
    if (!binFile) {
        printf("Error - file '%s' does not exist.\n", filename);
        return 1;
    }


    // display column headers
    printf("AccountNumber FirstName   LastName   AccountBalance LastPaymentAmount\n");
    printf("---------------------------------------------------------------------\n");


    Account account;


    // read from binary file and output information
    while (fread(&account, sizeof(Account), 1, binFile)) {
        printf("%-13d %-11s %-11s %13.2f %16.2f\n", account.accountNumber, account.firstName, account.lastName, account.accountBalance, account.lastPaymentAmount);
    }


    // close file
    fclose(binFile);


    return 0;
}
