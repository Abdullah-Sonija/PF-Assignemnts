#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no of intial Matchstickes for the game: ");
    scanf("%d", &n);

    if(n%5==0)
    {
        printf("Player A can not win the game.\n");
        return -1;
    }
    int r=n%5;

    printf("Player A should have to pick %d matchstick in his first turn.\n", r);

    return 0;
}
