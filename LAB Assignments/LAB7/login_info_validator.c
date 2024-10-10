#include <stdio.h>
int main()
{
	char name[100], mail[100], num[20];

	printf("Enter the Username: ");
	getchar();
	scanf("%[A-Za-z ]", &name);

	printf("Enter the Email Address: ");
	getchar();
	scanf("%[A-Za-z@0-9._-]", &mail);

	printf("Enter the Phone number: ");
	getchar();
	scanf("%[0-9-+ ]", &num);

	printf("%s %s %d", name, mail, num);

	return 0;
}