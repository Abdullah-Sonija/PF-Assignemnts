#include <stdio.h>
#include <string.h>

#define MAX_CHAR 128  // Max number of ASCII characters

void analyze_character_frequency(char *slogans[], int num_slogans) 
{
    for (int i = 0; i < num_slogans; i++)
    {
        char *slogan = slogans[i];
        int frequency[MAX_CHAR] = {0};  // Initialize array to count characters

        
        for (int j = 0; j < strlen(slogan); j++)
        {
            frequency[(int)slogan[j]]++; 
        }

        printf("For \"%s\": {", slogan);
        int first = 1;  
        for (int k = 0; k < MAX_CHAR; k++) 
        {
            if (frequency[k] > 0) 
            {
                if (!first) printf(", ");
                printf("'%c': %d", k, frequency[k]);
                first = 0;
            }
        }
        printf("}\n");
    }
}

int main() {
    char *slogans[] = {"buy now", "save big", "limited offer"};
    int num_slogans = sizeof(slogans) / sizeof(slogans[0]);

    analyze_character_frequency(slogans, num_slogans);
    return 0;
}
