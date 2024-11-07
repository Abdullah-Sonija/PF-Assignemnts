#include <stdio.h>
#include <string.h>

#define max_transactions 100
#define max_length 50

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

int find_or_create_group(char sorted[][max_length], int counts[], int *group_count, char *sorted_str) 
{
    for (int i = 0; i < *group_count; i++) 
    {
        if (strcmp(sorted[i], sorted_str) == 0) 
        {
            return i;
        }
    }
    strcpy(sorted[*group_count], sorted_str);
    counts[*group_count] = 0;
    return (*group_count)++;
}

void group_transactions(char *transactions[], int n) 
{
    char sorted[max_transactions][max_length];
    int counts[max_transactions] = {0};
    char *grouped_transactions[max_transactions][max_transactions];
    int group_count = 0;

    for (int i = 0; i < n; i++) 
    {
        char sorted_str[max_length];
        strcpy(sorted_str, transactions[i]);
        sort_string(sorted_str);

        int group_index = find_or_create_group(sorted, counts, &group_count, sorted_str);
        grouped_transactions[group_index][counts[group_index]++] = transactions[i];
    }

    for (int i = 0; i < group_count; i++) 
    {
        printf("[");
        for (int j = 0; j < counts[i]; j++) 
        {
            printf("\"%s\"", grouped_transactions[i][j]);
            if (j < counts[i] - 1) printf(", ");
        }
        printf("]\n");
    }
}

int main() 
{
    int n;
    printf("enter the number of transactions: ");
    scanf("%d", &n);

    char transactions[max_transactions][max_length];
    char *transaction_ptrs[max_transactions];

    printf("enter each transaction:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("transaction %d: ", i + 1);
        scanf("%s", transactions[i]);
        transaction_ptrs[i] = transactions[i];
    }

    group_transactions(transaction_ptrs, n);
    return 0;
}
