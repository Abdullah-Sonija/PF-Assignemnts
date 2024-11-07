#include <stdio.h>

#define SIZE 5

void printGrid(char grid[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(char grid[SIZE][SIZE], int *playerRow, int *playerCol, char direction)
{
    int newRow = *playerRow;
    int newCol = *playerCol;

    if (direction == 'w') newRow--;
    if (direction == 's') newRow++;
    if (direction == 'a') newCol--;
    if (direction == 'd') newCol++;

    if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && grid[newRow][newCol] != 'X') 
    {
        if (grid[newRow][newCol] == 'I')
        {
            printf("You collected an item!\n");
        }
        grid[*playerRow][*playerCol] = ' ';
        *playerRow = newRow;
        *playerCol = newCol;
        grid[*playerRow][*playerCol] = 'P';
        return 1;
    }

    return 0;
}

int main() {
    char grid[SIZE][SIZE] = 
  {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow = 4, playerCol = 4;
    char direction;
    int gameOn = 1;

    while (gameOn) 
    {
        printGrid(grid);
        printf("\nEnter direction (w = up, s = down, a = left, d = right, q = quit): ");
        scanf(" %c", &direction);

        if (direction == 'q') 
        {
            gameOn = 0;
            printf("You quit the game.\n");
        } 
        else 
        {
            if (movePlayer(grid, &playerRow, &playerCol, direction)) 
            {
                printf("Moved successfully.\n");
            } 
            else 
            {
                printf("Can't move in that direction.\n");
            }
        }
    }

    return 0;
}
