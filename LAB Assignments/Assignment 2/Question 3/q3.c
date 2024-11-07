#include <stdio.h>
#include <string.h>

// Function to eliminate consecutive duplicate characters
void compress1(const char* word, char* new_word, int* words_removed) 
{
    int i, j = 0;
    *words_removed = 0;
    
    for (i = 0; word[i] != '\0'; i++) 
    {
        if (i == 0 || word[i] != word[i - 1]) 
        {
            new_word[j++] = word[i];
        } 
        else 
        {
            (*words_removed)++;
        }
    }
    new_word[j] = '\0';
}

// Function to eliminate duplicates in multiple words
void compress2(const char words[][40], int n) 
{
    char new_word[100];
    int total_removed = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int words_removed = 0;
        compress1(words[i], new_word, &words_removed);
        total_removed += words_removed;
        printf("\nOriginal: \"%s\".\nCorrected word: \"%s\".\nNo of Extra Characters Removed: %d\n", words[i], new_word, words_removed);
    }
    printf("\nTotal Characters Removed: %d\n", total_removed);
}

int main() 
{
    int n;
    printf("How many words do you want to enter? ");
    scanf("%d", &n);

    char words[n][40];
    
    // Taking input
    for (int i = 0; i < n; i++) 
    {
        printf("Enter word %d: ", i + 1);
        scanf("%39s", words[i]);
    }

    compress2(words, n);

    return 0;
}
