#include <stdio.h>

unsigned long foobarsum(unsigned long limit);

int main(int argc, char *argv[])
{
	unsigned long answer = foobarsum(1000);

	printf("The sum of all multiples of 3 or 5 below %d is: %lu\n", 1000, answer);

	return 0;
}

// this function adds up all multiples of 3 or 5 up to limit
unsigned long foobarsum(unsigned long limit)
{
	unsigned long iter, sum = 0;

	for (iter = 0; iter < limit; ++iter)
	{
		if (iter % 3 == 0)
		{
			sum += iter;
		}
		else if (iter % 5 == 0) // do not count multiples of 15 twice !
		{
			sum += iter;
		}
	}

	return sum;
}
