#include<stdio.h>
#include<string.h>

int input()
{
    int n;
    printf("Enter the number of words you want to check: ");
    scanf("%d", &n);
    return n;
}


int is_palindrone(char word[])
{
    int length=strlen(word);
    for(int i=0;i<length/2;i++)
    {
        if(word[i]!=word[length-i-1])
        {
            return 0;
        }
    }
    return 1;
}


void palindrone(int n)
{
    char array[n][20];
    for(int i=0;i<n;i++)
    {
        printf("Enter the words %d: ", i+1);
        scanf("%s",array[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(is_palindrone(array[i]))
        {
            printf("%s: Palindrome\n", array[i]);
        }
        else
        {
            printf("%s: Not Palindrome\n", array[i]);
        }
    }
}

int main()
{
    int n = input();
    palindrone(n);
    return 0;
}