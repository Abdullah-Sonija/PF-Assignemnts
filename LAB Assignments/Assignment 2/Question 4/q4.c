#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 50

void sort_string(char *str) 
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) 
    {
        for (int j = i + 1; j < len; j++) 
        {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

typedef struct 
{
    char sorted[MAX_LENGTH];
    char *transactions[MAX_TRANSACTIONS];
    int count;
} AnagramGroup;

int find_or_create_group(AnagramGroup *groups, int *group_count, char *sorted) 
{
    for (int i = 0; i < *group_count; i++) 
    {
        if (strcmp(groups[i].sorted, sorted) == 0) 
        {
            return i;
        }
    }
    strcpy(groups[*group_count].sorted, sorted);
    groups[*group_count].count = 0;
    return (*group_count)++;
}

void group_transactions(char *transactions[], int n) 
{
    AnagramGroup groups[MAX_TRANSACTIONS];
    int group_count = 0;

    for (int i = 0; i < n; i++) 
    {
        char sorted[MAX_LENGTH];
        strcpy(sorted, transactions[i]);
        sort_string(sorted);

        int group_index = find_or_create_group(groups, &group_count, sorted);
        groups[group_index].transactions[groups[group_index].count++] = transactions[i];
    }

    for (int i = 0; i < group_count; i++) 
    {
        printf("[");
        for (int j = 0; j < groups[i].count; j++) 
        {
            printf("\"%s\"", groups[i].transactions[j]);
            if (j < groups[i].count - 1) printf(", ");
        }
        printf("]\n");
    }
}

int main() 
{
    char *transactions[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(transactions) / sizeof(transactions[0]);

    group_transactions(transactions, n);
    return 0;
}
