#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function to eliminate the same character
void compress1(const char* word,char* new_word,int* words_removed)
{
    int i,j=0;
    *words_removed=0;
    
    for(i=0;word[i]!='\0';i++)
    {
        if(i==0||word[i]!=word[i-1])
        {
            new_word[j++]=word[i];
        }
        else
        {
            (*words_removed)++;
        }
    }
    new_word[j]='\0';
}

//function to eliminate multiple words
void compress2(const char* words[],int n)
{
    char new_word[100];
    int total_removed=0;
    for(int i=0;i<n;i++)
    {
        int words_removed=0;
        compress1(words[i], new_word, &words_removed);
        total_removed+=words_removed;
        printf("\nOriginal: \"%s\".\nCorrected word: \"%s\".\nNo of Extra Characters Removed: %d\n", words[i], new_word, words_removed);
    }
    printf("\nTotal Characters Removed: %d\n", total_removed);
}

int main()
{
    int n, i;
    printf("How many words you want to enter: ");
    scanf("%d", &n);
    //Taking input
        char** words = (char**)malloc(n * sizeof(char*));
    for(i=0;i<n;i++)
    {
        words[i] = (char*)malloc(40 * sizeof(char));
        printf("Enter the word %d: ", i+1);
        scanf("%39s", words[i]);
    }
    compress2((const char**)words, n);
    for (i = 0; i < n; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}