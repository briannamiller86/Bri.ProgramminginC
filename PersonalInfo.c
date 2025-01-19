#include <stdio.h>
#include <string.h>

void runTest(int testNumber) {
    char name[50];
    char birthdate[20];
    char work_phone[20];
    char cell_phone[20];

    printf("\n=== Unit Test #%d ===\n", testNumber);
    
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    // Remove newline character if present
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    printf("Enter birthdate (MM/DD/YYYY): ");
    scanf("%s", birthdate);

    printf("Enter work phone (000-000-0000): ");
    scanf("%s", work_phone);

    printf("Enter cell phone (000-000-0000): ");
    scanf("%s", cell_phone);
    
    // Display the output
    printf("\nOutput:\n");
    printf("%s\n %s\n work %s\n cell %s\n", name, birthdate, work_phone, cell_phone);
    printf("\nTest Passed\n");
    
}

int main() {
    printf("Personal Information Test Program\n");
    printf("--------------------------------\n");

    // Run each test case
    for (int i = 1; i <= 4; i++) {
        runTest(i);
    }

    return 0;
}