#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3

typedef struct {
    char initial;
    char name[20];
    double totalSales;
} SalesPerson;

int main() {
    SalesPerson salesTeam[NUM_SALESPERSONS] = {
        {'D', "Danielle", 0.0},
        {'E', "Edward", 0.0},
        {'F', "Francis", 0.0}
    };

    char inputInitial;
    double saleAmount;

    printf("Welcome to Holiday Homes Sales Tracker\n");

    while (1) {
        printf("\nEnter salesperson initial (D, E, F) or Z to exit: ");
        scanf(" %c", &inputInitial);
        inputInitial = toupper(inputInitial);

        if (inputInitial == 'Z') {
            break;
        }

        int found = 0, index = -1;
        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            if (salesTeam[i].initial == inputInitial) {
                found = 1;
                index = i;
                break;
            }
        }

        if (!found) {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }

        printf("Enter sale amount: $");
        scanf("%lf", &saleAmount);

        salesTeam[index].totalSales += saleAmount;

        // Show updated totals
        double grandTotal = 0.0;
        printf("\nCurrent Sales Totals:\n");
        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            printf("%s: $%.2f\n", salesTeam[i].name, salesTeam[i].totalSales);
            grandTotal += salesTeam[i].totalSales;
        }
        printf("Current Total: $%.2f\n", grandTotal);
    }

    // Final summary
    double grandTotal = 0.0;
    printf("\nFinal Sales Summary:\n");
    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s's sales: $%.2f\n", salesTeam[i].name, salesTeam[i].totalSales);
        grandTotal += salesTeam[i].totalSales;
    }
    printf("Grand Total: $%.2f\n", grandTotal);

    // Determine highest sale
    int highestIndex = 0;
    for (int i = 1; i < NUM_SALESPERSONS; i++) {
        if (salesTeam[i].totalSales > salesTeam[highestIndex].totalSales) {
            highestIndex = i;
        }
    }
    printf("Highest Sale: %c\n", salesTeam[highestIndex].initial);

    return 0;
}
