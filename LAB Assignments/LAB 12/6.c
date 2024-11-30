#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct 
{
    char word[50];
    int count;
} WordFrequency;

void add_word(WordFrequency **word_array, int *size, int *count, const char *word);
void count_word_frequencies(const char *buffer, WordFrequency **word_array, int *size, int *count);

int main() 
{
    FILE *file = fopen("input.txt", "r");
    if (!file) 
    {
        printf("Error: Could not open file.\n");
        return 1;
    }
    char *buffer = (char *)malloc(100 * sizeof(char));
    int buffer_size = 100, length = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) 
    {
        if (length == buffer_size - 1) 
        {
            buffer_size *= 2;
            buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
        }
        buffer[length++] = ch;
    }
    buffer[length] = '\0';
    fclose(file);
    WordFrequency *word_array = (WordFrequency *)malloc(10 * sizeof(WordFrequency));
    int array_size = 10, word_count = 0;
    count_word_frequencies(buffer, &word_array, &array_size, &word_count);
    printf("Word Frequencies:\n");
    for (int i = 0; i < word_count; i++) 
    {
        printf("%s: %d\n", word_array[i].word, word_array[i].count);
    }
    free(buffer);
    free(word_array);
    return 0;
}
//functions
void add_word(WordFrequency **word_array, int *size, int *count, const char *word) 
{
    for (int i = 0; i < *count; i++) 
    {
        if (strcmp((*word_array)[i].word, word) == 0) 
        {
            (*word_array)[i].count++;
            return;
        }
    }
    if (*count == *size) 
    {
        *size *= 2;
        *word_array = (WordFrequency *)realloc(*word_array, *size * sizeof(WordFrequency));
    }
    strcpy((*word_array)[*count].word, word);
    (*word_array)[*count].count = 1;
    (*count)++;
}
void count_word_frequencies(const char *buffer, WordFrequency **word_array, int *size, int *count) 
{
    char word[50];
    int word_len = 0;

    for (int i = 0; buffer[i] != '\0'; i++) 
    {
        if (isalnum(buffer[i])) 
        {
            word[word_len++] = tolower(buffer[i]);
        } 
        else if (word_len > 0) 
        {
            word[word_len] = '\0';
            add_word(word_array, size, count, word);
            word_len = 0;
        }
    }
    if (word_len > 0) 
    {
        word[word_len] = '\0';
        add_word(word_array, size, count, word);
    }
}