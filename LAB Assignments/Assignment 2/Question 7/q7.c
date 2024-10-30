#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define rows 6
#define columns 5

//function to print the pattern

char random_character()
{
    return 'A' + (rand()%26);
}
void create_pattern(char pattern[rows][columns])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            pattern[i][j]=random_character();
            //My NU id is 24k-0013
            pattern[rows-1][0]=0;
            pattern[rows-1][1]=0;
            pattern[rows-1][2]=1;
            pattern[rows-1][3]=3;
        }
    }

}
void print_pattern(char pattern[rows][columns])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(i==rows-1)
            {
                if(j>3)
                {
                    printf(" %c ", pattern[i][j]);
                    break;
                }
                printf(" %d ", pattern[i][j]);
            }
            else
            {
                printf(" %c ", pattern[i][j]);
            }
        }
        printf("\n");
    }
}

//function to search
int search(char pattern[rows][columns], const char *word)
{
    int length=strlen(word);

    //search in row
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            int k;
            for(k=0;k<length;k++)
            {
                if(pattern[i][j+k]!=word[k])
                {
                    break;
                }
            }
            if(k==length)
            {
                return 1;
            }
        }
    }
    //search in column
    for(int j=0;j<columns;j++)
    {
        for(int i=0;i<=rows-length;i++)
        {
            int k;
            for(k=0;k<length;k++)
            {
                if(pattern[i+k][j]!=word[k])
                {
                    break;
                }
            }
            if (k==length)
            {
                return 1;
            }
        }
    }
    return 0;
}



int main()
{
    srand(time(NULL));
    char pattern[rows][columns];
    int score=0;
    while(1)
    {
    //printing the pattern
        create_pattern(pattern);
        print_pattern(pattern);
    //input
        char word[10];
        printf("\nEnter the word you found in this pattern (for exit enter END): ");
        scanf("%s", word);
    //exiting
        if(strcmp(word,"END")==0)
        {
            printf("Your final score = %d", score);
            break;
        }
    //searching
        if(search(pattern, word))
        {
            score++;
            printf("Good you find the word %s in the pattern.\nYour score = %d\n", word, score);
        }
        else
        {
            score--;
            printf("The word %s is not present in the pattern.\nYour score = %d\n", word, score);
        }
    }
    return 0;
}