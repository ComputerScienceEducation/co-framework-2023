#include <stdio.h>

int factorial(int n);

int main()
{
	if (factorial(3) == 6)
		printf("Result as expected.\n");
	else
		printf("Incorrect result.\n");

	return 0;
}
