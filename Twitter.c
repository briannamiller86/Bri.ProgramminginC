#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 140

int main() {
    char message[1000];  // Buffer large enough for any test input
    
    // Get input from user
    // Using fgets to handle spaces in input
    fgets(message, sizeof(message), stdin);
    
    // Remove trailing newline if present
    size_t len = strlen(message);
    if (len > 0 && message[len-1] == '\n') {
        message[len-1] = '\0';
        len--;
    }
    
    // Check message length and print result
    if (len <= MAX_LENGTH) {
        printf("Posted\n");
    } else {
        printf("Rejected\n");
    }
    
    return 0;
}