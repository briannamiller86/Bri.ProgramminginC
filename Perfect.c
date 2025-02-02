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

int main() {
    int number;
    
    printf("Enter a number to check if it's perfect: ");
    scanf("%d", &number);
    
    int divisorSum = sumOfDivisors(number);
    
    if(divisorSum == number) {
        printf("Perfect Number\n");
    } else {
        printf("Not A Perfect Number\n");
    }
    
    return 0;
}