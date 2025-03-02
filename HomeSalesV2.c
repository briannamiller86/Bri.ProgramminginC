#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3

int main() {
    char salespersons[NUM_SALESPERSONS] = {'D', 'E', 'F'};
    char *names[NUM_SALESPERSONS] = {"Danielle", "Edward", "Francis"};
    double sales[NUM_SALESPERSONS] = {0.0, 0.0, 0.0};
    
    double saleAmount;
    char initial;
    
    printf("Welcome to Holiday Homes Sales Tracker\n");
    
    do {
        printf("\nEnter salesperson initial (D, E, F) or Z to exit: ");
        scanf(" %c", &initial);
        initial = toupper(initial);
        
        if (initial == 'Z') {
            break;
        }
        
        int valid = 0, index = -1;
        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            if (salespersons[i] == initial) {
                valid = 1;
                index = i;
                break;
            }
        }
        
        if (!valid) {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }
        
        printf("Enter sale amount: $");
        scanf("%lf", &saleAmount);
        
        sales[index] += saleAmount;
        
        // Display current totals after each sale
        printf("\nCurrent Sales Totals:\n");
        double grandTotal = 0.0;
        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            printf("%s: $%.2f\n", names[i], sales[i]);
            grandTotal += sales[i];
        }
        printf("Current Total: $%.2f\n", grandTotal);
        
    } while (1);
    
    double grandTotal = 0.0;
    printf("\nFinal Sales Summary:\n");
    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s's sales: $%.2f\n", names[i], sales[i]);
        grandTotal += sales[i];
    }
    printf("Grand Total: $%.2f\n", grandTotal);
    
    // Determine highest sales
    int highestIndex = 0;
    for (int i = 1; i < NUM_SALESPERSONS; i++) {
        if (sales[i] > sales[highestIndex]) {
            highestIndex = i;
        }
    }
    printf("Highest Sale: %c\n", salespersons[highestIndex]);
    
    return 0;
}
