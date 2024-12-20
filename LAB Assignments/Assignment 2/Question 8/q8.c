#include <stdio.h>
#include <string.h>
#include <math.h>

int Binary_Decimal(int number) 
{
    int decimal = 0, base = 1, rem;
    
    while (number > 0) 
    {
        rem = number % 10;
        decimal = decimal + rem * base;
        base = base * 2;
        number = number / 10;
    }
    
    return decimal;
}

int Decimal_Binary(int number) 
{
    int binary = 0, rem, place = 1;
    
    while (number > 0) 
    {
        rem = number % 2;
        binary += rem * place;
        place *= 10;
        number /= 2;
    }
    
    return binary;
}

void Decimal_Hexadecimal(int number) 
{
    if (number == 0)
    {
        printf("0\n");
        return;
    }
    
    char hex[100];
    int i = 0;
    
    while (number != 0) 
    {
        int temp = number % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
        } else {
            hex[i] = temp + 87;
        }
        i++;
        number = number / 16;
    }
    
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) 
    {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void Hexadecimal_Decimal(char hexNumber[]) 
{
    int length = strlen(hexNumber);
    int decimal = 0, base = 1;
    
    for (int i = length - 1; i >= 0; i--) 
    {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') 
        {
            decimal += (hexNumber[i] - 48) * base;
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') 
        {
            decimal += (hexNumber[i] - 87) * base;
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') 
        {
            decimal += (hexNumber[i] - 55) * base;
        }
        base = base * 16;
    }
    
    printf("Decimal: %d\n", decimal);
}

void Binary_Hexadecimal(int number) 
{
    int decimal = Binary_Decimal(number);
    Decimal_Hexadecimal(decimal);
}

void Hexadecimal_Binary(char hexNumber[]) 
{
    int decimal = 0;
    Hexadecimal_Decimal(hexNumber);

    for (int i = 0; hexNumber[i] != '\0'; i++) 
    {
        decimal = decimal * 16 + (hexNumber[i] >= '0' && hexNumber[i] <= '9' ? hexNumber[i] - '0' : (hexNumber[i] >= 'a' && hexNumber[i] <= 'f' ? hexNumber[i] - 'a' + 10 : hexNumber[i] - 'A' + 10));
    }

    printf("Binary: ");
    printf("%d\n", Decimal_Binary(decimal));
}

int main() {
    int choice, number;
    char hexNumber[100];
    
    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", Binary_Decimal(number));
                break;
            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", Decimal_Binary(number));
                break;
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &number);
                Decimal_Hexadecimal(number);
                break;
            case 4:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexNumber);
                Hexadecimal_Decimal(hexNumber);
                break;
            case 5:
                printf("Enter binary number: ");
                scanf("%d", &number);
                Binary_Hexadecimal(number);
                break;
            case 6:
                printf("Enter hexadecimal number: ");
                scanf("%s", hexNumber);
                Hexadecimal_Binary(hexNumber);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
