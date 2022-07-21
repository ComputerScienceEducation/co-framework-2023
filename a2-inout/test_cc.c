#include <stdio.h>

int my_increment(int n);

int main()
{
	if (my_increment(1) == 2)
		printf("Result as expected.\n");
	else
		printf("Incorrect result.\n");

	return 0;
}
