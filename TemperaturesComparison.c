#include <stdio.h>

#define MIN_TEMP -30
#define MAX_TEMP 130
#define DAYS 5

void getTemperatures(int temps[]);
void analyzeTemperatures(int temps[]);
float calculateAverage(int temps[]);

int main() {
    int temperatures[DAYS];
    
    getTemperatures(temperatures);
    analyzeTemperatures(temperatures);
    
    printf("5-day Temperature [");
    for (int i = 0; i < DAYS; i++) {
        printf("%d", temperatures[i]);
        if (i < DAYS - 1) printf(", ");
    }
    printf("]\n");
    
    printf("Average Temperature is %.1f degrees\n", calculateAverage(temperatures));
    
    return 0;
}

void getTemperatures(int temps[]) {
    for (int i = 0; i < DAYS; i++) {
        int temp;
        while (1) {
            printf("Enter Temperature %d: ", i + 1);
            scanf("%d", &temp);
            if (temp < MIN_TEMP || temp > MAX_TEMP) {
                printf("EXCEPTION Temperature %d is invalid, Please enter a valid temperature between -30 and 130\n", temp);
            } else {
                temps[i] = temp;
                break;
            }
        }
    }
}

void analyzeTemperatures(int temps[]) {
    int ascending = 1, descending = 1;
    
    for (int i = 1; i < DAYS; i++) {
        if (temps[i] > temps[i - 1]) {
            descending = 0;
        } else if (temps[i] < temps[i - 1]) {
            ascending = 0;
        }
    }
    
    if (ascending) {
        printf("OUTPUT Getting Warmer\n");
    } else if (descending) {
        printf("OUTPUT Getting Colder\n");
    } else {
        printf("OUTPUT It's a mixed bag\n");
    }
}

float calculateAverage(int temps[]) {
    int sum = 0;
    for (int i = 0; i < DAYS; i++) {
        sum += temps[i];
    }
    return (float)sum / DAYS;
}
