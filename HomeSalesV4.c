#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3
#define FILE_NAME "salespersons.dat"

typedef struct {
    char initial;
    char name[20];
    double totalSales;
} SalesPerson;

// Function to load salespeople from a file
void loadSalesPeople(SalesPerson salesTeam[]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        fscanf(file, " %c %s %lf", &salesTeam[i].initial, salesTeam[i].name, &salesTeam[i].totalSales);
    }

    fclose(file);
}

// Function to save salespeople data to a file
void saveSalesPeople(SalesPerson salesTeam[]) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error opening file to save data!\n");
        return;
    }

    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        fprintf(file, "%c %s %.2f\n", salesTeam[i].initial, salesTeam[i].name, salesTeam[i].totalSales);
    }

    fclose(file);
}

int main() {
    SalesPerson salesTeam[NUM_SALESPERSONS];
    loadSalesPeople(salesTeam);

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

        saveSalesPeople(salesTeam);  // Save the updated data back to the file
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
