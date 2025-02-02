#include <stdio.h>

int main() {
    // Constants for wind speed thresholds
    const float CAT5_THRESHOLD = 157.0f;
    const float CAT4_THRESHOLD = 130.0f;
    const float CAT3_THRESHOLD = 111.0f;
    const float CAT2_THRESHOLD = 96.0f;
    const float CAT1_THRESHOLD = 74.0f;
    
    float windSpeed;
    
    // Get input from user
    printf("Enter wind speed (mph): ");
    scanf("%f", &windSpeed);
    
    // Classify hurricane based on wind speed
    if (windSpeed >= CAT5_THRESHOLD) {
        printf("Category Five Hurricane\n");
    }
    else if (windSpeed >= CAT4_THRESHOLD) {
        printf("Category Four Hurricane\n");
    }
    else if (windSpeed >= CAT3_THRESHOLD) {
        printf("Category Three Hurricane\n");
    }
    else if (windSpeed >= CAT2_THRESHOLD) {
        printf("Category Two Hurricane\n");
    }
    else if (windSpeed >= CAT1_THRESHOLD) {
        printf("Category One Hurricane\n");
    }
    else {
        printf("Not a Hurricane\n");
    }
    
    return 0;
}