#include <stdio.h>

int main()
{
	printf("%-32c|", 'a');
	printf("\n");
	printf("%-*c|", 7, 'b');
	printf("\n");
	printf("%c|", 'b');
	printf("\n");
	printf("%c|", 100);
	printf("\n");
	printf("%-*c|", 5, 't');
	printf("\n");
	printf("%*c|", 5, 't');
	printf("\n");
	printf("%*c|", -0, 't');
	printf("\n");
	printf("%c|", 100);
	printf("\n");
}