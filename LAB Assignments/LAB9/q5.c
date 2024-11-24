#include<stdio.h>
#include<string.h>

void reverse_sentence(char original[],char reveresed[]);

int main()
{
    char sentence[150];
    char reverse[150];
    //input
    printf("Write the Sentence: ");
    fgets(sentence,150,stdin);
    //remove trailing characters
    for(int i=0;sentence[i]!='\0';i++)
    {
        if(sentence[i]=='\n')
        {
            sentence[i]='\0';
            break;
        }
    }
    reverse_sentence(sentence,reverse);
    //output
    printf("Reversed String: %s", reverse);
    return 0;
}

void reverse_sentence(char original[],char reveresed[])
{
    int length=0;
    while(original[length]!=0)
    {
        length++;
    }
    for(int i=0;i<length;i++)
    {
        reveresed[i]=original[length-1-i];
    }    
    reveresed[length]='\0';
}