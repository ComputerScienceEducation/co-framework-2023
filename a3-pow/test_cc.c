#include <stdio.h>

int my_pow(int base, int exp);

int main()
{
	if (my_pow(3, 2) == 9)
		printf("Result as expected.\n");
	else
		printf("Incorrect result.\n");

	return 0;
}
