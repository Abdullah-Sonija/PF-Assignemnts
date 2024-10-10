#include <stdio.h>

int main() {
    int t;
    int temp[7];
    int i;
    int sum = 0;
    int avg;

    // Input
    for(i = 0; i < 7; i++) {
        printf("Enter Today's Temperature: ");
        scanf("%d", &t);
        temp[i] = t;
    }

    // Calculate Average
    for(i = 0; i < 7; i++) {
        sum = sum + temp[i];
    }

    avg = sum / 7;
    printf("Average Temperature is: %d\n", avg);

    // Check for Extreme Temperatures
    for(i = 0; i < 7; i++) {
        if(temp[i] <= 10 || temp[i] >= 40) {
            printf("Extreme Temperature on day %d: %d°C\n", i + 1, temp[i]);
        }
    }

    return 0;
}
