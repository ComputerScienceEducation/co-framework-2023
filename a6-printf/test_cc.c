#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int my_printf(char *s, ...);

int main()
{
	my_printf(
		"Hello from my_printf!\nFive is %u.\nSigned integers can be tricky. Here is negative ten: %d.\nThis is a string: %s\n",
		5, (int64_t)-10, "ABCDEF");

	return 0;
}
