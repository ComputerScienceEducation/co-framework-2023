#include <stdio.h>

int fibonacci(int n);

int main()
{
	if (fibonacci(11) == 55)
		printf("Result as expected.\n");
	else
		printf("Incorrect result.\n");

	return 0;
}
