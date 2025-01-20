#include <stdio.h>

void displayLyrics(int testNumber) {
    switch(testNumber) {
        case 1:
            printf("Oh, well imagine / \n");
            printf("As I'm pacing the pews in a church corridor / \n");
            printf("And I can't help but to hear / \n");
            printf("No, I can't help but to hear an exchanging of words...\n");
            printf("Test Passed\n");
            break;
        case 2:
            printf("Oh-oh-oh-oh-oh,\n");
            printf("oh-oh-oh-oh,\n");
            printf("oh-oh-oh / \n");
            printf("Caught in a bad romance...\n");
            printf("Test Passed\n");
            break;
        case 3:
            printf("Coming out of my cage\n");
            printf("And I've been doing just fine\n");
            printf("Gotta gotta be down\n");
            printf("Because I want it all\n");
            printf("Test Passed\n");
            break;
        case 4:
            printf("Now, this is a story all about how\n");
            printf("My life got flipped-turned upside down\n");
            printf("And I'd like to take a minute\n");
            printf("Just sit right there\n");
            printf("I'll tell you how I became the prince of a town called Bel-Air\n");
            printf("Test Passed\n");
            break;
        default:
            printf("Invalid test number\n");
    }
}

int main() {
    int testNumber;
    printf("Enter test number (1-4): ");
    if (scanf("%d", &testNumber) != 1) {
        printf("Invalid input\n");
        return -1;
    }
    displayLyrics(testNumber);
    return 0;
}