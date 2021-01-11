/* 
 * Prog 1a calculates the amount of months required to pay off a loan, 
 * as well as the total interest that compounds throughout.
 * This program takes in input through std. 
 * 
 * Prog 1a
 * Dalton Tarde
 * CS-320 Section 1
 * September 9, 2020
 */ 

#include<stdio.h>
#include<stdlib.h> 

/* Class Prototypes: */ 
void printId(); 
void getLoanFactors(double *loanAmt, double *intRate, double *paymentAmt); 
int getMonths(double loanAmt, double intRate, double paymentAmt, double *totalInt); 

/**
 * Identification printout for Edoras 
 *
 * @return void 
 */
void printId() { 
    printf("Program 1A, cssc2670, Dalton Tarde\n\n");  
}

/**
 * Take in and format loanAmt, intRate, and paymentAmt through command line
 *
 * @param argv[], loanAmt, intRate, paymentAmt 
 * @return void 
 */
void getLoanFactors(double *loanAmt, double *intRate, double *paymentAmt) {
    printf("$"); 
    printf("%.2lf", *loanAmt); 
    printf(" Loan amount\n    "); 

    printf("%.2lf", *intRate);
    printf(" Annual interest rate\n $"); 

    printf("%.2lf", *paymentAmt); 
    printf(" Monthly Payment\n\n"); 
}

/**
 * Take in loanAmt, intRate, paymentAmt, and undeclared totalInt, iterate through
 * and return a table that shows decrementing loanAmt, incrementing month, and totalInt
 *
 * @param loanAmt, intRate, paymentAmt, *totalInt 
 * @return int (incremented month count) 
 */
int getMonths(double loanAmt, double intRate, double paymentAmt, double *totalInt) {
    *totalInt = 0; 
    int month = 0;
    double lastTotalInt = 0;
    
    printf("LoanAmt  Month  TotalInt\n"); 
    while (loanAmt > 0.0) { 
        *totalInt += (loanAmt / 12.0) * intRate; 
        loanAmt = (loanAmt - paymentAmt) - lastTotalInt + *totalInt;
        lastTotalInt = *totalInt; 
        month++; 
        printf("%8.2f%6d%10.2f\n", loanAmt, month, *totalInt); 
    }
    return month; 
}

/**
 * Order goes from printId(), scanner, getLoanFactors(), and then 
 * return months and total interest paid 
 *
 * @return int (1) 
 */
int main() {
    /* 
     * loanAmt: The starting amount of the loan in dollars
     * intRate: The annual interest rate between 0 and 1.0; example: 18% is entered as 0.18
     * paymentAmt: The monthly payment made toward the loan in dollars
     * totalInt: The total amount of interest in dollars paid over the life of the loan
    */
    double loanAmt, intRate, paymentAmt, totalInt; 

    printId(); 

    scanf("%lf", &loanAmt); 
    scanf("%lf", &intRate); 
    scanf("%lf", &paymentAmt); 

    getLoanFactors(&loanAmt, &intRate, &paymentAmt); 

    int monthsRemaining = getMonths(loanAmt, intRate, paymentAmt, &totalInt); 
    
    printf("\n"); 
    printf("%d", monthsRemaining);
    printf(" months to pay off loan \n$");
    printf("%.2lf", totalInt);
    printf(" total interest paid\n");

    return 0; 
}
