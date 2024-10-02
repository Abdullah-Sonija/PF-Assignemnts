#include <stdio.h>

void calculate_final_grade(float attendance, float assignments, float exam) 
{
    if (attendance >= 75 && attendance <= 100) {
        if (assignments >= 50 && assignments <= 100) {
            if (exam >= 50 && exam <= 100) {
                // Calculate final score
                float final_score = (attendance * 0.2) + (assignments * 0.4) + (exam * 0.4);
                
                // Determine letter grade based on final score
                if (final_score >= 90) {
                    printf("Final Grade: A (Score: %.2f)\n", final_score);
                } else if (final_score >= 80) {
                    printf("Final Grade: B (Score: %.2f)\n", final_score);
                } else if (final_score >= 70) {
                    printf("Final Grade: C (Score: %.2f)\n", final_score);
                } else if (final_score >= 60) {
                    printf("Final Grade: D (Score: %.2f)\n", final_score);
                } else {
                    printf("Final Grade: F (Score: %.2f)\n", final_score);
                }
            } else if (exam < 50) {
                printf("Failed due to low exam score (below 50%%).\n");
            } else {
                printf("Invalid Input for exam score. Must be between 0 and 100.\n");
            }
        } else if (assignments < 50) {
            printf("Failed due to low assignment score (below 50%%).\n");
        } else {
            printf("Invalid Input for assignment score. Must be between 0 and 100.\n");
        }
    } else if (attendance < 75) {
        printf("Failed due to low attendance (below 75%%).\n");
    } else {
        printf("Invalid Input for attendance. Must be between 0 and 100.\n");
    }
}

int main() {
    float attendance, assignments, exam;
    
    printf("Enter attendance percentage: ");
    scanf("%f", &attendance);
    
    printf("Enter average assignment score out of 100: ");
    scanf("%f", &assignments);
    
    printf("Enter exam score out of 100: ");
    scanf("%f", &exam);

    calculate_final_grade(attendance, assignments, exam);

    return 0;
}
