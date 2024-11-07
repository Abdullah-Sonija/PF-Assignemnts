#include <stdio.h>

int pick(int N) 
{
    int dp[N + 1];
    
    dp[0] = 0;
    
    for (int i = 1; i <= N; i++) 
    {
        dp[i] = 0;
        for (int pick = 1; pick <= 4 && i - pick >= 0; pick++) 
        {
            if (dp[i - pick] == 0) 
            {
                dp[i] = 1;
                break;
            }
        }
    }
    
    if (dp[N] == 0) 
    {
        return -1;
    }

    for (int pick = 1; pick <= 4; pick++) 
    {
        if (N - pick >= 0 && dp[N - pick] == 0) 
        {
            return pick;
        }
    }

    return -1;
}

int main() 
{
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int result = pick(N);
    if (result == -1) 
    {
        printf("It is impossible for A to win the game.\n");
    } else
    {
        printf("A should pick %d matchsticks on his first turn to guarantee a win.\n", result);
    }

    return 0;
}
