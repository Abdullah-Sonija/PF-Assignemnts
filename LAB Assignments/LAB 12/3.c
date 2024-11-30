#include<stdio.h>

int length(const char *string);
void reverse(char *string);
void concatenate(char *dest, const char *string);

int main()
{
    char s1[40],s2[40];
    printf("Enter the first string: ");
    fgets(s1,sizeof(s1),stdin);
    printf("Enter the second string: ");
    fgets(s2,sizeof(s2),stdin);
    //remove newline character if present
    if (s1[length(s1) - 1] == '\n')
        s1[length(s1) - 1] = '\0';
    if (s2[length(s2) - 1] == '\n')
        s2[length(s2) - 1] = '\0';
    printf("Length of the first string: %d\n", length(s1));
    printf("Length of the second string: %d\n", length(s2));
    reverse(s1);
    printf("Reversed first string: %s\n", s1);
    reverse(s2);
    printf("Reversed second string: %s\n", s2);
    concatenate(s1, s2);
    printf("Concatenated string: %s\n", s1);
    return 0;
}

int length(const char *string)
{
    int length = 0;
    while (*string != '\0') 
    {
        length++;
        string++;
    }
    return length;
}
void reverse(char *string)
{
    char *start = string;
    char *end = string;
    char temp;
    while (*end != '\0') 
    {
        end++;
    }
    end--; 
    while (start < end) 
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
void concatenate(char *dest, const char *string)
{
    while (*dest != '\0') 
    {
        dest++;
    }
    while (*string != '\0') 
    {
        *dest = *string;
        dest++;
        string++;
    }
    *dest = '\0';
}