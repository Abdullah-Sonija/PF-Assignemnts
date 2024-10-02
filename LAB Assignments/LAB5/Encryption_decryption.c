#include <stdio.h>
int main()
{
	int key;
	char c, e, d;
	printf("Enter the CHARACTER: ");
	scanf(" %c", &c);
	printf("Enter the KEY: ");
	scanf("%d", &key);
	e = c ^ key;
	d = e ^ key;
	printf("\nThe Encrypted message is %c", e);
	printf("\nThe Decrypted message is %c", d);
	return 0;
}