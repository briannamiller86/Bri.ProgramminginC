#include <stdio.h>
#include <ctype.h>

int main() {
    double salesD = 0.0, salesE = 0.0, salesF = 0.0;
    double saleAmount;
    char initial;
    
    printf("Welcome to Holiday Homes Sales Tracker\n");
    
    do {
        printf("\nEnter salesperson initial (D, E, F) or Z to exit: ");
        scanf(" %c", &initial);
        initial = toupper(initial);  // Convert to uppercase for easier comparison
        
        if (initial == 'Z') {
            break;
        }
        
        if (initial != 'D' && initial != 'E' && initial != 'F') {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }
        
        printf("Enter sale amount: $");
        scanf("%lf", &saleAmount);
        
        switch (initial) {
            case 'D':
                salesD += saleAmount;
                break;
            case 'E':
                salesE += saleAmount;
                break;
            case 'F':
                salesF += saleAmount;
                break;
        }
        
        // Display current totals after each sale
        printf("\nCurrent Sales Totals:\n");
        printf("Danielle: $%.2f\n", salesD);
        printf("Edward: $%.2f\n", salesE);
        printf("Francis: $%.2f\n", salesF);
        printf("Current Total: $%.2f\n", salesD + salesE + salesF);
        
    } while (1);
    
    double grandTotal = salesD + salesE + salesF;
    
    printf("\nFinal Sales Summary:\n");
    printf("Danielle's sales: $%.2f\n", salesD);
    printf("Edward's sales: $%.2f\n", salesE);
    printf("Francis's sales: $%.2f\n", salesF);
    printf("Grand Total: $%.2f\n", grandTotal);
    
    // Determine highest sales
    printf("Highest Sale: ");
    if (salesD >= salesE && salesD >= salesF) {
        printf("D\n");
    } else if (salesE >= salesD && salesE >= salesF) {
        printf("E\n");
    } else {
        printf("F\n");
    }
    
    return 0;
}