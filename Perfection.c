#include <stdio.h>

// Function to calculate sum of proper divisors
int sumOfDivisors(int num) {
    int sum = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// Function to check if a number is perfect
int isPerfectNumber(int num) {
    return sumOfDivisors(num) == num;
}

// Function to get user input
int getUserInput() {
    int number;
    printf("Enter a number to check if it's perfect: ");
    scanf("%d", &number);
    return number;
}

// Function to display the result
void displayResult(int number) {
    if (isPerfectNumber(number)) {
        printf("Perfect Number\n");
    } else {
        printf("Not A Perfect Number\n");
    }
}

int main() {
    int number = getUserInput();
    displayResult(number);
    return 0;
}
