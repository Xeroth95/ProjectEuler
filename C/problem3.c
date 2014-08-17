#include <stdio.h>
#include <stdbool.h>
#include <math.h>


typedef unsigned long ulong;

bool is_prime(ulong n);
ulong largest_pfaktor(ulong n, ulong start);

int main(int argc, char *argv[])
{
	ulong answer = largest_pfaktor2(600851475143, 2);
	printf("The largest prime factor of %lu is: %lu\n",
	       600851475143, answer);

	return 0;
}

bool is_prime(ulong n)
{
	ulong limit = floor(sqrtl((long double) n));
	ulong iter;
	for (iter = 2; iter <= limit; ++iter)
	{
		// if n divides iter completly, then it is not prime
		if (n % iter == 0)
			return false;
	}
	return true;
}

ulong largest_pfaktor(ulong n, ulong start)
{
	if (is_prime(n)) return n;
	ulong iter;
	for (iter = start; iter < n; ++iter)
	{
		if (n % iter == 0 && is_prime(iter))
		{
			return largest_pfaktor(n/iter, iter);
		}
	}

	return 0;
}
