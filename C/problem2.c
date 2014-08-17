#include <stdio.h>

typedef unsigned long ulong;

ulong evenfibsum(ulong limit);

int main(int argc, char *argv[])
{

	ulong answer = evenfibsum(4000000);

	printf("The sum of all even fibonacci numbers up to %lu is: %lu\n",
	       4000000UL, answer);

	return 0;
}

ulong evenfibsum(ulong limit)
{
	ulong sum = 0;
	ulong last =1, current = 1; //1 is definitly not even so we skip it

	while (current < limit)
	{
		ulong tmp = current;
		current += last;
		last = tmp;
		// faster way to check for evenness than current % 2 == 0
		if ((current & 1) == 0)
		{
			sum += current;
		}
	}

	return sum;
}
